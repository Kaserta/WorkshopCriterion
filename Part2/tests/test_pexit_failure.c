/*
** EPITECH PROJECT, 2017
** Test_criterion
** File description:
** Test de foo
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "cesar.h"

TestSuite(pexit_failure,
.init = cr_redirect_stderr,
.fini = NULL,
.disabled = 0,
.description = "Test the function: pexit_failure.",
.timeout = 2);

Test(pexit_failure, NULL_Entry_Errno_zero,
.description = "Parameter NULL.", .init = NULL)
{
    int32_t error = 0;

    errno = 0;
    error = pexit_failure(NULL);
    fflush(stderr);
    cr_assert_eq(error, -1);
}

Test(pexit_failure, GOOD_Entry_Errno_zero,
.description = "Good parameter.")
{
    int32_t error = 0;

    errno = 0;
    error = pexit_failure("func_bad_work error");
    fflush(stderr);
    cr_stderr_match_str("func_bad_work error\n");
    cr_assert_eq(error, -1);
}

Test(pexit_failure, GOOD_Entry_Errno_sup_zero,
.description = "Good parameter, errno modification.")
{
    int32_t error = 0;

    errno = EREMOTE;
    error = pexit_failure("func_bad_work error");
    fflush(stderr);
    cr_stderr_match_str("func_bad_work error: Object is remote\n");
    cr_assert_eq(error, -1);
}