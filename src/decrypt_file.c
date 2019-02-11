/*
** EPITECH PROJECT, 2019
** cesarCypher
** File description:
** crypt_file
*/
/**
* \file
* \brief Set of function to decrypt the file content.
*/

#include "cesar.h"

/**
* \brief This function will use a key to decrypt a string, the algorythm used is the cesar.
* \param[in/out] to_decrypt is the string who will be decrypted.
    - to_decrypt cannot be NULL.
    - to_decrypt must be an alterable variable.
* \return Return the decrypted string.
*/
char *decrypt_string(char *to_decrypt)
{
    const uint8_t key = -3;
    char ch = '\0';

    if (!to_decrypt)
        return NULL;
    for (size_t i = 0; to_decrypt[i] != '\0'; ++i) {
        ch = to_decrypt[i];
        if (ch >= 'a' && ch <= 'z') {
            ch = ch + key;
            if (ch < 'a')
                ch = ch - 'a' + 'z' + 1;
            to_decrypt[i] = ch;
        } else if (ch >= 'A' && ch <= 'Z') {
            ch = ch + key;
            if (ch < 'A')
                ch = ch - 'A' + 'Z' + 1;
            to_decrypt[i] = ch;
        }
    }
    return (to_decrypt);
}

/**
* \brief Change the content of a crypted file with the decrypted content using
the decrypt_string function.
* \param[in] file_name is the path to the crypted file.
* \param[in] file_content the content of the file.
* \return int32_t
        - ON ERROR : call pexit_failure with "safe_open error N" as parameter
 where N is the number of the error and return -1.
        - ON SUCCESS : return 0.
*/
int32_t decrypt_file(const char *file_name, char *file_content)
{
    int32_t error = 0;
    int32_t fd = 0;

    if (file_name == NULL || file_content == NULL)
        return pexit_failure("decrypt_file error 1");
    fd = safe_open(file_name, O_WRONLY | O_TRUNC);
    if (fd == -1)
        return pexit_failure("decrypt_file error 2");
    file_content = decrypt_string(file_content);
    error = write(fd, file_content, strlen(file_content));
    if (error <= 0)
        return pexit_failure("decrypt_file error 3");
    error = safe_close(fd);
    if (error == -1)
        return pexit_failure("decrypt_file error 4");
    return (EXIT_SUCCESS);
}