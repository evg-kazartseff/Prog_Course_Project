#ifndef PARSING_H
#define PARSING_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>             // getopt

struct Data {
    char *input;
    char *dictionary;
    char *output;
};

struct FLG {
    int print;
    int info;
    int file;
    int arg;
};

struct FLG *parsing(int argc, char **argv, struct Data *t_file);
int check_path(char *str);

#endif
