Game Game::updatePosition(char input) {
  switch(input) {
    // Normal movements.

    case 'w':
      if(!paused){
        playerCoords[0] -= playerSpeed * gameTickDelta;
        direction = "f";
      }
      break;
    case 's':
      if(!paused){
        playerCoords[0] += playerSpeed * gameTickDelta;
        direction = "b";
      }
      break;
    case 'd':
      if(!paused){
        playerCoords[1] += playerSpeed * gameTickDelta;
        direction = "r";
      }
      break;
    case 'a':
      if(!paused){
        playerCoords[1] -= playerSpeed * gameTickDelta;
        direction = "l";
      }
      break;
    case 'o':
      if(!paused) showScore = true;
      break;
    case 'e':
      if(gunEnable && !paused) fired = true;
      break;
    case 'p':
      paused = !paused;
      pausePlay();
      break;
    default:
      break;
  }

  return *this;
}
