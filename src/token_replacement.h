#ifndef TOKEN_REPLACEMENT_H
#define TOKEN_REPLACEMENT_H

#include "bstree.h"
#include <string.h>
#include <stdio.h>

void right(char *str, int idx, int len);
void left(char *str, int idx, int len);
void replacement(char *str, int idx, struct bstree *node);

#endif
