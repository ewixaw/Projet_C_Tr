/*
 * E89 Pedagogical & Technical Lab
 * project:     Tr
 * created on:  2024-01-10 - 12:20 +0100
 * 1st author:  maxime.franchomme - maxime.franchomme
 * description: not_opt function
 */

#include <stddef.h>

char *not_opt(int ac, char **av)
{
    int cnt;

    cnt = 1;
    while (cnt < ac) {
        if (av[cnt][0] != '-') {
            return (av[cnt]);
        }
        cnt = cnt + 1;
    }
    return (NULL);
}
