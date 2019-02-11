/*
** EPITECH PROJECT, 2019
** cesarCypher
** File description:
** main
*/

#include "cesar.h"

int32_t main(int ac, char *av[])
{
    int32_t is_crypted = -1;
    char *file_content = NULL;
    char *file_name = NULL;
    size_t size_content_file = 0;

    if (ac != 2)
        return pexit_failure("main error");
    for (size_t i = 1; av[i] != NULL; i++) {
        file_name = av[i];
        if (strlen(file_name) > 0) {
            size_content_file = get_size_file(file_name);
            if (get_file_content(file_name, size_content_file, &file_content) == -1)
                return (EXIT_FAILURE);
            is_crypted = decrypt_file(file_name, file_content);
            if (is_crypted == -1)
                return (EXIT_FAILURE);
        } else
            is_crypted = pexit_failure("main error");
        if (file_content)
            free(file_content);
    }
    return ((is_crypted != -1) ? EXIT_SUCCESS : EXIT_FAILURE);
}