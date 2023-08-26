#ifndef UTILS_H
#define UTILS_H

#include <stdio.h>
#include <stdlib.h>
#include <sys/ioctl.h>
#include <unistd.h>

#include <stddef.h>

int getTerminalColumns();

void alignCenter(char *input, char *output, int columns, size_t inputSize);

#endif
