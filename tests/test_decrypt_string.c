/*
** EPITECH PROJECT, 2019
** cesarCypher
** File description:
** test_get_size_file
*/
/**
* \file
* \brief Unit test for the function decrypt_string.
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <signal.h>
#include "cesar.h"

TestSuite(decrypt_string,
.init = NULL,
.fini = NULL,
.disabled = 0,
.description = "Test the function: decrypt_string.",
.timeout = 0);

Test(decrypt_string, NULL_Entry,
.description = "NULL parameters.")
{
    char *return_value = NULL;

    return_value =  decrypt_string(NULL);
    cr_assert_null(return_value);
}

Test(decrypt_string, BAD_Entry,
.description = "Good parameter.", .signal = SIGSEGV)
{
    char *return_value = "i am a string";

    return_value = decrypt_string(return_value);
}

Test(decrypt_string, GOOD_Entry,
.description = "Good parameter.")
{
    char *return_value = strdup("mh vxlv xq ilfklhu gh whvw txl yd hwuh fkliiuhu.\nXq chssholq hvw xq déurvwdw gh wbsh gluljhdeoh uljlgh.");

    return_value = decrypt_string(return_value);
    cr_assert_not_null(return_value);
    cr_assert_str_eq(return_value, "je suis un fichier de test qui va etre chiffrer.\nUn zeppelin est un aérostat de type dirigeable rigide.");
}