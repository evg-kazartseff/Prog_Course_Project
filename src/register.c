#include "register.h"

int toLowCase_ru(char *str, char **out)
{
    size_t n = 2;
    char *buf_RU =
        "АБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ";
    char *buf_ru =
        "абвгдеёжзийклмнопрстуфхцчшщъыьэюя";
    char *tmp = malloc(strlen(str) * sizeof(char));
    int i = 0;
    int cmp;
    while (buf_RU[i] != '\0') {
        cmp = strncmp(str, &buf_RU[i], n);
        if (cmp == 0) {
            memmove(tmp, &buf_ru[i], n);
            tmp[2] = '\0';
            strcat(tmp, &str[2]);
            *out = tmp;
            return 1;
        }
        i += 2;
    }
    return 0;
}

void toHighCase_en(char *str, char **out, int reg)
{
    char *tmp = malloc(strlen(str) * sizeof(char));
    strcpy(tmp, str);
    if (reg == 1) {
        if (tmp[0] >= 'a' && tmp[0] <= 'z') {
            tmp[0] -= 'a' - 'A';
        }
        *out = tmp;
    } else
        *out = tmp;
}

void toLowCase_en(char *str, char **out)
{
    char *tmp = malloc(strlen(str) * sizeof(char));
    strcpy(tmp, str);
    if (tmp[0] >= 'A' && tmp[0] <= 'Z') {
        tmp[0] += 'a' - 'A';
        *out = tmp;
    } else
        *out = tmp;
}
