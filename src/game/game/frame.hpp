Game Game::frame() {
  system("clear");
  bool shotUsed = false;
  if(a[0] > 22) a[0] = 0;
        else if(a[1] > 79) a[1] = 0;
        else if(a[0] < 0) a[0] = 22;
        else if(a[1] < 0) a[1] = 78;
        else if(a[0] == asteroids[0] && a[1] == asteroids[1]){
          asteroids[0] = -1;// the -1 signifies that the asteroid should be despawned.
          asteroids[1] = -1;
          if(asteroids[2] == 3) { // Checking if the asteroid was a powerup asteroid.
            asteroids[2] = 3;
            boostCounter = 10;
            gunEnable = true;
          }
          score += 1;
        }
        else if((a[0] <= coords[0] + 1 && a[0] >= coords[0] - 1) && (a[1] <= coords[1] + 1 && a[1] >= coords[1] - 1)){
          //User lost.

          lostScreen();
          score = 0;
        }
        if(!showScore){
            asteroidSpawner(); // Spawns asteroid if not present in the map.
            for(int i=0;i<23;i++){
                for(int j=0;j<80;j++){
                    if(i == a[0] && j == a[1]){
                        //Printing the user character.
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
                        //Printing the asteroid.
                        if(asteroids[2] == 0){
                            cout<<RED_NO_FLASH<<"#"<<NC;
                        }
                        else{
                            cout<<RED_NO_FLASH<<"@"<<NC;
                        }
                    }
                    else if(i == coords[0] && j == coords[1]){
                        //Enemy
                        cout<<"*";
                    }
                    else if(blaster.shootable(j , i , a[1] , a[0] , coords[1] , coords[0] , direction) && boostCounter > 0 && fired){
                        //The shooting animation.
                        cout<<"+";
                        shotUsed = true;

        }
                    else{
                        //Printing the stars alternately.
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
            //To display the score.
            for(int i=0;i<40;i++){
                for(int j=0;j<40;j++){
                    if(i == 19 && j == 17){
                        cout<<"\033[1;33m"<<"Your"<<"\033[0m";
                        j += 3;//Not needed but just felt like keeping the boundaries still.
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
            pathfinder();// This algo will find the path for the mob and also move it.
            alternate = 1;
        }
        else if(alternate < mobSpeed + fps/30)
        alternate += 1;
        else
        alternate = 0;
        //Since the coordinates of the user might have changed in the frame, their counterpart in the KillerPiller class need to be reassigned.
        userCoords[0] = a[0];
        userCoords[1] = a[1];
        if(shotUsed){
            //Since one shot has been used
          boostCounter -= 1;
          shotUsed = false;
          fired = false;
  }
  if(boostCounter <= 0){
    //The user has used all of their shots.
    gunEnable = false;
    boostCounter = 0;
  }

  updatePosition(getKeyPress());

  return *this;
}
