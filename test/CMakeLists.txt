set(CF_TEST_HEADERS ctest.h ../src/bstree.h ../src/register.h ../src/token_replacement.h ../src/parsing.h)
set(CF_TEST_SOURCES main.c
					../src/bstree.c
					../src/parsing.c
					../src/token_replacement.c
					../src/register.c
					parsing_test.c
					bstree_test.c
					register_test.c
					token_replacement_test.c
					)

add_executable(${PROJECT_NAME}Test ${CF_TEST_HEADERS} ${CF_TEST_SOURCES})
