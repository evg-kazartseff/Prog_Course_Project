#include "dictionary.h"

struct bstree *create_dictionary(FILE * dictionary)
{
    struct bstree *tree;

    char *buf_key = NULL;
    buf_key = malloc(sizeof(char) * buf_size);

    char *buf_value = NULL;
    buf_value = malloc(sizeof(char) * buf_size);

    unsigned long int N = 256, i = 0;
    char *buf = (char *) malloc(sizeof(char) * N);      //заменить на логарифмическую функцию  
    while ((buf[i] = fgetc(dictionary)) != EOF) {
        if (++i >= N) {
            N = N * 2;
            buf = (char *) realloc(buf, sizeof(char) * N);
        }
    }
    buf[i] = '\0';

    char *token;
    token = strtok(buf, "-\n");

    if (token != NULL) {
        if (token[strlen(token) - 1] == ' ') {
            token[strlen(token) - 1] = '\0';
            strcpy(buf_key, token);
        }
        token = strtok(NULL, "-\n");
        if (token != NULL) {
            if (token[0] == ' ') {
                for (int i = 0; i < strlen(token); i++)
                    token[i] = token[i + 1];
                strcpy(buf_value, token);
            }
        }
        toLowCase_ru(buf_key, &buf_key);
        toLowCase_en(buf_value, &buf_value);
        tree = bstree_create(buf_key, buf_value);
    }

    token = strtok(NULL, "-\n");
    while (token != NULL) {
        if (token[strlen(token) - 1] == ' ') {
            token[strlen(token) - 1] = '\0';
            strcpy(buf_key, token);
        }
        token = strtok(NULL, "-\n");
        if (token != NULL) {
            if (token[0] == ' ') {
                /*for (int i = 0; i < strlen(token); i++)
                   token[i] = token[i + 1]; */
                strcpy(buf_value, &token[1]);
            }
        }
        toLowCase_ru(buf_key, &buf_key);
        toLowCase_en(buf_value, &buf_value);
        bstree_add(tree, buf_key, buf_value);
        token = strtok(NULL, "-\n");
    }
    free(buf);
    free(buf_key);
    free(buf_value);
    return tree;
}
