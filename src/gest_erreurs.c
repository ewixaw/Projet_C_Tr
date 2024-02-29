/*
 * E89 Pedagogical & Technical Lab
 * project:     Tr
 * created on:  2024-01-10 - 12:37 +0100
 * 1st author:  maxime.franchomme - maxime.franchomme
 * description: gest_erreurs function
 */

#include <unistd.h>
#include "../include/tr.h"

void gest_erreurs(int prob)
{
    char *msg;

    if (prob == 1) {
        msg = "Il y a un problème avec les paramètres, veuillez les"
            " vérifier et\nrelancer le programme.\n";
    }
    if (prob == 2) {
        msg = "Il y a eu un problème avec malloc.\n";
    }
    if (prob == 3) {
        msg = "Il y a eu un problème avec read.\n";
    }
    write(1, msg, stu_strlen(msg));
}
