/*
** EPITECH PROJECT, 2019
** cesarCypher
** File description:
** cesar
*/
/**
* \file
* \brief Header file for cesarCypher.
*/

#ifndef CESAR_H_
#define CESAR_H_

    #include <sys/types.h>
    #include <sys/stat.h>
    #include <stdbool.h>
    #include <stdint.h>
    #include <fcntl.h>
    #include <stdio.h>
    #include <string.h>
    #include <stdlib.h>
    #include <unistd.h>
    #include <errno.h>

/* src/crypt_file.c */
char *crypt_string(char *to_crypt);
int32_t crypt_file(const char *file_name, char *file_content);

/* src/file_manager.c */
int32_t safe_open(const char *file_name, uint32_t open_type);
int32_t safe_close(int32_t fd);
size_t get_size_file(const char *file_name);
int32_t get_file_content(const char *file_name, size_t size_file_content, char **file_content);

/* src/main.c */
int32_t pexit_failure(const char *func_name);

#endif /* !CESAR_H_ */