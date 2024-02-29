/*
 * E89 Pedagogical & Technical Lab
 * project:     Tr
 * created on:  2023-12-15 - 12:09 +0100
 * 1st author:  maxime.franchomme - maxime.franchomme
 * description: normal tr function
 */

#include <stdlib.h>
#include <unistd.h>

static char *change(const char *to_replace, const char *substitues,
                    char *msg)
{
    int cnt1;
    int cnt2;

    cnt1 = 0;
    cnt2 = 0;
    while (msg[cnt1] != '\0') {
        while (to_replace[cnt2] != '\0') {
            if (to_replace[cnt2] == msg[cnt1]) {
                msg[cnt1] = substitues[cnt2];
            }
            cnt2 = cnt2 + 1;
        }
        cnt1 = cnt1 + 1;
        cnt2 = 0;
    }
    return (msg);
}

int tr_simple(const char *to_replace, const char *substitutes)
{
    int size_read;
    char *buffer;

    buffer = malloc(sizeof(char) * 51);
    if (!buffer) {
        return (2);
    }
    size_read = read(0, buffer, 50);
    if (size_read == -1) {
        return (3);
    }
    while (size_read != 0) {
        buffer[size_read] = '\0';
        change(to_replace, substitutes, buffer);
        write(1, buffer, size_read);
        size_read = read(0, buffer, 50);
        if (size_read == -1) {
            return (3);
        }
    }
    free(buffer);
    return (0);
}
