/*
 * E89 Pedagogical & Technical Lab
 * project:     Tr
 * created on:  2024-01-10 - 11:43 +0100
 * 1st author:  maxime.franchomme - maxime.franchomme
 * description: main for Tr project
 */

#include "../include/tr.h"

int main(int ac, char **av)
{
    if (has_opt(ac, av, 'h')) {
        helper(av[0]);
        return (0);
    } else {
        call_tr(ac, av);
    }
}
