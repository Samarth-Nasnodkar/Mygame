Game Game::asteroidSpawner() {
    // Spawns the asteroid if not present.
    srand(time(0));

    int randx;
    int randy;
    int powerUp;

    if(asteroids[0] == -1 && asteroids[1] == -1) {
      randx = rand() % (dimensions[1] - 1);
      randy = rand() % (dimensions[0] - 1);

      asteroids[0] = randy;
      asteroids[1] = randx;
      powerUp = rand() % 3 + 1;

      if(powerUp == 2) {
        asteroids[2] = 3;
      }
    }

    return *this;
  }
