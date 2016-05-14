#ifndef BSTREE_H
#define BSTREE_H

#include <stdlib.h>
#include <string.h>

struct bstree {
    char *key;                  /* Ключ */
    char *value;                /* Данные */
    struct bstree *left;
    struct bstree *right;
};

struct bstree *bstree_create(char *key, char *value);
void bstree_add(struct bstree *tree, char *key, char *value);
struct bstree *bstree_lookup(struct bstree *tree, char *key);

#endif
