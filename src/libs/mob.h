#include<bits/stdc++.h>
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

class KillerPiller{
    // 0th element represents the y coordinate of the mob/user and 1st element is the x coordinate
    public:
        // coords represents the coordinates of the mob.
        int coords[2] = {10 , 20};
        int userCoords[2] = {9 , 5};
        // userCoords represents the coordinates of the user.
        KillerPiller(){
        }

        void pathfinder(){
            if(userCoords[0] > coords[0] && userCoords[1] > coords[1]){
                // User is 4th Quadrant taking mob at origin.
                int yDiff , xDiff;
                yDiff = userCoords[0] - coords[0];
                xDiff = userCoords[1] - coords[1];
                coords[0] += 1;
                coords[1] += 1;
            }
            else if(userCoords[0] > coords[0] && userCoords[1] < coords[1]){
                // User is 3rd Quadrant taking mob at origin.
                int yDiff , xDiff;
                yDiff = userCoords[0] - coords[0];
                xDiff = coords[1] - userCoords[1];
                coords[0] += 1;
                coords[1] -= 1;
            }
            else if(userCoords[0] < coords[0] && userCoords[1] > coords[1]){
                // User is 1st Quadrant taking mob at origin.
                int yDiff , xDiff;
                yDiff = coords[0] - userCoords[0];
                xDiff = userCoords[1] - coords[1];
                coords[0] -= 1;
                coords[1] += 1;
            }
            else if(userCoords[0] < coords[0] && userCoords[1] < coords[1]){
                // User is 2nd Quadrant taking mob at origin.
                int yDiff , xDiff;
                yDiff = coords[0] - userCoords[0];
                xDiff = coords[1] - userCoords[1];
                coords[0] -= 1;
                coords[1] -= 1;
            }
            else if(userCoords[0] == coords[0]){
                // User lies at the same y value i.e., on a line perpendicular to the y axis
                if(userCoords[1] > coords[1]){
                    coords[1] += 1;
                }
                else{
                    coords[1] -= 1;
                }
            }
            else if(userCoords[1] == coords[1]){
                // User lies at the same x value i.e., on a line perpendicular to the x axis
                if(userCoords[0] > coords[0]){
                    coords[0] += 1;
                }
                else{
                    coords[0] -= 1;
                }
            }
        }
};