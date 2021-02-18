#include <bits/stdc++.h>
#include <string>
using namespace std;

class Gun {
  public:
    /**
    * Tells if at that specific point, the gun shot animation should be showed or not.
    */
    bool shootable(
      int x,
      int y,
      int playerX,
      int playerY,
      int mobX,
      int mobY,
      int asteroidX,
      int asteroidY,
      char direction
    ) {
      // This function tells if at that specific point, the gun shot animation should be showed or not.
      // Asteroids and mobs block laser

      switch(direction) {
        case 'b':
          return (x == playerX) && (y > playerY) && !(mobX == playerX && y >= mobY) && !(asteroidX == playerX && y >= asteroidY);
        case 'f':
          return (x == playerX) && (y < playerY) && !(mobX == playerX && y <= mobY) && !(asteroidX == playerX && y <= asteroidY);
        case 'l':
          return (y == playerY) && (x < playerX) && !(mobY == playerY && x <= mobX) && !(asteroidY == playerY && x <= asteroidX);
        default:
          return (y == playerY) && (x > playerX) && !(mobY == playerY && x >= mobX) && !(asteroidY == playerY && x >= asteroidX);
      }

      return false;
    }
};
