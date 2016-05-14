#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "parsing.h"
#include "bstree.h"
#include "dictionary.h"
#include "token_replacement.h"
#include "register.h"

#define translate_const 256

int main(int argc, char **argv)
{
    struct Data *t_file;
    t_file = malloc(sizeof(*t_file));

    struct FLG *flg;
    flg = parsing(argc, argv, t_file);

    if (flg->arg == 1)
        return EXIT_FAILURE;
    if (flg->info == 1 && flg->file == 0)
        return EXIT_SUCCESS;
    if (flg->file == 0)
        return EXIT_FAILURE;

    FILE *input;
    input = fopen(t_file->input, "r");
    if (input == NULL) {
        printf("Can't open input file!!\n");
        return EXIT_FAILURE;
    }

    unsigned int N = 256, i = 0;
    char *buf = (char *) malloc(sizeof(char) * N);      //заменить на логарифмическую функцию  
    while ((buf[i] = fgetc(input)) != EOF) {
        if (++i >= N) {
            N = N * 2;
            buf = (char *) realloc(buf, sizeof(char) * N);
        }
    }
    buf[i] = '\0';
    fclose(input);


    FILE *dictionary;
    dictionary = fopen(t_file->dictionary, "r");
    if (dictionary == NULL) {
        printf("Can't open dictionary file!!\n");
        return EXIT_FAILURE;
    }
    struct bstree *tree;
    tree = create_dictionary(dictionary);
    fclose(dictionary);


    FILE *output;
    output = fopen(t_file->output, "w");
    if (output == NULL) {
        printf("Can't create output file!!\n");
        return EXIT_FAILURE;
    }

    char *buf_tr = malloc(strlen(buf) * sizeof(char) + translate_const);
    strcpy(buf_tr, buf);

    char *delim = ",.?! \t\n;:-";

    char *token = NULL;
    token = strtok(buf, delim);

    struct bstree *node;
    int offset = 0;
    int flg_reg = 0;
    char *tok_low;
    while (token != NULL) {
        tok_low = NULL;
        flg_reg = toLowCase_ru(token, &tok_low);
        if (tok_low != NULL) {
            node = bstree_lookup(tree, tok_low);
        } else {
            node = bstree_lookup(tree, token);
        }
        if (node != NULL) {
            int idx = (int) (token - buf);
            offset = offset + replacement(buf_tr, idx + offset, node, flg_reg);
        }
        token = strtok(NULL, delim);
    }
    fprintf(output, "%s", buf_tr);
    fclose(output);
    if (flg->print == 1)
        printf("\n%s\n", buf_tr);

    return EXIT_SUCCESS;
}
