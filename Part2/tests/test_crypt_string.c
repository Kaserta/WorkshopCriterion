/*
** EPITECH PROJECT, 2019
** cesarCypher
** File description:
** test_get_size_file
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <signal.h>
#include "cesar.h"

TestSuite(crypt_string,
.init = NULL,
.fini = NULL,
.disabled = 0,
.description = "Test the function: crypt_string.",
.timeout = 0);

Test(crypt_string, NULL_Entry,
.description = "NULL parameters.")
{
    cr_assert_fail();
}

Test(crypt_string, BAD_Entry,
.description = "Good parameter.", .signal = SIGSEGV)
{
    cr_assert_fail();
}

Test(crypt_string, GOOD_Entry,
.description = "Good parameter.")
{
    cr_assert_fail();
}