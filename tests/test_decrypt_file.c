/*
** EPITECH PROJECT, 2019
** cesarCypher
** File description:
** test_get_size_file
*/
/**
* \file
* \brief Unit test for the function decrypt_file.
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <signal.h>
#include "cesar.h"

TestSuite(decrypt_file,
.init = cr_redirect_stderr,
.fini = NULL,
.disabled = 0,
.description = "Test the function: decrypt_file.",
.timeout = 2);

Test(decrypt_file, NULL_File_NULL_content,
.description = "NULL parameters.")
{
    int32_t error = 0;

    errno = 0;
    error = decrypt_file(NULL, NULL);
    fflush(stderr);
    cr_stderr_match_str("decrypt_file error 1\n");
    cr_assert_eq(error, -1);
}

Test(decrypt_file, BAD_File_NULL_content,
.description = "Bad parameter.")
{
    int32_t error = 0;

    errno = 0;
    error = decrypt_file("./tests/FileTest/IDontExist.txt", NULL);
    fflush(stderr);
    cr_stderr_match_str("decrypt_file error 1\n");
    cr_assert_eq(error, -1);
}

Test(decrypt_file, BAD_File_BAD_content,
.description = "Bad parameter.", .init = NULL)
{
    int32_t error = 0;
    char *file_content = "";

    errno = 0;
    error = decrypt_file("./tests/FileTest/IDontExist.txt", file_content);
    fflush(stderr);
    cr_stderr_match_str("decrypt_file error 2\n");
    cr_assert_eq(error, -1);
}

Test(decrypt_file, GOOD_File_NULL_content,
.description = "NULL parameters.")
{
    int32_t error = 0;

    errno = 0;
    error = decrypt_file("./tests/FileTest/ImGonnaBeDecrypted.txt", NULL);
    fflush(stderr);
    cr_stderr_match_str("decrypt_file error 1\n");
    cr_assert_eq(error, -1);
}

Test(decrypt_file, GOOD_File_GOOD_content,
.description = "NULL parameters.", .init = NULL)
{
    size_t size_content_file = 0;
    int32_t error = 0;
    const char *file_name = "./tests/FileTest/ImGonnaBeDecrypted.txt";
    char *file_content = NULL;

    errno = 0;
    size_content_file = get_size_file(file_name);
    if (get_file_content(file_name, size_content_file, &file_content) == -1)
        cr_assert_fail();
    error = decrypt_file(file_name, file_content);
    cr_assert_eq(error, EXIT_SUCCESS);
    cr_assert_eq(errno, 0);
}