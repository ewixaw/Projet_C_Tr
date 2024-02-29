/*
 * E89 Pedagogical & Technical Lab
 * project:     Tr
 * created on:  2024-01-10 - 11:17 +0100
 * 1st author:  maxime.franchomme - maxime.franchomme
 * description: suppr function of Tr
 */

#include <unistd.h>
#include <stdlib.h>
#include "../include/tr.h"

static void delete(const char *to_delete, char *msg)
{
    int nb;

    while (msg[0] != '\0') {
        nb = find_char_index(msg, to_delete);
        if (nb != 0) {
            write(1, msg, nb);
        }
        msg = msg + nb + 1;
    }
}

static int tr_suppr_loop(const char *to_delete, char *buffer)
{
    int size_read;

    size_read = read(0, buffer, 50);
    if (size_read == -1) {
        return (3);
    }
    while (size_read != 0) {
        buffer[size_read] = '\0';
        delete(to_delete, buffer);
        size_read = read(0, buffer, 50);
        if (size_read == -1) {
            return (3);
        }
    }
    free(buffer);
    return (0);
}

int tr_suppr(const char *to_delete)
{
    char *buffer;

    buffer = malloc(sizeof(char) * 51);
    if (!buffer) {
        return (2);
    }
    stu_memset(buffer, 51);
    return (tr_suppr_loop(to_delete, buffer));
}
