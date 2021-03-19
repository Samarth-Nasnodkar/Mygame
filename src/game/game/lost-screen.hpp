Game Game::lostScreen() {
  // This screen is showed when the user loses.
  gameRunning = false;
  char input;
  system("clear");

  cout << RED_FLASH << "GAME OVER" << NC << endl;
  cout << "Score: \n"<< ORANGE_NO_FLASH << score << NC << endl;

  cout << GREEN_NO_UNDER << "\n\nWould You like to continue?[y/N]: ";
  cin >> input;

  if (input == 'y' || input == 'Y') this->start();
  else if (input == 'r') this->replay();

  return *this;
}
