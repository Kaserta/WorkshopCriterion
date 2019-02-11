/*
** EPITECH PROJECT, 2017
** Test_criterion
** File description:
** Test de foo
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "cesar.h"

TestSuite(safe_open,
.init = cr_redirect_stderr,
.fini = NULL,
.disabled = 0,
.description = "Test the function: safe_open.",
.timeout = 2);

Test(safe_open, NULL_Entry,
.description = "Parameter NULL.")
{
    int32_t error = 0;

    errno = 0;
    error = safe_open(NULL, 0);
    fflush(stderr);
    cr_stderr_match_str("safe_open error 1");
    cr_assert_eq(error, -1);
}

Test(safe_open, BAD_File,
.description = "Inexistant file.")
{
    int32_t error = 0;

    errno = 0;
    error = safe_open("IDontExist.txt", 0);
    fflush(stderr);
    cr_stderr_match_str("safe_open error 2: No such file or directory\n");
    cr_assert_eq(error, -1);
}

Test(safe_open, GOOD_Entry,
.description = "Good file.")
{
    int32_t error = 0;

    errno = 0;
    error = safe_open("./tests/FileTest/IExist.txt", 0);
    cr_assert(error > 0);
    (void)safe_close(error);
}