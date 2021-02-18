Game Game::fetchResolution(){
  struct winsize w;
  ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
  dimensions[0] = w.ws_row - 5;
  dimensions[1] = w.ws_col - 2; // Space for the HUD
  return *this;
}
