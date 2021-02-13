#include<bits/stdc++.h>
#include"conio.h"
#include<string>
#include<chrono>
#include<thread>
using namespace std;

class Game{
    public:
    string direction = "f";
    bool showScore = false;
    int score = 0;
    int asteroids[2] = {-1 , -1};
    Game(){
        generateMap();
    }
    int a[2] = {9 , 5};
    void generateMap(){
        while(true){
            if(a[0] > 22)
            a[0] = 0;
            else if(a[1] > 79)
            a[1] = 0;
            else if(a[0] < 0)
            a[0] = 22;
            else if(a[1] < 0)
            a[1] = 78;
            if(a[0] == asteroids[0] && a[1] == asteroids[1]){
                asteroids[0] = -1;
                asteroids[1] = -1;
                score += 1;
            }
            if(!showScore){
                asteroidSpawner();
                for(int i=0;i<23;i++){
                    for(int j=0;j<80;j++){
                        if(i == a[0] && j == a[1]){
                            if(direction == "f")
                            cout<<"^";
                            else if(direction == "b")
                            cout<<"v";
                            else if(direction == "l")
                            cout<<"<";
                            else if(direction == "r")
                            cout<<">";
                        }
                        else if(i == asteroids[0] && j == asteroids[1]){
                            cout<<"#";
                        }
                        else{
                            cout<<" ";
                        }
                    }
                    cout<<"\n";
                }
            }
            else{
                for(int i=0;i<40;i++){
                    for(int j=0;j<40;j++){
                        if(i == 19 && j == 17){
                            cout<<"\033[1;33m"<<"Your"<<"\033[0m";
                            j += 3;
                        }
                        else if(i == 20 && j == 16){
                            cout<<"\033[1;33m"<<"Score:"<<"\033[0m";
                            j += 5;
                        }
                        else if(i == 21 && j == 17){
                            int temp = score;
                            int digits = 0;
                            while(temp > 0){
                                digits += 1;
                                temp = temp/10;
                            }
                            cout<<"\033[0;32m"<<score<<"\033[0m";
                            j += digits - 1;
                        }
                        else{
                            cout<<" ";
                        }
                    }
                    cout<<"\n";
                }
                showScore = false;
            }
            std::this_thread::sleep_for(std::chrono::milliseconds(16));
            updatePosition(getKeyPress());
            system("clear");
        }
    }
    char getKeyPress(){
        char a;
        a = getch();
        return a;
    }
    void asteroidSpawner(){
        srand(time(0));
        int randx = a[1];
        int randy = a[0];
        if(asteroids[0] == -1 and asteroids[1] == -1){
            while(randx == a[1])
            randx = rand()%79;
            while(randy == a[0])
            randy = rand()%22;

            asteroids[0] = randy;
            asteroids[1] = randx;
        }
    }
    void updatePosition(char input){
        switch(input){
            case 'w':
                a[0] -= 1;
                direction = "f";
                break;
            case 's':
                a[0] += 1;
                direction = "b";
                break;
            case 'd':
                a[1] += 1;
                direction = "r";
                break;
            case 'a':
                a[1] -= 1;
                direction = "l";
                break;
            case 'o':
                showScore = true;
                break;
            default:
                break;
        }
    }
};

int main(){
    Game g;
    return 0;
}