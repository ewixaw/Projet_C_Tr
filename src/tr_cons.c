/*
 * E89 Pedagogical & Technical Lab
 * project:     Tr
 * created on:  2024-01-10 - 11:24 +0100
 * 1st author:  maxime.franchomme - maxime.franchomme
 * description: cons function of Tr
 */

#include <unistd.h>
#include <stdlib.h>
#include "../include/tr.h"

static char *keep(const char *to_keep, char *msg)
{
    int nb;
    int cnt;
    char *new_buf;

    new_buf = malloc(sizeof(char) * (stu_strlen(msg) + 1));
    if (!new_buf) {
        return (NULL);
    }
    stu_memset(new_buf, (stu_strlen(msg) + 1));
    cnt = 0;
    while (msg[0] != '\0') {
        nb = find_char_index(msg, to_keep);
        msg = msg + nb;
        new_buf[cnt] = msg[0];
        msg = msg + 1;
        cnt = cnt + 1;
    }
    return (new_buf);
}

static int tr_cons_loop_sub(int *res, char *temp_buf1, char **all_text,
                            char *buffer)
{
    int size_read;
    char *temp_buf2;

    if (!temp_buf1) {
        *res = 2;
        size_read = 0;
    } else {
        temp_buf2 = *all_text;
        *all_text = strdupcat(*all_text, temp_buf1);
        free(temp_buf1);
        free(temp_buf2);
        size_read = read(0, buffer, 25);
        if (size_read == -1) {
            *res = 3;
        }
    }
    return (size_read);
}

static int tr_cons_loop(const char *to_keep, char *buffer)
{
    int size_read;
    int res;
    char *all_text;
    char *temp_buf1;

    size_read = read(0, buffer, 25);
    if (size_read == -1) {
        return (3);
    }
    res = 0;
    all_text = NULL;
    while (size_read > 0) {
        buffer[size_read] = '\0';
        temp_buf1 = keep(to_keep, buffer);
        size_read = tr_cons_loop_sub(&res, temp_buf1, &all_text,
                                     buffer);
    }
    write(1, all_text, stu_strlen(all_text));
    free(all_text);
    free(buffer);
    return (res);
}

int tr_cons(char *to_keep)
{
    char *buffer;

    buffer = malloc(sizeof(char) * 26);
    if (!buffer) {
        return (2);
    }
    stu_memset(buffer, 26);
    return(tr_cons_loop(to_keep, buffer));
}
