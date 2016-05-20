set(CF_HEADERS dictionary.h bstree.h register.h token_replacement.h parsing.h)
set(CF_SOURCES dictionary.c bstree.c register.c token_replacement.c parsing.c main.c)

add_executable(${PROJECT_NAME} ${CF_HEADERS} ${CF_SOURCES})
target_link_libraries(${PROJECT_NAME} m)
