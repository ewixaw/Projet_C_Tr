/*
 * E89 Pedagogical & Technical Lab
 * project:     Tr
 * created on:  2024-01-10 - 11:30 +0100
 * 1st author:  maxime.franchomme - maxime.franchomme
 * description: helper of the Tr project
 */

#include <unistd.h>
#include "../include/tr.h"

void helper(char *name)
{
    char *str;

    str = " [OPTION]... STRING1 [STRING2]\n"
        "Translate or delete characters from standard input,"
        " writing\nto standard output.  STRING1 and STRING2"
        " specify arrays of\ncharacters ARRAY1 and ARRAY2 that control"
        " the action.\n\n"
        "  -c   use the complement of ARRAY1\n"
        "  -d   delete characters in ARRAY1, do not translate\n"
        "  -h   display this help and exit\n"
        "Translation occurs if -d is not given and both STRING1 and"
        " STRING2 appear\nand are of equal size.\n";
    write(1, "Usage: ", 7);
    write(1, name, stu_strlen(name));
    write(1, str, stu_strlen(str));
}
