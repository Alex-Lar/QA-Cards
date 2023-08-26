#include "actions.h"
#include "colors.h"
#include "show.h"
#include <stdio.h>

const MenuAction menuActions[] = {quit,       practice, addCard,
                                  removeCard, addTopic, removeTopic,
                                  list,       themes,   help};

int main() {
  int choice;

  showWelcomeMessage(MCOLOR "Card" RESET " CLI");
  showMainMenu();

  printf("\n" MCOLOR "Number: " RESET);
  scanf("%d", &choice);

  if (choice >= 0 &&
      choice <= (sizeof(menuActions) / sizeof(menuActions[0])) - 1) {
    MenuAction action = menuActions[choice];
    action();
  } else {
    printf("No, we don't have that here.\n");
  }

  return 0;
}
