#include "utils.h"

int getTerminalColumns() {
  struct winsize ws;
  if (ioctl(STDOUT_FILENO, TIOCGWINSZ, &ws) == -1) {
    fprintf(stderr, "Failed to get terminal window size.\n");
    exit(1);
  }
  return ws.ws_col;
}

void alignCenter(char *input, char *output, int columns, size_t inputSize) {
  int spacesQty =
      (columns - (inputSize - 15)) / 2; // Number magic is happening here.
  const char space = ' ';

  int i;
  for (i = 0; i < spacesQty; ++i) {
    output[i] = space;
  }

  for (int j = 0; j < inputSize; ++i, ++j) {
    output[i] = input[j];
  }
}
