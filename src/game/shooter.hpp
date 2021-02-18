#include <bits/stdc++.h>
#include <string>
using namespace std;

class Gun {
  public:
    /**
    * Tells if at that specific point, the gun shot animation should be showed or not.
    */
    bool shootable(
      int currentx,
      int currenty,
      int userx,
      int usery,
      int enemyx,
      int enemyy,
      string direction
    ) {
      // This function tells if at that specific point, the gun shot animation should be showed or not.

      if(direction == "f") {
        // Check the graph in the mob.h file for more intuitive feeling.

        if(enemyy > usery) {
          if(currenty < usery && currentx == userx) return true;
          else return false;
        }
        else{
          if(currenty < usery && currenty > enemyy && currentx == userx) return true;
          else return false;
        }
      }
      else if(direction == "b") {
        if(enemyy < usery) {
          if(currenty > usery && currentx == userx) return true;
          else return false;
        }
        else {
          if(currenty > usery && currenty < enemyy && currentx == userx) return true;
          else return false;
        }
      }
      else if(direction == "l") {
        if(enemyx > userx) {
          if(currentx < userx && currenty == usery) return true;
          else return false;
        }
        else{
          if(currentx < userx && currentx > enemyx && currenty == usery) return true;
          else return false;
        }
      }
      else if(direction == "r") {
        if(enemyx < userx) {
          if(currentx > userx && currenty == usery) return true;
          else return false;
        }
        else{
          if(currentx > userx && currentx < enemyx && currenty == usery) return true;
          else return false;
        }
      }
    }
};
