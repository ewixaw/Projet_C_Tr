/*
 * E89 Pedagogical & Technical Lab
 * project:     Tr
 * created on:  2024-01-10 - 11:41 +0100
 * 1st author:  maxime.franchomme - maxime.franchomme
 * description: stu_strlen function needed for the project
 */

unsigned int stu_strlen(const char *str)
{
    int counter;

    counter = 0;
    while (str[counter] != '\0') {
        counter = counter + 1;
    }
    return (counter);
}
