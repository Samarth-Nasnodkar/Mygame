# How it works?
This game is simple, There is the user which has to collect all the asteroids which spawn in random space before the enemy comes and captures you.
The enemy will be always chasing you with various speeds , which depends on the difficulty level you choose.

# The Mob class
The mob class is responsible for all actions taken by the enemy. It controls the path on which the enemy moves using a pathfinding algorithm.
The enemy will create an imaginary graph at every frame in which it lies on the origin and the user in its respective position. From there it first finds the user's quadrant
and then the chases the user with its full potential. A quick preview of the game and the enemy's movement is shown below.

# A Sneak Peak
![Here is a quick preview](https://i.imgur.com/5daFvPN.gif)

# Commands
The commands are simple and intuitive:  
  W/A/S/D to move Up/Left/Down/Right respectively.  
  P to Pause/Play the game  
  And  
  O to check your score.
  
# How to run it on windows
To run it on windows, it is pretty simple. You have to enable windows subsystem for linux followed by installing the g++ compiler through bash.  
After that you can compile the project for linux and use it through your linux bash terminal on windows.
