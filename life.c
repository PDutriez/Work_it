#include <stdio.h>
#define N 6 //Cantidad de filas
#define M N //Cantidad de columnas
#define VIVA 1 //valor de celula viva
#define MUERTA 0 //valor de celula muerta
int mundo [M][N];
void print_mundo(arr[M][N])
{
    int countfil, countcol;
    countfil=1;  //Empieza 1 porque empieza en la segunda fila
    while(countfil<=(SIZE-2)) //Por como pensamos el arr. imprime toda fila menos los bordes
    {
        countcol=1; //Con esto señalamos el segundo elemento de la segunda fila
        while(countcol<=(SIZE-2)) //Restamos 2 porque tiene dos cols. "fantasmas"
        {
            printf("%c",arr[countfil][countcol]);
              ++countcol;
        }
        ++countfil;
        printf("\n");
    }
}

void copypaste(copy[SIZE][SIZE], paste[SIZE][SIZE])
{
    int countfil, countcol;
    countfil=0; //Primerea fila
    while(countfil<=SIZE)  //Menos a la cantidad de columnas totales
    {
        countcol=0; //Primera columna
        while(countcol<=SIZE)  //Menor a la cantidad de filas totales
        {
            paste[countfil][countcol]=copy[countfil][countcol]; //Igualamos sus valores
            ++countcol; //Columna siguiente dentro de la fila
        }
        ++countfil; //Fila siguiente
    }
}
