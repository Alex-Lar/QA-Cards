#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ioctl.h>
#include <unistd.h>

// Reset
#define RESET "\e[0m"
// Bold
#define BWHITE "\e[1;37m"
#define BBLACK "\e[1;30m"
// 8-bit Mode
#define PGREEN "\e[38;5;34m"
#define PPURPLE_1 "\e[38;5;140m"
#define PPURPLE_2 "\e[38;5;98m"
#define PBLUE "\e[38;5;74m"
#define PORANGE "\e[38;5;172m"
#define PRED "\e[38;5;131m"
#define PYELLOW "\e[38;5;187m"
#define RDGRAY_1 "\e[38;5;244m"
#define RDGRAY_2 "\e[38;5;240m"
// Main Color
#define MCOLOR PPURPLE_1

int getTerminalColumns() {
  struct winsize ws;
  if (ioctl(STDOUT_FILENO, TIOCGWINSZ, &ws) == -1) {
    fprintf(stderr, "Failed to get terminal window size.\n");
    exit(1);
  }
  return ws.ws_col;
}

void printMenuOption(const char *number, const char *text) {
  printf(RDGRAY_1 "[" MCOLOR "%s" RDGRAY_1 "]" RESET " %s\n", number, text);
}

void displayMainMenu() {
  printf("What you wanna do?\n\n");
  printMenuOption("1", "add_card");
  printMenuOption("2", "remove_card");
  printMenuOption("3", "add_topic");
  printMenuOption("4", "remove_topic");
  printMenuOption("5", "list");
  printMenuOption("6", "themes");
  printMenuOption("7", "help");
  printMenuOption("0", "quit");
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

  for (int j = 0; j < spacesQty; ++i, ++j) {
    output[i] = space;
  }
}

void displayWelcomeMessage(char *msg) {
  int col = getTerminalColumns();
  size_t size = strlen(msg) + 1; // I'm a wizard, we love numbers
  char msgCentered[col];
  char dash = '-';

  alignCenter(msg, msgCentered, col, size);
  printf("%s\n", msgCentered);

  printf(RDGRAY_2);
  for (int i = 0; i < col; ++i) {
    printf("%c", dash);
  }
  printf(RESET);
}

int main() {
  int choice;

  displayWelcomeMessage(MCOLOR "QA" RESET " Cards");
  displayMainMenu();
  printf("\n" MCOLOR "Number: " RESET);
  scanf("%d", &choice);

  switch (choice) {
  case 0:
    printf("You're leaving...\n");
    break;
  case 1:
    printf("Add a card...\n");
    break;
  case 2:
    printf("Remove a card...\n");
    break;
  case 3:
    printf("Add a new topic...\n");
    break;
  case 4:
    printf("Remove a topic...\n");
    break;
  case 5:
    printf("I wanna see it all!\n");
    break;
  case 6:
    printf("No color, no party! Choose a theme!\n");
    break;
  case 7:
    printf("I need help...\n");
    break;
  default:
    printf("No, we don't have that here.");
  };

  return 0;
}
