/*
** EPITECH PROJECT, 2019
** cesarCypher
** File description:
** file_manager
*/
/**
* \file
* \brief Function to manage file easily.
*/

#include <sys/types.h>
#include <sys/stat.h>
#include "cesar.h"

/**
* \brief Open a file with the open_type wanted, call pexit_failure if an error
occured.
* \param[in] file_name the path of the file to be open.
* \param[in] open_type how the file is open.
* \return int32_t
        - ON ERROR : call pexit_failure with "safe_open error N" as parameter
 where N is the number of the error and return -1.
        - ON SUCCESS : return the file descriptor.
*/
int32_t safe_open(const char *file_name, uint32_t open_type)
{
}

/**
* \brief Close a file descriptor, if an error occured the function call
 pexit_failure.
* \param[in] fd File descriptor that have to be closed.
* \return int32_t
        - ON ERROR : call pexit_failure with "safe_close" as parameter
 and return -1.
        - ON SUCCESS : return 0.
*/
int32_t safe_close(int32_t fd)
{
}

/**
* \brief Get the size of the file using the stat function.
* \param[in] file_name the path of the file to be open.
* \return size_t
        - ON ERROR : call pexit_failure with "get_size_file error" as parameter
 and return 0.
        - ON SUCCESS : return the size of the file.
*/
size_t get_size_file(const char *file_name)
{
}

/**
* \brief Get the content of the file in a buffer, using safe_open and
 safe_close function.
* \param[in] file_name the path of the file to be open.
* \param[in] size_file_content size of the content of the file.
* \param[out] file_content buffer filed up with the content of the file.
* \return int32_t
        - ON ERROR : call pexit_failure with "get_file_content error N"
 as parameter where N is the number of the error and return -1.
        - ON SUCCESS : return the file descriptor.
*/
int32_t get_file_content(const char *file_name, size_t size_file_content, char **file_content)
{
}