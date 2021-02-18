Game Game::frame() {
  updatePosition(getKeyPress());
  system("clear");

  bool shotUsed = false;

  playerCoords[0] = fmin(22, fmax(0, playerCoords[0])); // Bounded
  playerCoords[1] = fmin(78, fmax(0, playerCoords[1])); // Bounded

  if(
    floor(playerCoords[0]) == asteroids[0] &&
    floor(playerCoords[1]) == asteroids[1]
  ) {
    asteroids[0] = -1;// the -1 signifies that the asteroid should be despawned.
    asteroids[1] = -1;

    if(asteroids[2] == 3) { // Checking if the asteroid was a powerup asteroid.
      asteroids[2] = 3;
      boostCounter = 10;
      gunEnable = true;
    }
    score++;
  }
  else if(
    (playerCoords[0] <= mobCoords[0] + 1 && playerCoords[0] >= mobCoords[0] - 1) &&
    (playerCoords[1] <= mobCoords[1] + 1 && playerCoords[1] >= mobCoords[1] - 1)
  ) {
    // User lost.
    this->lostScreen();
    score = 0;
  }
  if(!showScore) {
    this->asteroidSpawner(); // Spawns asteroid if not present in the map.

    // Draw frame
    for(int i = 0; i < 23; i++) {
      for(int j = 0; j < 80; j++) {
        if(i == floor(playerCoords[0]) && j == floor(playerCoords[1])) {
          // Printing the user character.

          if(direction == "f") cout << ORANGE_NO_FLASH << "^" << NC;
          else if(direction == "b") cout << ORANGE_NO_FLASH << "v" << NC;
          else if(direction == "l") cout << ORANGE_NO_FLASH << "<" << NC;
          else if(direction == "r") cout << ORANGE_NO_FLASH << ">" << NC;
        }
        else if(
          i == asteroids[0] &&
          j == asteroids[1]
        ) {
          // Printing the asteroid.

          if(asteroids[2] == 0) cout << RED_NO_FLASH << "#" <<NC;
          else cout << RED_NO_FLASH << "@" << NC;
        }
        else if(i == floor(mobCoords[0]) && j == floor(mobCoords[1])) cout << "*";
        else if(
          blaster.shootable(
            j,
            i,
            playerCoords[1],
            playerCoords[0],
            mobCoords[1],
            mobCoords[0],
            direction
          ) &&
          boostCounter > 0 &&
          fired
        ) {
          //The shooting animation.
          cout << "+";
          shotUsed = true;

        }
        else {
          cout << " ";

          // // Printing the stars alternately.

          // if(starPrint == 0) {
          //   cout << GREEN_NO_FLASH << "." << NC;
          //   starPrint = 1;
          // }
          // else if(starPrint < 5) {
          //   cout << " ";
          //   starPrint += 1;
          // }
          // else {
          //   cout << " ";
          //   starPrint = 0;
          // }
        }
      }
      cout << "\n";
    }
  }
  else {
    // To display the score.
    for(int i = 0; i < 40; i++) {
      for(int j = 0; j < 40; j++) {
        if(i == 19 && j == 17) {
          cout << "\033[1;33m" << "Your" << "\033[0m";
          j += 3;// Not needed but just felt like keeping the boundaries still.
        }
        else if(i == 20 && j == 16) {
          cout<<"\033[1;33m"<<"Score:"<<"\033[0m";
          j += 5;
        }
        else if(i == 21 && j == 17) {
          int temp = score;
          int digits = 0;
          while(temp > 0) {
            digits += 1;
            temp = temp/10;
          }
          cout << "\033[0;32m" << score << "\033[0m";
          j += digits - 1;
        }
        else cout<<" ";
      }
      cout<<"\n";
    }
    showScore = false;
  }

  if(alternate == 0) {
    mobPathFind(gameTickDelta);// This algo will find the path for the mob and also move it.
    alternate = 1;
  }
  else if(alternate < mobSpeed + fps/30) alternate += 1;
  else {
    alternate = 0;

    if(shotUsed) {
      // Since one shot has been used
      boostCounter -= 1;
      shotUsed = false;
      fired = false;
    }
    if(boostCounter <= 0) {
      // The user has used all of their shots.
      gunEnable = false;
      boostCounter = 0;
    }
  }

  return *this;
}
