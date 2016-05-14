#include "ctest.h"
#include "../src/parsing.h"

CTEST(parsing, test_1)
{
    struct Data *t_file;
    t_file = malloc(sizeof(*t_file));
    int i;
    char **arg = malloc(7 * sizeof(char*));
    for (i = 0; i < 7; i++)
	arg[i] = malloc(80 * sizeof(char));

    struct FLG *flg;
    flg = parsing(0, arg, t_file);
    ASSERT_EQUAL(1, flg->arg);
    free(t_file);
    for (i = 0; i < 7; i++)
	free(arg[i]);
    free(arg);
}

CTEST(parsing, test_2)
{
    struct FLG *flg;
    
    struct Data *t_file;
    t_file = malloc(sizeof(*t_file));
    int i;
    char **arg = (char **) malloc(7 * sizeof(char*));
    for (i = 0; i < 7; i++)
	arg[i] = (char *) malloc(80 * sizeof(char));
	
    arg[0] = "translate";
    arg[1] = "-i";
    arg[2] = "./test_file/text_rus.txt";
    arg[3] = "-d";
    arg[4] = "../dictionary/dictionary.txt";
    arg[5] = "-o";
    arg[6] = "./test_file/text_eng.txt";
    flg = parsing(7, arg, t_file);
    ASSERT_EQUAL(0, flg->arg);
    ASSERT_EQUAL(1, flg->file);
    ASSERT_EQUAL(0, flg->print);
    free(t_file);
}

CTEST(parsing, test_3)
{
    struct FLG *flg;
    
    struct Data *t_file;
    t_file = malloc(sizeof(*t_file));
    int i;
    char **arg = malloc(7 * sizeof(char*));
    for (i = 0; i < 7; i++)
	arg[i] = malloc(80 * sizeof(char));
	
    arg[0] = "translate";
    arg[1] = "-i";
    arg[2] = "./test_file/text_rus.txt";
    arg[3] = "-d";
    arg[4] = "";
    arg[5] = "-o";
    arg[6] = "./test_file/text_eng.txt";
    flg = parsing(7, arg, t_file);
    ASSERT_EQUAL(0, flg->arg);
    ASSERT_EQUAL(0, flg->file);
    ASSERT_EQUAL(0, flg->print);
    free(t_file);
}

CTEST(parsing, test_4)
{
    struct FLG *flg;
    
    struct Data *t_file;
    t_file = malloc(sizeof(*t_file));
    int i;
    char **arg = malloc(8 * sizeof(char*));
    for (i = 0; i < 8; i++)
	arg[i] = malloc(80 * sizeof(char));
	
    arg[0] = "translate";
    arg[1] = "-i";
    arg[2] = "./test_file/text_rus.txt";
    arg[3] = "-d";
    arg[4] = "../dictionary/dictionary.txt";
    arg[5] = "-o";
    arg[6] = "./test_file/text_eng.txt";
    arg[7] = "-p";
    flg = parsing(8, arg, t_file);
    ASSERT_EQUAL(0, flg->arg);
    ASSERT_EQUAL(0, flg->file);
    ASSERT_EQUAL(1, flg->print);
    free(t_file);
}
