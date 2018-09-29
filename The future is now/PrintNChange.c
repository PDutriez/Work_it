#include "PrintNChange.h"
#include "Creation.h"
#include <stdio.h>

void print_mundo(char arr[MAX][MAX], int *p)                            //Esta funcion imprime la matriz en pantalla
{
    int countfil, countcol;
    for (countfil=p[1]; countfil<p[2]; ++countfil)
    {
                                                                //Con esto señalamos el segundo elemento de la segunda fila
        for (countcol=p[1]; countcol<p[2]; ++countcol)
        {
            putchar('|');                                       //Separacion entre columnas
            printf("%c ",arr[countfil][countcol]);
        }
        putchar('|');                                           //se ponen guiones para separar el borde
        putchar('\n');                                          //Se pone ENTER para que inicie la nueva linea
    }
}
void copypaste(char copy[MAX][MAX], char paste[MAX][MAX], int *p)       //Copia una matriz en otra
{
    int countfil, countcol;
    for (countfil=p[1]; countfil<p[2]; ++countfil)              //Menos a la cantidad de columnas totales
    {
        for (countcol=0; countcol<p[2]; ++countcol)             //Menor a la cantidad de filas totales
        {
            paste[countfil][countcol]=copy[countfil][countcol]; //Igualamos sus valores
        }
    }
}

void time_clean(int *p)                                           //Esta funcion se encarga de hacer tiempo y limpiar la pantalla para hacer que se vea bien la nueva generacion
{
    long time;
    for(time=0;time<300000000;++time);                          //El tiempo fijado fue elegido a ojo y gusto del programador
    for(time=0;time<P[1];++time)                              //Se limia la pantalla para que aparezca ordenado
    printf("\n");

}
