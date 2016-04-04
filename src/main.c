#include <stdio.h>
#include <stdlib.h>

int main (int argc, char *argv[])
{
    if (argc < 3) {
        printf ("\n");
        return EXIT_FAILURE;
    }

    FILE *input;
    input = fopen(argv[1], "r");
    FILE *dictionary;
    dictionary = fopen(argv[2], "r");
    FILE *output;
    output = fopen(argv[3], "a");
    printf("%s\n",argv[1]);
    printf("%s\n",argv[2]);
    printf("%s\n",argv[3]);
}
