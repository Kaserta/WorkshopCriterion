/*
** EPITECH PROJECT, 2019
** cesarCypher
** File description:
** test_get_size_file
*/
/**
* \file
* \brief Unit test for the function get_size_file.
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "cesar.h"

TestSuite(get_size_file,
.init = cr_redirect_stderr,
.fini = NULL,
.disabled = 0,
.description = "Test the function: get_size_file.",
.timeout = 2);

Test(get_size_file, NULL_Entry,
.description = "NULL parameter.")
{
    size_t error = 0;

    errno = 0;
    error = get_size_file(NULL);
    fflush(stderr);
    cr_stderr_match_str("get_size_file error: No such file or directory\n");
    cr_assert_eq(error, 0);
}

Test(get_size_file, BAD_File,
.description = "bad file parameter.")
{
    size_t error = 0;

    errno = 0;
    error = get_size_file("./tests/FileTest/IDontExist.txt");
    fflush(stderr);
    cr_stderr_match_str("get_size_file error: No such file or directory\n");
    cr_assert_eq(error, 0);
}

Test(get_size_file, GOOD_File,
.description = "Good parameter.")
{
    size_t error = 0;

    errno = 0;
    error = get_size_file("./tests/FileTest/IExist.txt");
    fflush(stderr);
    cr_stderr_match_str("get_size_file error: No such file or directory\n");
    cr_assert(error > 0);
}