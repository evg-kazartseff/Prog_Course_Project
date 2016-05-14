#include "ctest.h"
#include "../src/register.h"

CTEST(register, toLowCase_ru_1)
{
    char *out = NULL;
    int rez = toLowCase_ru("Тест", &out);
    ASSERT_STR("тест", out);
    ASSERT_EQUAL(1, rez);
    free(out);
}

CTEST(register, toLowCase_ru_2)
{
    char *out = NULL;
    int rez = toLowCase_ru("тест", &out);
    ASSERT_NULL(out);
    ASSERT_EQUAL(0, rez);
    free(out);
}

CTEST(register, toLowCase_en_1)
{
    char *out = NULL;
    toLowCase_en("Test", &out);
    ASSERT_NOT_NULL(out);
    ASSERT_STR("test", out);
    free(out);
}

CTEST(register, toLowCase_en_2)
{
    char *out = NULL;
    toLowCase_en("test", &out);
    ASSERT_NOT_NULL(out);
    ASSERT_STR("test", out);
    free(out);
}

CTEST(register, toHighCase_en_1)
{
    char *out = NULL;
    toHighCase_en("test", &out, 1);
    ASSERT_NOT_NULL(out);
    ASSERT_STR("Test", out);
    free(out);
}

CTEST(register, toHighCase_en_2)
{
    char *out = NULL;
    toHighCase_en("test", &out, 0);
    ASSERT_NOT_NULL(out);
    ASSERT_STR("test", out);
    free(out);
}

CTEST(register, toHighCase_en_3)
{
    char *out = NULL;
    toHighCase_en("Test", &out, 1);
    ASSERT_NOT_NULL(out);
    ASSERT_STR("Test", out);
    free(out);
}

CTEST(register, toHighCase_en_4)
{
    char *out = NULL;
    toHighCase_en("Test", &out, 0);
    ASSERT_NOT_NULL(out);
    ASSERT_STR("Test", out);
    free(out);
}
