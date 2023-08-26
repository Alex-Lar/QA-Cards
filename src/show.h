#ifndef SHOW_H
#define SHOW_H

#include "options.h"
#include <string.h>

void showOption(const char *number, const char *text);
void showMainMenu(MenuOption menuOptions[], int size);
void showWelcomeMessage(char *msg);

#endif
