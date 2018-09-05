#include <stdio.h>
#define L_MAX 46      //Maximo de letras por palabra
#define TERM '\0'      //Terminador

void comparer (char arr1 [L_MAX], char arr2 [L_MAX]);


void comparer (char fuente [L_MAX], char copia [L_MAX])
{
    char *word2 = fuente;
    for ( ; *word2 != TERM; word2++)
    {
        char *word1 = copia;
        int finder;
        int counter;
        for (finder=0, counter=0; counter<L_MAX; counter++, word1++)
        {
            if (*word2 == *word1)
            {
                *word1 = 0;
                finder++;
                counter = L_MAX-1;
            }
        }
        if (finder != 1)
        {
            printf("Error, la letra %c no fue encontrada.\n",*word2);
        }
    }
    printf ("Las letras son suficientes para escribir la palabra deseada.");
}
