#include <stdio.h>
#define L_MAX 46      //Maximo de letras por palabra
#define TERM '\0'      //Terminador
void comparer (char arr1 [L_MAX], char arr2 [L_MAX]);
void arr_init (void);


int main (void)
{
    char fuente [L_MAX]; //Arreglo para la segunda palabra
    char copia [L_MAX]; //Arreglo para la primer palabra
    char *pointer;
    pointer = copia;
    for( ;(input=getchar()) != EOF; ++pointer)
    {
    arr_init(input);
    printf("Entre las palabras %s y %s \n",copia, fuente);
    comparer (char fuente [L_MAX], char copia [L_MAX]);
    }

}




//Funciones

void arr_init (char input)
{
    char *pointer;
    pointer = copia;
    for( ;input != '\n';++pointer,(input=getchar()))
    {
      if((input <= 'z') || (input >= 'a'))
      input-= 'a' - 'A'; //Convertimos las minusculas en mayusculas para asi tener el mismo tipo de letras
      *pointer= input; //Guardamos el caracter
      else if(input == '/')
      {
          *pointer = TERM; //Ponemos un terminador
          pointer = fuente; //Cambiamos de arreglo
      }
      else if((input <= 'z') || (input >= 'a'))
      *pointer=input; //Guardamos el caracter
    }
}

void comparer (char fuente [L_MAX], char copia [L_MAX])   //Chequea si es posible escribir la segunda palabra con las letraso de la primera
{
    char *word2, *word1;                                 //Pointer a la segunda palabra
    int finder, counter;
    word2  = fuente;
    for ( ;*word2 != TERM; word2++)
    {
        word1 = copia;                                  //Pointer a la primera palabra
        for (finder=0, counter=0; counter<L_MAX; counter++, word1++)
        {
            if (*word2 == *word1)
            {
                *word1 = 0;
                finder++;
                counter = L_MAX-1;
            }
            if(*word1== TERM)
            {

            }
        }
        if (finder != 1)                          //En caso de que no sea uno implica que no se encontro la letra
        {
            printf("Error, la letra %c no fue encontrada.\n",*word2);
            *(word2+1)=TERM;          //Le indicamos al for principa que no es necesario seguir analizando
        }
    }
    if(finder == 1)                             //En caso de que se haya encontrado, finder es igual a 1
    printf ("Las letras son suficientes para escribir la palabra deseada.\n");
}
