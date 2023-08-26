#ifndef OPTIONS_H
#define OPTIONS_H

typedef struct {
  const char *name;
  void (*action)();
} MenuOption;

void quit();

void practice();

void addCard();

void removeCard();

void addTopic();

void removeTopic();

void list();

void themes();

void help();

#endif
