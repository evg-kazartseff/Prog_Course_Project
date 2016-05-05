#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h> // getopt
#include "bstree.h"
#include "dictionary.h"
#include "token_replacement.h"

#define translate_const 256

struct Data {
    char *input;
    char *dictionary;
    char *output;
};

int main (int argc, char **argv)
{
    struct Data *t_file;
    t_file = malloc(sizeof(*t_file));
    t_file->input = NULL;
    t_file->output = NULL;
    t_file->dictionary = NULL;
	
    if (argc < 2) {
	printf ("Please specify the file names!\n");
	return EXIT_FAILURE;
    }

    int key;
    int len;
    //opterr = 0; // запретить вывод ошибок от getopt()
    while ((key = getopt(argc, argv, "hvi:o:d:")) != -1) {
	switch (key) {
	    case 'h':
		printf("Basic usage: \"translate -i input_file -d dictionary -o output_file\"\n");
		break;
	    case 'v':
		printf("Version 0.0\n");
		break;
	    case 'd':
		len = strlen(optarg)+1;
		t_file->dictionary = malloc(sizeof(char) * len);
		strncpy(t_file->dictionary, optarg, len-1);
		break;
	    case 'o':
		len = strlen(optarg)+1;
		t_file->output = malloc(sizeof(char) * len);
		strncpy(t_file->output, optarg, len-1);
		break;
	    case 'i':
		len = strlen(optarg)+1;
		t_file->input = malloc(sizeof(char) * len);
		strncpy(t_file->input, optarg, len-1);
		break;
	    default: /* '?' */
		printf ("look trenslate -h\n");
	}
    }
    
    if ((t_file->input == NULL) || (t_file->dictionary == NULL) || (t_file->output == NULL)) {
	if (t_file->input == NULL) {
	    printf ("Unknown input file\n");
	}
	if (t_file->dictionary == NULL) {
	    printf ("Unknown dictionary file\n");
	}
	if (t_file->output == NULL) {
	    printf ("Unknown output file\n");
	}
	return EXIT_FAILURE;
    }

    FILE *input;
    input = fopen(t_file->input, "r");
    if (input == NULL) {
	    printf ("Can't open input file!!\n");
	    return EXIT_FAILURE;
    }
    
    unsigned int N = 256, i = 0;   
    char* buf = (char*) malloc(sizeof(char)*N); //заменить на логарифмическую функцию  
    while ((buf [i] = fgetc(input)) != EOF)  {                
        if (++i >= N) {
            N = N * 2;
            buf = (char*) realloc(buf, sizeof(char)*N);        
        }   
    }
    buf[i] = '\0';
    fclose(input);


    FILE *dictionary;
    dictionary = fopen(t_file->dictionary, "r");
    if (dictionary == NULL) {
	    printf ("Can't open dictionary file!!\n");
	    return EXIT_FAILURE;
    }
    struct bstree *tree;
    tree = create_dictionary(dictionary);
    fclose(dictionary);

    
    FILE *output;
    output = fopen(t_file->output, "w");
    if (output == NULL) {
	printf ("Can't create output file!!\n");
	return EXIT_FAILURE;
    }

    printf("%s\n",buf);

    char *buf_tr = malloc(strlen(buf) * sizeof(char) + translate_const);
    strcpy(buf_tr, buf);
    
    char *delim = ",.?! \t\n;:-";
    
    char *token = NULL;
    token = strtok(buf, delim);
    
    struct bstree *node;
    while (token != NULL) {
	//printf("token \"%s\"\n",token);
	node = bstree_lookup(tree, token);
	if (node != NULL) {
	    //printf("lookup %s %s\n",node->key, node->value);
	    int idx = (int)(token - buf);
	    //printf("idx %d\n", idx);
	    replacement(buf_tr, idx, node);
	}
	else
	    printf("word: \"%s\" not found!\n", token);
	token = strtok(NULL ,delim);
    }
    
    printf("%s\n",buf_tr);
    
    return EXIT_SUCCESS;
}
