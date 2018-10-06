#include <stdio.h>
#include "Input_arrays.h"
/*******************************************************************************
 * arreglos para guardar los argumentos que vamos a separar más adelante
 * en tres secciones distintas
 ******************************************************************************/
char ** valores [O_MAX];
char ** claves [O_MAX];
char ** nombre;
char ** parametros [O_MAX];
/******************************************************************************/
int clasify (int argc, char *argv[])
{
    int i;
    int options = 0;                                  //numero de opciones
    int parameters = 0;                               //numero de parametros

/*******************************************************************************
 * Se revisarán todos los argumentos de argv y los clasificará según su tipo
 * en tres secciones distintas
 ******************************************************************************/
     for(i=0;i<argc;i++)
     {
        switch (* argv [i])
        {
            case '.':                                 //Nombre del programa
            {
                nombre = argv;
                break;
            }
            case '-':                                 //Opciones
            {
                claves [options] = & argv [i];
                valores [options] = & argv [i+1];
                i++;
                options++;
                break;
            }
            default:                                  //Parametros
            {
                parametros [parameters] = & argv [i];
                parameters++;
            }
        }
    }
/*******************************************************************************
 * Se corrige el numero de opciones y parámetros para que en vez de 0 a n-1
 * sea de 1 a n
 ******************************************************************************/
    options++;
    parameters++;
/*******************************************************************************
 * A la hora de mostrarlos en pantalla hace falta corregir el puntero al nombre
 * para no incluir el "./" y el puntero a las claves para no mostrar los "-"
 ******************************************************************************/
    printf ("Nombre del programa: %s\n", *nombre+2);
    for (int counter= 1; counter<=options; counter++)
    {
        printf ("\nOpción %d:", counter);
        printf ("\nClave %d: %s", counter, *claves [counter-1]+1);
        printf ("\nValor %d: %s", counter, *valores [counter-1]);
    }
    printf ("\n");
    for (int counter= 1; counter<=parameters; counter++)
    {
        printf ("\nParámetro %d: %s", counter, *parametros [counter-1]);
    }

    return 0;
}
