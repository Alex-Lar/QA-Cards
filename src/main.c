#include "actions.h"
#include "colors.h"
#include "show.h"
#include <stdio.h>

int main() {
  extern MenuAction menuActions[];
  extern char *MENU_OPTIONS[];
  extern int NUMBER_OF_OPTIONS;

  int choice;

  showWelcomeMessage(MCOLOR "Card" RESET " CLI");

  showMainMenu(MENU_OPTIONS, NUMBER_OF_OPTIONS);

  printf("\n" MCOLOR "Number: " RESET);
  scanf("%d", &choice);

  if (choice >= 0 && choice <= NUMBER_OF_OPTIONS - 1) {
    MenuAction action = menuActions[choice];
    action();
  } else {
    printf("No, we don't have that here.\n");
  }

  return 0;
}
