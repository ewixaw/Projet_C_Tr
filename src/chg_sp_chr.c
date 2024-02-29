/*
 * E89 Pedagogical & Technical Lab
 * project:     Tr
 * created on:  2024-01-10 - 12:32 +0100
 * 1st author:  maxime.franchomme - maxime.franchomme
 * description: change_spe_chars function
 */

#include "../include/tr.h"

void change_spe_chars(char *buffer)
{
    int cnt;
    int cnt2;
    int size;

    cnt = 0;
    size = stu_strlen(buffer);
    while (cnt < size) {
        if (buffer[cnt] == '\\' && buffer[cnt + 1] == 'n') {
            buffer[cnt] = '\n';
            cnt2 = cnt + 1;
            while (buffer[cnt2] != '\0') {
                buffer[cnt2] = buffer[cnt2 + 1];
                cnt2 = cnt2 + 1;
            }
        }
        cnt = cnt + 1;
    }
}
