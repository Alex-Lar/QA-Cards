#include "actions.h"
#include "colors.h"
#include <stdio.h>

const char *MENU_OPTIONS[] = {"quit",        "practice",  "add_card",
                              "remove_card", "add_topic", "remove_topic",
                              "list",        "themes",    "help"};

const MenuAction menuActions[] = {quit,       practice, addCard,
                                  removeCard, addTopic, removeTopic,
                                  list,       themes,   help};

const int NUMBER_OF_OPTIONS = sizeof(MENU_OPTIONS) / sizeof(MENU_OPTIONS[0]);

void quit() { printf(BWHITE "\nGoodbye!\n" RESET); }

void practice() { printf("I want to practice!\n"); }

void addCard() { printf("Add a new card\n"); }

void removeCard() { printf("Remove a card\n"); }

void addTopic() { printf("Add a new topic\n"); }

void removeTopic() { printf("Remove a topic\n"); }

void list() { printf("I wanna see it all!\n"); }

void themes() { printf("I want to select some fancy theme!\n"); }

void help() { printf("Help me!\n"); }
