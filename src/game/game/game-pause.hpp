Game Game::pausePlay(){
  while(paused){
    updatePosition(getKeyPress());
  }
  return *this;
}