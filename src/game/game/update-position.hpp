Game::updatePosition(char input) {
  switch(input) {
    // Normal movements.

    case 'w':
      a[0] -= 1;
      direction = "f";
      break;
    case 's':
      a[0] += 1;
      direction = "b";
      break;
    case 'd':
      a[1] += 1;
      direction = "r";
      break;
    case 'a':
      a[1] -= 1;
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
