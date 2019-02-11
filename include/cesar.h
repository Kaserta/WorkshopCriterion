/*
** EPITECH PROJECT, 2019
** cesarCypher
** File description:
** cesar
*/
/**
* \file
* \brief Header file for the cesarDecrypt.
*/
/*! \mainpage Workshop Criterion
 *
 * \section intro_sec Introduction
 *
 * This workshop is made to make you understand the interest of using unit test
 * don't be shy ask us help if needed.
 *
 * Complete and create more test if you can.
 *
 * Read carefully the documentation, everything is wrote in it.
 */

#ifndef CESAR_H_
#define CESAR_H_

    #include <fcntl.h>
    #include <unistd.h>
    #include <stdint.h>
    #include <stdio.h>
    #include <string.h>
    #include <stdlib.h>

/* src/crypt_file.c */
char *decrypt_string(char *to_crypt);
int32_t decrypt_file(const char *file_name, char *file_content);

/* src/file_manager.c */
int32_t safe_open(const char *file_name, uint32_t open_type);
int32_t safe_close(int32_t fd);
size_t get_size_file(const char *file_name);
int32_t get_file_content(const char *file_name, size_t size_file_content, char **file_content);

/* src/main.c */
int32_t pexit_failure(const char *func_name);

#endif /* !CESAR_H_ */