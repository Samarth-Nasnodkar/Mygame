#include <math.h>
#include "./game/game/game.hpp"
#include "./game/game/lost-screen.hpp"
#include "./game/game/reset.hpp"
#include "./game/game/asteroid-spawner.hpp"
#include "./game/game/update-position.hpp"
#include "./game/game/event-loop.hpp"
#include "./game/game/frame.hpp"
#include "./game/game/game-pause.hpp"
#include "./game/game/game-resolution.hpp"
#include "./game/game/replay.hpp"

using namespace std;

int main() {
  // Noice. You made it till here.
  int choice;
  int speed = 1;

  cout << GREEN_NO_UNDER << "1: " << NC << "Easy" << endl;
  cout << GREEN_NO_UNDER << "2: " << NC << "Medium" << endl;
  cout << GREEN_NO_UNDER << "3: " << NC << "Hard" << endl;
  cout << "Choose game difficulty: " << ORANGE_NO_UNDER;
  cin >> choice;
  cout << NC;

  choice = max(1, min(choice, 4));

  system("clear");
  Game g;
  return 0;
}
