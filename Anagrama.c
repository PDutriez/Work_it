#include <stdio.h>
#define L_MAX 46      //Maximo de letras por palabra
#define TERM 0      //Terminador
void comparer (char arr1 [L_MAX], char arr2 [L_MAX]); //Funcion que compara ambas palabras
int arr_init (char input, char arr1 [L_MAX],  char arr2 [L_MAX]); //Funcion que crea los arreglos de las palabras


int main (void)
{
    char fuente [L_MAX]; //Arreglo para la segunda palabra
    char copia [L_MAX]; //Arreglo para la primer palabra
    char input;
    while((input=getchar()) != EOF)
    {
    if(arr_init(input,copia,fuente))
    {
      printf("Para formar la palabra %s, las letras de %s ",fuente,copia);
      comparer (fuente,copia);
    }
    }
  return 0;
}




//Funciones

int arr_init (char input,char arr1 [L_MAX], char arr2 [L_MAX]) //Funcion que crea los arreglos de las palabras
{
    char *pointer;
    char mycopy = input;
    int error = 1; //Variable para indicar error
    pointer = arr1;
    for( ;mycopy != '\n';++pointer,(mycopy=getchar()))
    {
      if((mycopy <= 'z') && (mycopy >= 'a'))
      {
        mycopy-= 'a' - 'A'; //Convertimos las minusculas en mayusculas para asi tener el mismo tipo de letras
        *pointer= mycopy; //Guardamos el caracter
      }
      else if(mycopy == '/')
      {
          *pointer = TERM; //Ponemos un terminador
          pointer = arr2-1; //Cambiamos de arreglo
      }
      else if((mycopy <= 'Z') && (mycopy >= 'A'))
      {
        *pointer=mycopy; //Guardamos el caracter
      }
      else
      {
        printf("el caracter '%c' no es una letra. \n \n", mycopy);
        error = 0;
      }
    }
    *pointer=TERM;
    return error;
}

void comparer (char arr1 [L_MAX], char arr2 [L_MAX])   //Chequea si es posible escribir la segunda palabra con las letraso de la primera
{
    char *word2, *word1;                                 //Pointer a la segunda palabra
    int finder, counter;
    word2  = arr1;
    for ( ;*word2 != TERM; word2++)
    {
        word1 = arr2;                                  //Pointer a la primera palabra
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
            printf("son insuficientes, la letra %c no fue encontrada.\n \n",*word2);
            *(word2+1)=TERM;          //Le indicamos al for principa que no es necesario seguir analizando
        }
    }
    if(finder == 1)                             //En caso de que se haya encontrado, finder es igual a 1
    printf ("son suficientes para poder escribirla.\n \n");
}
