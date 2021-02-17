#include<bits/stdc++.h>
using namespace std;

class equation{
	public:
//		ax + by + c = 0
		int a , b;
		equation(int xcoeff, int ycoeff , int constant){
			a = xcoeff;
			b = ycoeff;
			c = constant;
		}
		bool satisfy(int xval , yval){
			if(a*xval + b*yval + c == 0){
				return true;
			}
			
			return false;
		}
};

