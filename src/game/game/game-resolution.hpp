Game Game::fetchResolution(){
  struct winsize w;
  ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
  dimensions[0] = w.ws_row - 2;
  dimensions[1] = w.ws_col - 5; // Space for the HUD
  return *this;
}
