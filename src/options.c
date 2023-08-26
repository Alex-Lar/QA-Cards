#include "options.h"
#include "colors.h"
#include <stdio.h>

MenuOption menuOptions[] = {
    {"quit", quit},          {"practice", practice},
    {"add_card", addCard},   {"remove_card", removeCard},
    {"add_topic", addTopic}, {"remove_topic", removeTopic},
    {"list", list},          {"themes", themes},
    {"help", help}};

const int NUMBER_OF_OPTIONS = sizeof(menuOptions) / sizeof(menuOptions[0]);

void quit() { printf(BWHITE "\nGoodbye!\n" RESET); }

void practice() { printf("I want to practice!\n"); }

void addCard() { printf("Add a new card\n"); }

void removeCard() { printf("Remove a card\n"); }

void addTopic() { printf("Add a new topic\n"); }

void removeTopic() { printf("Remove a topic\n"); }

void list() { printf("I wanna see it all!\n"); }

void themes() { printf("I want to select some fancy theme!\n"); }

void help() { printf("Help me!\n"); }
