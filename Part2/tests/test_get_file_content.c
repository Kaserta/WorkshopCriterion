/*
** EPITECH PROJECT, 2019
** cesarCypher
** File description:
** test_get_size_file
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "cesar.h"

TestSuite(get_file_content,
.init = cr_redirect_stderr,
.fini = NULL,
.disabled = 0,
.description = "Test the function: get_file_content.",
.timeout = 2);

Test(get_file_content, NULL_Entry,
.description = "NULL parameters.")
{
    int32_t error = 0;

    errno = 0;
    error =  get_file_content(NULL, 0, NULL);
    fflush(stderr);
    cr_stderr_match_str("safe_open error 1\nget_file_content error\n");
    cr_assert_eq(error, -1);
}

Test(get_file_content, BAD_File_BAD_Size_BAD_buffer,
.description = "Good and bad parameter.")
{
    int32_t error = 0;

    errno = 0;
    error = get_file_content("./tests/FileTest/IDontExist.txt", 0, NULL);
    fflush(stderr);
    cr_stderr_match_str("safe_open error 2: No such file or directory\nget_file_content error: No such file or directory\n");
    cr_assert_eq(error, -1);
}

Test(get_file_content, GOOD_File_BAD_Size_BAD_buffer,
.description = "Good and bad parameter.")
{
    int32_t error = 0;

    errno = 0;
    error = get_file_content("./tests/FileTest/ImNotCrypted.txt", 0, NULL);
    fflush(stderr);
    cr_stderr_match_str("get_file_content error\n");
    cr_assert_eq(error, -1);
}

Test(get_file_content, GOOD_File_BAD_Size_GOOD_buffer,
.description = "Good and bad parameter.")
{
    int32_t error = 0;
    char *buffer = NULL;

    errno = 0;
    error = get_file_content("./tests/FileTest/ImNotCrypted.txt", 0, &buffer);
    fflush(stderr);
    cr_stderr_match_str("get_file_content error\n");
    cr_assert_eq(error, -1);
}

Test(get_file_content, GOOD_File_GOOD_Size_BAD_buffer,
.description = "Good and bad parameter.")
{
    int32_t error = 0;

    errno = 0;
    error = get_file_content("./tests/FileTest/ImNotCrypted.txt",
                get_size_file("./tests/FileTest/ImNotCrypted.txt"), NULL);
    fflush(stderr);
    cr_stderr_match_str("get_file_content error\n");
    cr_assert_eq(error, -1);
}

Test(get_file_content, GOOD_File_GOOD_Size_GOOD_buffer,
.description = "Good parameter.")
{
    int32_t error = 0;
    char *buffer = NULL;
    FILE *stream = NULL;

    errno = 0;
    error = get_file_content("./tests/FileTest/ImNotCrypted.txt",
                get_size_file("./tests/FileTest/ImNotCrypted.txt"), &buffer);
    fflush(stderr);
    stream = fopen("./tests/FileTest/ImNotCrypted.txt", "r");
    cr_file_match_str(stream, buffer);
    free(buffer);
    cr_assert_eq(error, 0);
}