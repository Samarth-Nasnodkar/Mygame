#include <bits/stdc++.h>
#include <string>
using namespace std;

class Gun {
  public:
  bool killed = false;
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
      char direction,
      bool fired = false
    ) {
      // This function tells if at that specific point, the gun shot animation should be showed or not.
      // Asteroids and mobs block laser
      killed = false;
      switch(direction) {
        case 'b':
          if (mobY > playerY && playerX == mobX) killed = true && fired;
          return (x == playerX) && (y > playerY) && !(mobX == playerX && y >= mobY) && !(asteroidX == playerX && y >= asteroidY);
        case 'f':
          if (mobY < playerY && playerX == mobX) killed = true && fired;
          return (x == playerX) && (y < playerY) && !(mobX == playerX && y <= mobY) && !(asteroidX == playerX && y <= asteroidY);
        case 'l':
          if (mobX < playerX && playerY == mobY) killed = true && fired;
          return (y == playerY) && (x < playerX) && !(mobY == playerY && x <= mobX) && !(asteroidY == playerY && x <= asteroidX);
        default:
          if (mobX > playerX && playerY == mobY) killed = true && fired;
          return (y == playerY) && (x > playerX) && !(mobY == playerY && x >= mobX) && !(asteroidY == playerY && x >= asteroidX);
      }

      return false;
    }
};
