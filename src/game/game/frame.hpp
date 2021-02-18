Game Game::frame() {
  updatePosition(getKeyPress());
  system("clear");

  bool shotUsed = false;

  playerCoords[0] = fmin(dimensions[0] - 2, fmax(1, playerCoords[0])); // Bounded
  playerCoords[1] = fmin(dimensions[1] - 2, fmax(1, playerCoords[1])); // Bounded

  mobCoords[0] = fmin(dimensions[0] - 2, fmax(1, mobCoords[0])); // Bounded
  mobCoords[1] = fmin(dimensions[1] - 2, fmax(1, mobCoords[1])); // Bounded

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
    for(int i = 0; i < dimensions[0]; i++) {
      for(int j = 0; j < dimensions[1]; j++) {
        if(i == floor(playerCoords[0]) && j == floor(playerCoords[1])) {
          // Printing the user character.

          if(direction == 'f') cout << ORANGE_NO_FLASH << "^" << NC;
          else if(direction == 'b') cout << ORANGE_NO_FLASH << "v" << NC;
          else if(direction == 'l') cout << ORANGE_NO_FLASH << "<" << NC;
          else if(direction == 'r') cout << ORANGE_NO_FLASH << ">" << NC;
        }
        else if(
          i == asteroids[0] &&
          j == asteroids[1]
        ) {
          // Printing the asteroid.

          if(asteroids[2] == 0) cout << GREEN_NO_UNDER << "#" <<NC;
          else cout << GREEN_NO_UNDER << "@" << NC;
        }
        else if(i == floor(mobCoords[0]) && j == floor(mobCoords[1])) cout << "*";
        else if(
          blaster.shootable(
            j,
            i,
            floor(playerCoords[1]),
            floor(playerCoords[0]),
            floor(mobCoords[1]),
            floor(mobCoords[0]),
            asteroids[1],
            asteroids[0],
            direction
          ) &&
          boostCounter > 0 &&
          fired
        ) {
          //The shooting animation.
          cout << RED_NO_UNDER << "+";
          shotUsed = true;

        }
        else {
          if (i == 0 || i == dimensions[0] - 1 || j == 0 || j == dimensions[1] - 1) cout << BG_WHITE << " " << NC;
          else cout << " ";

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

    // HUD
    cout << "Score: " << ORANGE_UNDER << score << NC << endl;
    cout << "Boost Level: [";
    for (int i = 0; i < boostCounter; i++) cout << GREEN_NO_UNDER << "#" << NC;
    for (int i = 0; i < 10 - boostCounter; i++) cout << " ";
    cout << "]" << endl;
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
