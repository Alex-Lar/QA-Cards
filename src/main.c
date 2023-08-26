#include "colors.h"
#include "options.h"
#include "show.h"
#include <stdio.h>

int main() {
  extern MenuOption menuOptions[];
  extern int NUMBER_OF_OPTIONS;

  int choice;

  showWelcomeMessage(MCOLOR "Card" RESET " CLI");
  showMainMenu(menuOptions, NUMBER_OF_OPTIONS);

  printf("\n" MCOLOR "Number: " RESET);
  scanf("%d", &choice);

  if (choice >= 0 && choice <= NUMBER_OF_OPTIONS - 1) {
    MenuOption option = menuOptions[choice];
    option.action();
  } else {
    printf("No, we don't have that here.\n");
  }

  return 0;
}
