Game Game::fetchResolution(){
  struct winsize w;
  ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
  dimensions[0] = w.ws_row - 3; // Space for the HUD
  dimensions[1] = w.ws_col;
  return *this;
}
