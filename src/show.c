#include "show.h"
#include "colors.h"
#include "utils.h"

void showOption(const char *number, const char *text) {
  printf(RDGRAY_1 "[" MCOLOR "%s" RDGRAY_1 "]" RESET " %s\n", number, text);
}

void showMainMenu() {
  printf("What you wanna do?\n\n");
  showOption("1", "practice");
  showOption("2", "add_card");
  showOption("3", "remove_card");
  showOption("4", "add_topic");
  showOption("5", "remove_topic");
  showOption("6", "list");
  showOption("7", "themes");
  showOption("8", "help");
  showOption("0", "quit");
}

void showWelcomeMessage(char *msg) {
  int col = getTerminalColumns();
  size_t size = strlen(msg) + 1; // I'm a wizard, we love numbers
  char msgCentered[col];
  char dash = '-';

  alignCenter(msg, msgCentered, col, size);
  printf("\e[1m%s\n" RESET, msgCentered);

  printf(RDGRAY_2);
  for (int i = 0; i < col; ++i) {
    printf("%c", dash);
  }
  printf(RESET);
}
