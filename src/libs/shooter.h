#include<bits/stdc++.h>
#include<string>
using namespace std;

class Gun{
	public:
		Gun(){
		}
		bool shootable(int currentx , int currenty , int userx , int usery , int enemyx , int enemyy, string direction){
			if(direction == "f"){
				if(enemyy > usery){
					if(currenty < usery){
						return true;
					}
					
					return false;
				}
				else{
					if(currenty < usery && currenty > enemyy){
						return true;
					}
					return false;
				}
			}
			else if(direction == "b"){
				if(enemyy < usery){
					if(currenty > usery){
						return true;
					}
					
					return false;
				}
				else{
					if(currenty > usery && currenty < enemyy){
						return true;
					}
					return false;
				}
			}
			else if(direction == "l"){
				if(enemyx > userx){
					if(currentx < userx){
						return true;
					}
					
					return false;
				}
				else{
					if(currentx < userx && currentx > enemyx){
						return true;
					}
					return false;
				}
			}
			else if(direction == "r"){
				if(enemyx < userx){
					if(currentx > userx){
						return true;
					}
					
					return false;
				}
				else{
					if(currentx > userx && currentx < enemyx){
						return true;
					}
					return false;
				}
			}
		}
};
