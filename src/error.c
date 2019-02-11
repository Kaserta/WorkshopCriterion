/*
** EPITECH PROJECT, 2019
** cesarCypher
** File description:
** error
*/
/**
* \file
* \brief Error function.
*/

#include <errno.h>
#include "cesar.h"

/**
* \brief Print an error, after a call to this function the program should finish.
        - errno > 0: print using perror.
        - errno <= 0: print using dprintf.
* \param[in] func_name is the string corresponding to the function where the
error occured.
* \return int32_t return -1.
*/
int32_t pexit_failure(const char *func_name)
{
    if (!func_name)
        return (-1);
    if (errno)
        perror(func_name);
    else
        dprintf(2, "%s\n",func_name);
    return (-1);
}