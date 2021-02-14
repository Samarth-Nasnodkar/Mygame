#include<bits/stdc++.h>
using namespace std;

class KillerPiller{
    // 0 -> y , 1 -> x
    public:
        int coords[2] = {10 , 20};
        int userCoords[2] = {9 , 5};
        KillerPiller(){
        }
        // void takeValues(int ux , int uy , int mx , int my){
        //     coords[0] = my;
        //     coords[1] = mx;
        //     userCoords[0] = uy;
        //     userCoords[1] = ux;
        // }
        void pathfinder(){
            if(userCoords[0] > coords[0] && userCoords[1] > coords[1]){
                // Q 4
                int yDiff , xDiff;
                yDiff = userCoords[0] - coords[0];
                xDiff = userCoords[1] - coords[1];
                coords[0] += 1;
                coords[1] += 1;
            }
            else if(userCoords[0] > coords[0] && userCoords[1] < coords[1]){
                // Q 3
                int yDiff , xDiff;
                yDiff = userCoords[0] - coords[0];
                xDiff = coords[1] - userCoords[1];
                coords[0] += 1;
                coords[1] -= 1;
            }
            else if(userCoords[0] < coords[0] && userCoords[1] > coords[1]){
                // Q 1
                int yDiff , xDiff;
                yDiff = coords[0] - userCoords[0];
                xDiff = userCoords[1] - coords[1];
                coords[0] -= 1;
                coords[1] += 1;
            }
            else if(userCoords[0] < coords[0] && userCoords[1] < coords[1]){
                // Q 2
                int yDiff , xDiff;
                yDiff = coords[0] - userCoords[0];
                xDiff = coords[1] - userCoords[1];
                coords[0] -= 1;
                coords[1] -= 1;
            }
            else if(userCoords[0] == coords[0]){
                if(userCoords[1] > coords[1]){
                    coords[1] += 1;
                }
                else{
                    coords[1] -= 1;
                }
            }
            else if(userCoords[1] == coords[1]){
                if(userCoords[0] > coords[0]){
                    coords[0] += 1;
                }
                else{
                    coords[0] -= 1;
                }
            }
        }
};