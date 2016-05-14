#ifndef DICTIONARY_H
#define DICTIONARY_H

#define buf_size 80

#include <stdio.h>
#include <stdlib.h>
#include "bstree.h"
#include "register.h"

struct bstree *create_dictionary(FILE * dictionary);

#endif
