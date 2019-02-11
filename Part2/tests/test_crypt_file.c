/*
** EPITECH PROJECT, 2019
** cesarCypher
** File description:
** test_get_size_file
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "cesar.h"

TestSuite(crypt_file,
.init = cr_redirect_stderr,
.fini = NULL,
.disabled = 0,
.description = "Test the function: crypt_file.",
.timeout = 2);

Test(crypt_file, NULL_File_NULL_content,
.description = "NULL parameters.")
{
    cr_assert_fail();
}

Test(crypt_file, BAD_File_NULL_content,
.description = "Bad parameter.")
{
    cr_assert_fail();
}

Test(crypt_file, BAD_File_BAD_content,
.description = "Bad parameter.", .init = NULL)
{
    cr_assert_fail();
}

Test(crypt_file, GOOD_File_NULL_content,
.description = "NULL parameters.")
{
    cr_assert_fail();
}

Test(crypt_file, GOOD_File_GOOD_content,
.description = "NULL parameters.", .init = NULL)
{
    cr_assert_fail();
}