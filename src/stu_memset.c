/*
 * E89 Pedagogical & Technical Lab
 * project:     Tr
 * created on:  2024-01-10 - 11:39 +0100
 * 1st author:  maxime.franchomme - maxime.franchomme
 * description: stu_memset function needed for the project
 */

void stu_memset(char *buffer, const int size)
{
    int cnt;

    cnt = 0;
    while (cnt < size) {
        buffer[cnt] = '\0';
        cnt = cnt + 1;
    }
}
