#include <bits/stdc++.h>
#include <string>
#include <sys/time.h>
#include <thread>
#include "../mob.hpp"
#include "../shooter.hpp"
#include "../../libs/COLORS!.hpp"
#include "../../util/input.hpp"

const int defaultAsteroids[3] = {-1, -1, 3};

class Game: public KillerPiller {
  public:
    //Speed is for the speed of the mob as compared to the user.
    Game(int speed) {
      mobSpeed = speed;
      this->start();
    }

  private:
    Gun blaster; // Declaring the blaster/Gun from shooter.h
    int mobSpeed; //speed of the mob relative to the user.

    string direction = "f"; // Tells the direction of the user. f == forward , b == backward , l == left , r == right. (Lowercase is important)
    bool showScore = false;// Tell if the score should be displayed or not.
    int score = 0; // The score of the user

    int alternate = 0; // A temporary integer to modulate the speed of the mob. It changes its from 0 to the mobSpeed by 1 every frame therefore the speed of the mob decreases.
    //As the mob moves only when alternate is 0.
    int asteroids[3] = {
      defaultAsteroids[0],
      defaultAsteroids[1],
      defaultAsteroids[2]
    }; //Represents the asteroid, 0th element -> y coordinate , 1st element -> x coordinate , 2nd element -> the powerup  Value.
    // If power up value is 3, the gun gets equipped to the user.

    int boostCounter = 0;// The user gets 10 shots using the gun, these shots fired are counted using this var.
    int starPrint = 0; // The stars should be printed after a regular interval. Thi variable moves between 0 and 5 and prints the star if equal to 0
    bool gunEnable = false; // Tells if the gun is enabled or not.
    bool fired = false; // If the user has fired a bullet or not.

    const int tps = 10;
    const int fps = 60;
    timeval lastFrameEndTime;

    bool gameRunning = false;
    float gameTickDelta = 0;

    Game start() {
      this->reset();
      // this->generateMap();
      gameRunning = true;
      gettimeofday(&lastFrameEndTime, NULL);
      this->eventLoop();

      return *this;
    }

    Game lostScreen();
    Game reset();
    Game asteroidSpawner();
    Game updatePosition(char input);
    Game frame();
    Game eventLoop();
};
