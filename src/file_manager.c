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
    int32_t fd = 0;

    if (file_name == NULL || strlen(file_name) == 0)
        return pexit_failure("safe_open error 1");
    fd = open(file_name, open_type);
    if (fd == -1)
        return pexit_failure("safe_open error 2");
    return fd;
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
    int32_t error = 0;

    error = close(fd);
    if (error == -1)
        return pexit_failure("safe_close");
    return EXIT_SUCCESS;
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
    struct stat stat_file = {0};
    int32_t error = 0;

    error = stat(file_name, &stat_file);
    if (error == -1) {
        pexit_failure("get_size_file error");
        return 0;
    }
    return stat_file.st_size;
}

/**
* \brief Get the content of the file in a buffer.
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
    int32_t bytes_read = 0;
    int32_t fd = 0;

    fd = safe_open(file_name, O_RDONLY);
    if (fd == -1 || !file_content || *file_content != NULL || size_file_content == 0)
        return (pexit_failure("get_file_content error"));
    *file_content = malloc((size_file_content + 1) * sizeof(char));
    if (file_content == NULL)
        return pexit_failure("get_file_content error 2");
    for (size_t i = 0; i <= size_file_content; i++)
        (*file_content)[i] = '\0';
    bytes_read = read(fd, *file_content, size_file_content);
    if (bytes_read == -1)
        return pexit_failure("get_file_content error 3");
    fd = safe_close(fd);
    if (fd == -1)
        return (-1);
    return EXIT_SUCCESS;
}