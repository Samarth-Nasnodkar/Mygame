#include "../libs/conio.h"

char getKeyPress() {
  if (kbhit()) { // If user has hit a key or not.
    char a;
    a = getch(); // The key the user hit.
    return a;
  }
  else return 'e';
}
