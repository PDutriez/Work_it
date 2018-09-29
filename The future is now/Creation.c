#include "Creation.h"
#include <stdio.h>

int  inicio, tope;
char universe [MAX][MAX];
char future [MAX] [MAX];

void create(int n)                  //Creal la matriz elegida por el USUARIO
{                                   //Ademas de los punteros de la misma dentro de la amtriz original

    inicio=(MAX - n)/2;             //Se creal el inicio de la matriz a nostrar
    tope=MAX-inicio;                //Se creal el tope de la matriz a mostrar
    tope-=((n%2)?1:0);              //Al ser un numero inpar se trunca el valor y se agega un casillero falso
    deadoralive(universe,universe); //Al estar ambos arreglos con 0s lo que hacemos con esto llenarlo de...
    deadoralive(future,future);     //espacios para que tengan los requisitos del juego
    int i, j;                       //Variables punteros
    for(i=inicio ; i<tope ; ++i)
    {
      for(j=inicio ; j<tope ; j+=(n/2-1))
      universe[i][j]='*';
    }
    printf("Tamaño cargado correctamente, por favor aprete 'S' para iniciar\n");
}

int deadoralive (char arr1[MAX][MAX],char arr2[MAX][MAX])  //Esta función revisa las células y las actualiza en una matriz provisoria
{
    int col;                                               //Puntero para columnas en la matriz
    int row;                                               //Puntero para filas en la matriz
    int falive=0;                                          //Cantidad final de celulas vivas
    for (row=inicio; row<tope; row++)                      //Consecituivamente se desplazará en un arreglo menor al original ya que los bordes no se modifican
    {
        for (col=inicio; col<tope; col++)
        {
            int y, x;                                      //Se crean 2 variables provisorias como punteros auxiliares para revisar los alrededores de la célula
            int alive=0;                                   //Se crea una variable local como contador para las células vivas que 'rodean' a la célula analizada

            for (y=row-1; y<row+2;y++)                     //Ahora revisa cada célula adyacente y si están vivas incrementa el contador
            {
                for (x=col-1; x<col+2; x++)
                {
                    if ((arr1[y][x] == '*') && (y!=row || x!=col))
                    {                                      //En caso de que x=col o y=row implica que se analiza la misma celula
                        alive++;
                    }
                }

            }
            if (arr1[row][col] == '*')                     //Dependiendo de si la célula estaba originalmente viva o muerta se aplicarán distintos criterios dictados por las reglas
            {
                if (alive == 2 || alive == 3)
                {
                    arr2[row][col] = '*';
                    ++falive;
                }
                else
                {
                    arr2[row][col] = ' ';
                }
            }
            else                                           //En caso de estar nuerta debemos analizar si revive
            {
                if (alive == 3)
                {
                    arr2[row][col] = '*';                  //La celula revive
                    ++falive;
                }
                else
                {
                    arr2[row][col] = ' ';                  //La ccelula sigue muerta
                }

            }
                                                           //El proceso se repite para todas las células del arreglo interior
        }
    }
    return falive;                                         //Devolvemos la cantidad de celulas vivas en el nuevo mundo
}