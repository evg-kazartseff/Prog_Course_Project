#include "bstree.h"


struct bstree *bstree_create(char *key, char *value)
{
    struct bstree *node;

    node = malloc(sizeof(*node));
    if (node != NULL) {
        node->key = malloc(sizeof(char) * strlen(key));
        strcpy(node->key, key);
        node->value = malloc(sizeof(char) * strlen(value));
        strcpy(node->value, value);
        node->left = NULL;
        node->right = NULL;
    }
    return node;
}

void bstree_add(struct bstree *tree, char *key, char *value)
{
    struct bstree *parent, *node;
    if (tree == NULL)
        return;

    /* Отыскиваем листовой узел */
    for (parent = tree; tree != NULL;) {
        parent = tree;
        int cmp = strcmp(key, tree->key);
        if (cmp < 0)
            tree = tree->left;
        else if (cmp > 0)
            tree = tree->right;
        else
            return;
    }
    /* Создаем элемент и связываем с узлом */
    node = bstree_create(key, value);
    int cmp = strcmp(key, parent->key);
    if (cmp < 0) {
        parent->left = node;
    } else {
        parent->right = node;
    }
}

struct bstree *bstree_lookup(struct bstree *tree, char *key)
{
    while (tree != NULL) {
        int cmp = strcmp(key, tree->key);
        if (cmp == 0) {
            return tree;
        } else if (cmp < 0) {
            tree = tree->left;
        } else {
            tree = tree->right;
        }
    }
    return tree;
}
