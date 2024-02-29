/*
 * E89 Pedagogical & Technical Lab
 * project:     Tr
 * created on:  2024-01-10 - 11:38 +0100
 * 1st author:  maxime.franchomme - maxime.franchomme
 * description: fonction needed for the project
 */

int find_char_index(char *msg, const char *wanted)
{
    int cnt;
    int cnt2;

    cnt = 0;
    cnt2 = 0;
    while (msg[cnt] != '\0') {
        while (wanted[cnt2] != '\0') {
            if (msg[cnt] == wanted[cnt2]) {
                return (cnt);
            }
            cnt2 = cnt2 + 1;
        }
        cnt = cnt + 1;
        cnt2 = 0;
    }
    return (cnt);
}
