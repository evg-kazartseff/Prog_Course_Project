#include "dictionary.h"

struct bstree *create_dictionary(FILE *dictionary)
{
    struct bstree *tree;

    char *buf_key = NULL;
    buf_key = malloc(sizeof(char) * buf_size);

    char *buf_value = NULL;
    buf_value = malloc(sizeof(char) * buf_size);
    
    if (!feof(dictionary)) {
	    fscanf(dictionary, "%s\n",buf_key);
	    fscanf(dictionary, "%s\n",buf_value);
	    //buf_key = toLowCase(buf_key);
	    //printf("buf_key %s\n", buf_key);
	    //buf_value = toLowCase(buf_value);
	    tree = bstree_create(buf_key,buf_value);
    }

    while (!feof(dictionary)) {
	    fscanf(dictionary, "%s\n",buf_key);
	    fscanf(dictionary, "%s\n",buf_value);
	    //buf_key = toLowCase(buf_key);
	    //printf("buf_key %s\n", buf_key);
	    //buf_value = toLowCase(buf_value);
	    bstree_add(tree,buf_key,buf_value);
    }
    free(buf_key);
    free(buf_value);
    return tree;
}
