#include "ctest.h"
#include "../src/bstree.h"

CTEST(bstree, bstree_create)
{
    struct bstree *tree = bstree_create("key", "value");
    ASSERT_NOT_NULL(tree);
    ASSERT_STR("key", tree->key);
    ASSERT_STR("value", tree->value);
    free(tree);
}

CTEST(bstree, bstree_add)
{
    struct bstree *tree;
    tree = bstree_create("key", "value");
    ASSERT_NOT_NULL(tree);
    bstree_add(tree, "key1", "value1");
    int okay = 0;
    if (tree->left != NULL || tree->right != NULL)
	okay = 1;
    ASSERT_EQUAL(1, okay);
    if (tree->left != NULL) {
	ASSERT_STR("key1", tree->left->key);
	ASSERT_STR("value1", tree->left->value);
	free(tree->left);
    }
    if (tree->right != NULL) {
	ASSERT_STR("key1", tree->right->key);
	ASSERT_STR("value1", tree->right->value);
	free(tree->right);
    }
    free(tree);
}

CTEST(bstree, bstree_lookup)
{
    struct bstree *tree;
    tree = bstree_create("key", "value");
    bstree_add(tree, "key1", "value1");
    
    struct bstree *node;
    
    node = bstree_lookup(tree, "key1");
    ASSERT_NOT_NULL(node);
    ASSERT_STR("key1", node->key);
    ASSERT_STR("value1", node->value);
    
    node = bstree_lookup(tree, "key2");
    ASSERT_NULL(node);
    if (tree->left != NULL) {
	free(tree->left);
    }
    if (tree->right != NULL) {
	free(tree->right);
    }
    free(tree);
}
