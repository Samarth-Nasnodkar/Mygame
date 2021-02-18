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

class KillerPiller {
  // 0th element represents the y coordinate of the mob/user and 1st element is the x coordinate
  protected:
    // coords represents the coordinates of the mob.
    float mobCoords[2] = {defaultCoords[0], defaultCoords[1]};
    float playerCoords[2] = {defaultplayerCoords[0], defaultplayerCoords[1]};
    float mobSpeed = defaultMobSpeed;
    float playerSpeed = defaultPlayerSpeed;
    // userCoords represents the coordinates of the user.

    KillerPiller mobPathFind(float tick) {
      if(
        playerCoords[0] > mobCoords[0] &&
        playerCoords[1] > mobCoords[1]
      ) {
        // User is 4th Quadrant taking mob at origin.
        int yDiff, xDiff;

        yDiff = playerCoords[0] - mobCoords[0];
        xDiff = playerCoords[1] - mobCoords[1];

        mobCoords[0] += mobSpeed * tick;
        mobCoords[1] += mobSpeed * tick;
      }
      else if(
        playerCoords[0] > mobCoords[0] &&
        playerCoords[1] < mobCoords[1]
      ) {
        // User is 3rd Quadrant taking mob at origin.
        int yDiff, xDiff;

        yDiff = playerCoords[0] - mobCoords[0];
        xDiff = mobCoords[1] - playerCoords[1];

        mobCoords[0] += mobSpeed * tick;
        mobCoords[1] -= mobSpeed * tick;
      }
      else if(
        playerCoords[0] < mobCoords[0] &&
        playerCoords[1] > mobCoords[1]
      ) {
        // User is 1st Quadrant taking mob at origin.
        int yDiff , xDiff;

        yDiff = mobCoords[0] - playerCoords[0];
        xDiff = playerCoords[1] - mobCoords[1];

        mobCoords[0] -= mobSpeed * tick;
        mobCoords[1] += mobSpeed * tick;
      }
      else if(
        playerCoords[0] < mobCoords[0] &&
        playerCoords[1] < mobCoords[1]
      ) {
        // User is 2nd Quadrant taking mob at origin.
        int yDiff, xDiff;

        yDiff = mobCoords[0] - playerCoords[0];
        xDiff = mobCoords[1] - playerCoords[1];

        mobCoords[0] -= mobSpeed * tick;
        mobCoords[1] -= mobSpeed * tick;
      }
      else if(playerCoords[0] == mobCoords[0]) {
        // User lies at the same y value i.e., on a line perpendicular to the y axis
        if(playerCoords[1] > mobCoords[1]) mobCoords[1] += mobSpeed * tick;
        else mobCoords[1] -= mobSpeed * tick;
      }
      else if(playerCoords[1] == mobCoords[1]) {
        // User lies at the same x value i.e., on a line perpendicular to the x axis
        if(playerCoords[0] > mobCoords[0]) mobCoords[0] += mobSpeed * tick;
        else mobCoords[0] -= mobSpeed * tick;
      }


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
