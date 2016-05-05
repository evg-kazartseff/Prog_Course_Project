#include "token_replacement.h"
 
void right(char *str, int idx, int len)
{
    printf("len %d",len);
}

void left(char *str, int idx, int len)
{
    printf("len %d",len);
}

void replacement(char *str, int idx, struct bstree *node)
{
    int size_word_del = strlen(node->key) / 2;
    int size_word_in = strlen(node->value);
    printf("len del %d\n",size_word_del + idx);
    int delta = 0;
    if (size_word_del < size_word_in) {
	delta = size_word_in - size_word_del;
	printf("delta %d\n", delta);
	printf("src:\n%s\n", &str[idx + size_word_del*2]);
	printf("dest:\n%s\n", &str[idx + size_word_del*2 + delta]);
	memmove(&str[idx + size_word_del + delta], &str[idx + size_word_del], strlen(&str[idx + size_word_del*2]));
	printf("str before\n%s\n", str);
	strncpy(&str[idx], node->value, size_word_in);
	printf("str\n%s\n", str);
    }
    else if (size_word_del > size_word_in) {
	delta = size_word_del - size_word_in;
	//left(str, idx , delta);
	
    }
}
