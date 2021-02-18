#include <bits/stdc++.h>
using namespace std;

/*
This is a visual representation of the imaginary graph plotted by the mob
  (0,0)           x coordinate increases from Left to Right while y coordinate increases from top to bottom
    _______________________________________>
   |
   |
   |
   |
   |
   |
   |
   |
   |
   |
   V

*/

const float defaultCoords[2] = {10, 20};
const float defaultplayerCoords[2] = {9, 5};
const float defaultPlayerSpeed = 5; // in units per tick
const float defaultMobSpeed = 3.5;

// Returns the mathematical sign of the number
int sgn(float number) {
  if (number == 0) return 0;
  else if (number > 0) return 1;
  else return -1;
}

class KillerPiller {
  // 0th element represents the y coordinate of the mob/user and 1st element is the x coordinate
  protected:
    float mobCoords[2] = {defaultCoords[0], defaultCoords[1]};
    float playerCoords[2] = {defaultplayerCoords[0], defaultplayerCoords[1]};
    float mobSpeed = defaultMobSpeed;
    float playerSpeed = defaultPlayerSpeed;

    KillerPiller mobPathFind(float tick) {
      // Move towards the difference between the player and mob
      mobCoords[0] += sgn(floor(playerCoords[0]) - floor(mobCoords[0])) * mobSpeed * tick;
      mobCoords[1] += sgn(floor(playerCoords[1]) - floor(mobCoords[1])) * mobSpeed * tick;

      return *this;
    }

    KillerPiller reset() {
      mobCoords[0] = defaultCoords[0];
      mobCoords[1] = defaultCoords[1];

      playerCoords[0] = defaultplayerCoords[0];
      playerCoords[1] = defaultplayerCoords[1];

      return *this;
    }
};
