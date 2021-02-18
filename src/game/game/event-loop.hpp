Game Game::eventLoop() {
  while (gameRunning) {
    timeval currentTime;
    gettimeofday(&currentTime, NULL);

    double milliDiff = (currentTime.tv_sec - lastFrameEndTime.tv_sec) * 1000.0 + (currentTime.tv_usec - lastFrameEndTime.tv_usec) / 1000.0;

    if (milliDiff > 1000 / fps) {
      gameTick = milliDiff * tps / 1000;

      this->frame();
      gettimeofday(&lastFrameEndTime, NULL);
    }
    else {
      usleep(1000000 / fps - milliDiff * 1000);
    }
  }

  return *this;
}
