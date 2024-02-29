/*
 * E89 Pedagogical & Technical Lab
 * project:     Tr
 * created on:  2024-01-10 - 11:22 +0100
 * 1st author:  maxime.franchomme - maxime.franchomme
 * description: include file for Tr project
 */

#ifndef TR_H_
#define TR_H_

unsigned int stu_strlen(const char *str);
char *not_opt(int ac, char **av);
int has_opt(int ac, char **av, char str);
void change_spe_chars(char *buffer);
void stu_memset(char *buffer, const int size);
int find_char_index(char *msg, const char *wanted);
char *strdupcat(char *str1, char *str2);
void helper(char *name);
int tr_simple(const char *to_replace, const char *substitutes);
int tr_cons(char *to_keep);
int tr_suppr(const char *to_delete);
void gest_erreurs(int prob);
int call_tr(int ac, char **av);

#endif
