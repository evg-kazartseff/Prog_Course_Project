#include "ctest.h"
#include "../src/token_replacement.h"
#include "../src/bstree.h"
#include <string.h>

CTEST(replacement, test_1)
{
    char *str = NULL;
    str = malloc(256 * sizeof(char));
    sprintf(str, "%s", "замена слова тест на английское");
    int idx = 24; //индекс слова тест в массиве
    
    char *buf1 = "тест";
    char *buf2 = "test";
    
    struct bstree *tree;
    tree = bstree_create(buf1, buf2);
    int zn_delta;
    zn_delta = strlen(buf2) - strlen(buf1);
    int delta = replacement(str, idx, tree, 0);
    ASSERT_EQUAL(zn_delta, delta);
    ASSERT_STR("замена слова test на английское", str);
    free(str);
}

CTEST(replacement, test_2)
{
    char *str = NULL;
    str = malloc(256 * sizeof(char));
    sprintf(str, "%s", "замена слова тест на английское");
    int idx = 24; //индекс слова тест в массиве
    
    char *buf1 = "тест";
    char *buf2 = "test";
    
    struct bstree *tree;
    tree = bstree_create(buf1, buf2);
    int zn_delta = strlen(buf2) - strlen(buf1);
    int delta = replacement(str, idx, tree, 1);
    ASSERT_EQUAL(zn_delta, delta);
    ASSERT_STR("замена слова Test на английское", str);
    free(str);
}

CTEST(replacement, test_3)
{
    char *str = NULL;
    str = malloc(256 * sizeof(char));
    sprintf(str, "%s", "замена слова Тест на английское");
    int idx = 24; //индекс слова тест в массиве
    
    char *buf1 = "тест";
    char *buf2 = "test";
    
    struct bstree *tree;
    tree = bstree_create(buf1, buf2);
    int zn_delta = strlen(buf2) - strlen(buf1);
    int delta = replacement(str, idx, tree, 1);
    ASSERT_EQUAL(zn_delta, delta);
    ASSERT_STR("замена слова Test на английское", str);
    free(str);
}
