/*
** EPITECH PROJECT, 2017
** Test_criterion
** File description:
** Test de foo
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "cesar.h"

TestSuite(safe_close,
.init = cr_redirect_stderr,
.fini = NULL,
.disabled = 0,
.description = "Test the function: safe_close.",
.timeout = 2);

Test(safe_close, BAD_Entry,
.description = "Bad file descriptor.")
{
    int32_t error = 0;

    errno = 0;
    error = safe_close(-1);
    fflush(stderr);
    cr_stderr_match_str("safe_close: Bad file descriptor\n");
    cr_assert_eq(error, -1);
}

Test(safe_close, GOOD_Entry,
.description = "Valid file descriptor.")
{
    int32_t error = 0;
    int32_t fd = 0;

    errno = 0;
    fd = safe_open("./tests/FileTest/IExist.txt", 0);
    if (fd > 0)
        error = safe_close(fd);
    cr_assert_eq(error, 0);
}