Game Game::fetchResolution(){
  struct winsize w;
  ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
  defaultDimensions[0] = w.ws_row - 1;
  defaultDimensions[1] = w.ws_col;
  return *this;
}