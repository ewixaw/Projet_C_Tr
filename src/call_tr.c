/*
 * E89 Pedagogical & Technical Lab
 * project:     Tr
 * created on:  2024-01-10 - 11:46 +0100
 * 1st author:  maxime.franchomme - maxime.franchomme
 * description: call_tr function
 */

#include "../include/tr.h"

static int call_tr_sub1(int ac, char **av)
{
    char *not_opt_txt;

    if (has_opt(ac, av, 'd')) {
        not_opt_txt = not_opt(ac, av);
        if (!not_opt_txt) {
            return (1);
        }
        change_spe_chars(not_opt_txt);
        if (has_opt(ac, av, 'c')) {
            return (tr_cons(not_opt_txt));
        } else {
            return (tr_suppr(not_opt_txt));
        }
    } else {
        change_spe_chars(av[1]);
        change_spe_chars(av[2]);
        if (stu_strlen(av[1]) != stu_strlen(av[2])) {
            return (1);
        } else {
            return (tr_simple(av[1], av[2]));
        }
    }
}

static int test_params(int ac, char **av)
{
    int cnt1;
    int cnt2;

    cnt1 = 1;
    cnt2 = 0;
    while (cnt1 < ac) {
        if (av[cnt1][0] != '-') {
            cnt2 = cnt2 + 1;
        } else if (av[cnt1][1] != 'c' && av[cnt1][1] != 'd') {
            cnt2 = cnt2 + 1;
        }
        cnt1 = cnt1 + 1;
    }
    return (cnt2);
}

static int call_tr_sub2(int ac, char **av)
{
    char *not_opt_txt;

    if (test_params(ac, av) != 1) {
        return (1);
    }
    if (has_opt(ac, av, 'd')) {
        if (has_opt(ac, av, 'c')) {
            not_opt_txt = not_opt(ac, av);
            if (!not_opt_txt) {
                return (1);
            }
            change_spe_chars(not_opt_txt);
            return (tr_cons(not_opt_txt));
        }
        return (1);
    }
    return (1);
}

int call_tr(int ac, char **av)
{
    int res;

    if (ac == 3) {
        res = call_tr_sub1(ac, av);
    } else if (ac == 4) {
        res = call_tr_sub2(ac, av);
    } else {
        gest_erreurs(1);
        return (1);
    }
    if (res != 0) {
        gest_erreurs(res);
    }
    return (res);
}
