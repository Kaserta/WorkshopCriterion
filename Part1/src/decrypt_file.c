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
}

/**
* \brief Change the content of a crypted file with the decrypted content using
the decrypt_string function.
* \param[in] file_name is the path to the crypted file.
* \param[in] file_content the content of the file.
* \return int32_t
        - ON ERROR : call pexit_failure with "decrypt_file error N" as parameter
 where N is the number of the error and return -1.
        - ON SUCCESS : return 0.
*/
int32_t decrypt_file(const char *file_name, char *file_content)
{
}