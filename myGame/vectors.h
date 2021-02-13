#include<bits/stdc++.h>
#include<math.h>
using namespace std;

class Vector{
    public:
    Vector(){}
    int startx , starty , endx , endy;
    int direction(){
        // 0 -> up , 1 -> down , 2 -> left , 3 -> right
        bool vertical = false , horizontal = false;
        if(startx == endx){
            vertical = true;
        }
        else if(starty == endy){
            horizontal = true;
        }

        if(vertical){
            if(starty > endy){
                return 0;
            }
            else{
                return 1;
            }
        }
        else if(horizontal){
            if(startx > endx){
                return 2;
            }
            else{
                return 3;
            }
        }

    }
    float magnitude(){
        float mag = 0;
        mag = sqrt(pow((startx - endx),2) + pow((starty - endy),2));
        return mag;
    }
    int* position(){
        int a[2];
        a[0] = startx;
        a[1] = starty;
        return a;
    }
};