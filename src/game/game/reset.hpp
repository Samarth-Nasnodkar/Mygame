Game Game::reset() {
  KillerPiller::reset();

  playerCoords[0] = defaultplayerCoords[0];
  playerCoords[1] = defaultplayerCoords[1];

  asteroids[0] = defaultAsteroids[0];
  asteroids[1] = defaultAsteroids[1];
  asteroids[2] = defaultAsteroids[2];

  gameRunning = false;

  return *this;
}
