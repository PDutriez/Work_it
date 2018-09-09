#include <stdio.h>
#define L_MAX 46      //Maximo de letras por palabra
#define TERM '\0'      //Terminador
void comparer (char arr1 [L_MAX], char arr2 [L_MAX]);
void arr_init (void);


int main (void)
{
    char fuente [L_MAX];
    char copia [L_MAX];
    arr_init;
    comparer (char fuente [L_MAX], char copia [L_MAX]);
    return 0;
}




//Funciones

void arr_init (void)                 //Recibe por teclado las palabras y las guarda en arreglos
{
    char letter = getchar ();       //Variable para recibir el input del teclado
    char *pointer = copia;         //Puntero para la copia de los arreglos
    while (letter != '/' && (letter >= 'a') && (letter <='z'))
    {                               //Copia la primera palabra hasta percibir el '/'
        *pointer = letter;          //Y paulatinamente la guarda en un arreglo
        letter = getchar ()
        pointer++;
    }

    pointer = fuente;              //Apunta el puntero al nuevo arreglo
    letter = getchar ();
    while (letter != '\n' && (letter >= 'a') && (letter <='z'))
    {                             //Copia la segunda palabra hasta llegar al '\n'
        *pointer = letter;        //Y se guarda en el segundo arreglo
        letter = getchar ()
        pointer++;
    }
    return 0;
}



void comparer (char fuente [L_MAX], char copia [L_MAX])   //Chequea si es posible escribir
{                                                         //la segunda palabra con las letras
    char *word2 = fuente;                                 //de la primera
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
