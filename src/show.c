#include "show.h"
#include "colors.h"
#include "utils.h"

void showOption(const char *number, const char *text) {
  printf(RDGRAY_1 "[" MCOLOR "%s" RDGRAY_1 "]" RESET " %s\n", number, text);
}

void showMainMenu(MenuOption menuOptions[], int size) {
  printf("What you wanna do?\n\n");
  char num_str[15];

  for (int i = 1; i < size; i++) {
    sprintf(num_str, "%d", i);
    showOption(num_str, menuOptions[i].name);
  }

  showOption("0", menuOptions[0].name);
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
