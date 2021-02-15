#include<bits/stdc++.h>
#include"libs/conio.h"
#include<string>
#include<chrono>
#include<thread>
#include"libs/mob.h"
using namespace std;

class Game : public KillerPiller{
    public:
    Game(int speed){
        mobSpeed = speed;
        generateMap();
        while(restart){
            a[0] = 9;
            a[1] = 5;
            asteroids[0] = -1;
            asteroids[1] = -1;
            asteroids[2] = 0;
            generateMap();
        }
    }
    int mobSpeed;
    int a[2] = {9 , 5};
    string direction = "f";
    bool showScore = false;
    int score = 0;
    int alternate = 0;
    int asteroids[3] = {-1 , -1 , 0};
    int boostCounter = 0;
    int boostSpeed = 0;
    int realSpeed;
    int starPrint = 0;
    bool restart = false;
    void lostScreen(){
        string input;
        char ORANGE_NO_FLASH[] = "\033[1;33m";
        char RED_NO_FLASH[] = "\033[1;31m";
        char NC[] = "\033[0m";
        char GREEN_NO_FLASH[] = "\033[0;32m";
        system("clear");
        cout<<"You Lost.\nYour Score : \n"<<ORANGE_NO_FLASH<<score<<NC<<endl;
        cout<<RED_NO_FLASH<<"\n\nWould You like to continue?(Y/N)\n"<<NC;
        cin>>input;
        if(input == "y" || input == "Y"){
            restart = true;
        }
        else{
            restart = false;
        }
    }
    void generateMap(){
        char ORANGE_NO_FLASH[] = "\033[1;33m";
        char RED_NO_FLASH[] = "\033[1;31m";
        char NC[] = "\033[0m";
        char GREEN_NO_FLASH[] = "\033[0;32m";
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
                if(asteroids[2] == 3){
                    asteroids[2] = 0;
                    boostSpeed += 1;
                    boostCounter = 20;
                }
                score += 1;
            }
            if((a[0] <= coords[0] + 1 && a[0] >= coords[0] - 1) && (a[1] <= coords[1] + 1 && a[1] >= coords[1] - 1)){
                lostScreen();
                score = 0;
                return;
            }
            if(!showScore){
                asteroidSpawner();
                for(int i=0;i<23;i++){
                    for(int j=0;j<80;j++){
                        if(i == a[0] && j == a[1]){
                            if(direction == "f")
                            cout<<ORANGE_NO_FLASH<<"^"<<NC;
                            else if(direction == "b")
                            cout<<ORANGE_NO_FLASH<<"v"<<NC;
                            else if(direction == "l")
                            cout<<ORANGE_NO_FLASH<<"<"<<NC;
                            else if(direction == "r")
                            cout<<ORANGE_NO_FLASH<<">"<<NC;
                        }
                        else if(i == asteroids[0] && j == asteroids[1]){
                            if(asteroids[2] == 0){
                                cout<<RED_NO_FLASH<<"#"<<NC;
                            }
                            else{
                                cout<<RED_NO_FLASH<<"@"<<NC;
                            }
                        }
                        else if(i == coords[0] && j == coords[1]){
                            cout<<"*";
                        }
                        else{
                            if(starPrint == 0){
                                cout<<GREEN_NO_FLASH<<"."<<NC;
                                starPrint = 1;
                            }
                            else if(starPrint < 5){
                                cout<<" ";
                                starPrint += 1;
                            }
                            else{
                                cout<<" ";
                                starPrint = 0;
                            }
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
            if(alternate == 0){
                pathfinder();
                alternate = 1;
            }
            if(boostCounter > 0){
                realSpeed = boostSpeed;
                boostCounter -= 1;
            }
            else{
                realSpeed = mobSpeed;
            }

            if(alternate < realSpeed + 1)
            alternate += 1;
            else
            alternate = 0;
            userCoords[0] = a[0];
            userCoords[1] = a[1];
            std::this_thread::sleep_for(std::chrono::milliseconds(16));
            updatePosition(getKeyPress());
            system("clear");
        }
    }
    char getKeyPress(){
        if(kbhit()){
            char a;
            a = getch();
            return a;
        }
    }
    void asteroidSpawner(){
        srand(time(0));
        int randx = a[1];
        int randy = a[0];
        int powerUp;
        if(asteroids[0] == -1 && asteroids[1] == -1){
            while(randx == a[1])
            randx = rand()%79;
            while(randy == a[0])
            randy = rand()%22;

            asteroids[0] = randy;
            asteroids[1] = randx;
            powerUp = rand()%3 + 1;
            if(powerUp == 2 && mobSpeed == 1){
                asteroids[2] = 3;
            }
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
    int choice;
    int speed = 1;
    cout<<"Enter\n1 -> Easy\n2 -> Medium\n3 -> hard\n";
    cin>>choice;
    if(choice < 4 && choice > 0){
        speed = 4 - choice;
    }
    system("clear");
    Game g(speed);
    return 0;
}