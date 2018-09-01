#include<stdio.h>
#define SIZE 8                                    //Tamaño de la matriz

char universe [SIZE] [SIZE];
char future [SIZE] [SIZE];

void deadoralive (int arr1[MAX][MAX],int arr2[MAX][MAX])                           //Esta función revisa las células y las actualiza en una matriz provisoria
{
    int col;                                      //Puntero para columnas en la matriz
    int row;                                      //Puntero para filas en la matriz
    for (row=inicio; row<(SIZE-inicio); row++)              //Consecituivamente se desplazará en un arreglo menor al original ya que los bordes no se modifican
    {
        for (col=inicio; col<(SIZE-inicio); col++)
        {
            int y, x;                              //Se crean 2 variables provisorias como punteros auxiliares para revisar los alrededores de la célula
            int alive;                            //Se crea una variable local como contador para las células vivas que 'rodean' a la célula analizada

            for (y=row-1; y<row+2;y++)            //Ahora revisa cada célula adyacente y si están vivas incrementa el contador
            {
                for (x=col-1; x<col+2; x++)
                {
                    if ((arr1[y][x] == '*') && (y!=row || x!=col))
                    {                             //En caso de que x=col o y=row implica que se analiza la misma celula
                        alive++;
                    }
                }

            }
            if (arr1 [row] [col] == '*')      //Dependiendo de si la célula estaba originalmente viva o muerta se aplicarán distintos criterios dictados por las reglas
            {
                if (alive == 2 || alive == 3)
                {
                    arr2 [row] [col] = '*';
                }
                else
                {
                    arr2 [row] [col] = ' ';
                }
            }
            else                                  //En caso de estar nuerta debemos analizar si revive
            {
                if (alive == 3)
                {
                    arr2 [row] [col] = '*';     //La celula revive
                }
                else
                {
                    arr2 [row] [col] = ' ';   //La ccelula sigue muerta
                }

            }
                                                  //El proceso se repite para todas las células del arreglo interior
        }
    }
}
