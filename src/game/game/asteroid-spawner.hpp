Game::asteroidSpawner() {
    // Spawns the asteroid if not present.
    srand(time(0));

    int randx;
    int randy;
    int powerUp;

    if(asteroids[0] == -1 && asteroids[1] == -1) {
      randx = rand() % 79;
      randy = rand() % 22;

      asteroids[0] = randy;
      asteroids[1] = randx;
      powerUp = rand() % 3 + 1;

      if(powerUp == 2 && mobSpeed == 1) {
        asteroids[2] = 3;
      }
    }

    return *this;
  }
