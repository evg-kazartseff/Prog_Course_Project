#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h> // getopt

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
	//opterr = 0; // запретить вывод ошибок от getopt()
	while ((key = getopt(argc, argv, "hvi:o:d:")) != -1)
	{
		switch (key)
		{
            default: /* '?' */
			case 'h':
				printf("Basic usage: \"translate -i input_file -d dictionary -o output_file\"\n");
				break;
			case 'v':
				printf("Version 0.0\n");
				break;
            case 'd':
                t_file->dictionary = malloc(sizeof(char) * strlen(optarg));
                strncpy(t_file->dictionary, optarg, strlen(optarg));
                break;
            case 'o':
                t_file->output = malloc(sizeof(char) * strlen(optarg));
                strncpy(t_file->output, optarg, strlen(optarg));
                break;
			case 'i':
				t_file->input = malloc(sizeof(char) * strlen(optarg));
                strncpy(t_file->input, optarg, strlen(optarg));
				break;
		}
	}


printf ("input %s\n",t_file->input);
printf ("output %s\n",t_file->output);
    FILE *input;
    input = fopen(t_file->input, "r");
    if (input == NULL) {
		printf ("Can't open input file!!\n");
		return EXIT_FAILURE;
	}
    FILE *dictionary;
    dictionary = fopen(t_file->dictionary, "r");
    if (dictionary == NULL) {
		printf ("Can't open dictionary file!!\n");
		return EXIT_FAILURE;
	}
    FILE *output;
    output = fopen(t_file->output, "a");
    if (output == NULL) {
		printf ("Can't create output file!!\n");
		return EXIT_FAILURE;
	}
}
