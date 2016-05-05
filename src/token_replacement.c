#include "token_replacement.h"
 
int replacement(char *str, int idx, struct bstree *node, int reg)
{
    /*printf("idx %d\n", idx);
    printf("idx zamen\n%s\n",&str[idx]);*/
    int size_word_del = strlen(node->key);
    int size_word_in = strlen(node->value);
    int delta = size_word_in - size_word_del;
    if (delta > 0) {
	/*printf("delta %d\n", delta);
	printf("src:\n%s\n", &str[idx + size_word_del]);
	printf("dest:\n%s\n", &str[idx + size_word_del + delta]);*/
	memmove(&str[idx + size_word_del + delta], &str[idx + size_word_del], strlen(&str[idx + size_word_del*2]));
	//printf("str before\n%s\n", str);
	strncpy(&str[idx], node->value, size_word_in);
	//printf("str\n%s\n", str);
    }
    else if (delta < 0) {
	/*printf("delta %d\n", delta);
	printf("src:\n%s\n", &str[idx + size_word_del]);
	printf("dest:\n%s\n", &str[idx + size_word_del + delta]);*/
	memmove(&str[idx + size_word_del + delta], &str[idx + size_word_del], strlen(&str[idx + size_word_del-1]));
	//printf("str before\n%s\n", str);
	strncpy(&str[idx], node->value, size_word_in);
	//printf("str\n%s\n", str);
    }
    else if (delta == 0) {
	strncpy(&str[idx], node->value, size_word_in);
    }
    return delta;
}
