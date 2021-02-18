Game Game::updatePosition(char input) {
  switch(input) {
    // Normal movements.

    case 'w':
      playerCoords[0] -= playerSpeed * gameTickDelta;
      direction = "f";
      break;
    case 's':
      playerCoords[0] += playerSpeed * gameTickDelta;
      direction = "b";
      break;
    case 'd':
      playerCoords[1] += playerSpeed * gameTickDelta;
      direction = "r";
      break;
    case 'a':
      playerCoords[1] -= playerSpeed * gameTickDelta;
      direction = "l";
      break;
    case 'o':
      showScore = true;
      break;
    case 'e':
      if(gunEnable) fired = true;
      break;
    default:
      break;
  }

  return *this;
}
