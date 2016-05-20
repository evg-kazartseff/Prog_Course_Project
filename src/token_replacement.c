#include "token_replacement.h"

int replacement(char *str, int idx, struct bstree *node, int reg)
{
    char *value = NULL;
    toHighCase_en(node->value, &value, reg);
    int size_word_del = strlen(node->key);
    int size_word_in = strlen(node->value);
    int delta = size_word_in - size_word_del;
    if (delta > 0) {
        memmove(&str[idx + size_word_del + delta], &str[idx + size_word_del],
                strlen(&str[idx + size_word_del * 2 - 2]));
        strncpy(&str[idx], value, size_word_in);
    } else if (delta < 0) {
        memmove(&str[idx + size_word_del + delta], &str[idx + size_word_del],
                strlen(&str[idx + size_word_del - 1]));
        strncpy(&str[idx], value, size_word_in);
    } else if (delta == 0) {
        strncpy(&str[idx], node->value, size_word_in);
    }
    return delta;
}
