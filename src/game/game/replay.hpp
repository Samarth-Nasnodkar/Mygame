Game Game::replay(){
  replay_ongoing = true;
  Node *t = head;
  while(t != NULL){
    playerCoords[0] = t->playery;
    playerCoords[1] = t->playerx;
    mobCoords[0] = t->moby;
    mobCoords[1] = t->mobx;
    direction = t->direction;
    timeval currentTime;
    gettimeofday(&currentTime, NULL);

    double milliDiff = (currentTime.tv_sec - lastFrameEndTime.tv_sec) * 1000.0 + (currentTime.tv_usec - lastFrameEndTime.tv_usec) / 1000.0;

    if (milliDiff > 1000 / fps) {
      gameTickDelta = milliDiff * tps / 1000;

      this->frame();
      gettimeofday(&lastFrameEndTime, NULL);
    }
    else {
      usleep(1000000 / fps - milliDiff * 1000);
    }
    t = t->next;
  }
  replay_ongoing = false;
  this->reset();
  return *this;
}