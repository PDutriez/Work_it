#include<stdio.h>
#define SIZE 8                                    //Tamaño de la matriz





char universe [SIZE] [SIZE];
char future [SIZE] [SIZE];

void deadoralive (void)                           //Esta función revisa las células y las actualiza en una matriz provisoria
{
    int col;                                      //Puntero para columnas en la matriz
    int row;                                      //Puntero para filas en la matriz
    for (row=1; row<(SIZE-1); row++)              //Consecituivamente se desplazará en un arreglo menor al original ya que los bordes no se modifican
    {
        for (col=1; col<(SIZE-1); col++)
        {
            int y;                                //Se crean 2 variables provisorias como punteros auxiliares para revisar los alrededores de la célula
            int x;
            int alive;                            //Se crea una variable local como contador para las células vivas que 'rodean' a la célula analizada

            for (y=row-1; y<row+2;y++)            //Ahora revisa cada célula adyacente y si están vivas incrementa el contador
            {
                for (x=col-1; x<col+2; x++)
                {
                    if ((universe [y] [x] == '*') && y != row && x != col )
                    {
                        alive++;
                    }
                }

            }
            if (universe [row] [col] == '*')      //Dependiendo de si la célula estaba originalmente viva o muerta se aplicarán distintos criterios dictados por las reglas
            {
                if (alive == 2 || alive == 3)
                {
                    future [row] [col] = '*';
                }
                else
                {
                    future [row] [col] = ' ';
                }
            }
            else                                  //Sea cual sea el resultado la nueva célula se guardará en una nueva matriz, que luego se imprimirá en pantalla
            {
                if (alive == 3)
                {
                    future [row] [col] = '*';
                }
                else
                {
                    future [row] [col] = ' ';
                }

            }
                                                  //El proceso se repite para todas las células del arreglo interior
        }
    }
}