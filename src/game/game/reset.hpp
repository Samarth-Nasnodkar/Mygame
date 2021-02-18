Game::reset() {
  KillerPiller::reset();

  a[0] = defaultA[0];
  a[1] = defaultA[1];

  asteroids[0] = defaultAsteroids[0];
  asteroids[1] = defaultAsteroids[1];
  asteroids[2] = defaultAsteroids[2];

  return *this;
}
