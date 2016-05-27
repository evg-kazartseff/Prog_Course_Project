#include "parsing.h"

struct FLG *parsing(int argc, char **argv, struct Data *t_file)
{
    struct FLG *flg;
    flg = malloc(sizeof(*flg));
    if (flg != NULL) {
        flg->arg = 0;
        flg->file = 0;
        flg->info = 0;
        flg->print = 0;
    }

    t_file->input = NULL;
    t_file->output = NULL;
    t_file->dictionary = NULL;

    if (argc < 2) {
        printf("Please specify the file names!\n");
        flg->arg = 1;
    }

    int key;
    int len;
    //opterr = 0; // запретить вывод ошибок от getopt()
    while ((key = getopt(argc, argv, "hvi:o:d:p")) != -1) {
        switch (key) {
            case 'p':
                flg->print = 1;
                flg->info = 1;
                break;
            case 'h':
                flg->info = 1;
                printf
                    ("Basic usage: \"translate -i input_file -d dictionary -o output_file\"\n");
                break;
            case 'v':
                flg->info = 1;
                printf("Version 3.0\n");
                break;
            case 'd':
                flg->file = 1;
                if (check_path(optarg) == 1) {
                    flg->arg = 1;
                    printf("Incorrect file name: %s\n", optarg);
                }
                len = strlen(optarg) + 1;
                t_file->dictionary = malloc(sizeof(char) * len);
                strncpy(t_file->dictionary, optarg, len - 1);
                break;
            case 'o':
                flg->file = 1;
                if (check_path(optarg) == 1) {
                    flg->arg = 1;
                    printf("Incorrect file name: %s\n", optarg);
                }
                len = strlen(optarg) + 1;
                t_file->output = malloc(sizeof(char) * len);
                strncpy(t_file->output, optarg, len - 1);
                break;
            case 'i':
                flg->file = 1;
                if (check_path(optarg) == 1) {
                    flg->arg = 1;
                    printf("Incorrect file name: %s\n", optarg);
                }
                len = strlen(optarg) + 1;
                t_file->input = malloc(sizeof(char) * len);
                strncpy(t_file->input, optarg, len - 1);
                break;
            default:           /* '?' */
                printf("look \"translate -h\"\n");
        }
    }
    if (flg->file == 1) {
        if ((t_file->input == NULL) || (t_file->dictionary == NULL)
            || (t_file->output == NULL)) {
            if (t_file->input == NULL) {
                printf("Unknown input file\n");
            }
            if (t_file->dictionary == NULL) {
                printf("Unknown dictionary file\n");
            }
            if (t_file->output == NULL) {
                printf("Unknown output file\n");
            }
            flg->file = 0;
        }
    } else if (flg->info == 1) {
        flg->file = 0;
    }
    return flg;
}

int check_path(char *str)
{
    int flg = 0;
    if (str == NULL)
        flg = 1;
    else {
        char *pl = strrchr(str, '.');
        if (pl == NULL)
            flg = 1;
        else if ((long int)(pl[1]) == (long int)'/')
            flg = 1;
    }
    return flg;
}
