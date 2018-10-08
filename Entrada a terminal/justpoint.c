#include <stdio.h>
#include "justpoint.h"
/*******************************************************************************
 * arreglos para guardar los argumentos que vamos a separar más adelante
 * en tres secciones distintas
 ******************************************************************************/
char * opciones [2][O_MAX];
char * nombre;
char * parametros [O_MAX];
/******************************************************************************/
int clasify (int argc, char *argv[])
{
    int word;
    int options = 0;                                  //numero de opciones
    int parameters = 0;                               //numero de parametros

/*******************************************************************************
 * Se revisarán todos los argumentos de argv y los clasificará según su tipo
 * en tres secciones distintas
 ******************************************************************************/
     for(word=0;word<argc;word++)
     {
        switch (* argv [word])
        {
            case '.':                                 //Nombre del programa
            {
                nombre = argv[word]+2;
                break;
            }
            case '-':                                 //Opciones
            {
                opciones[0][options] = argv [word];
                opciones[1][options++] = argv [++word];
                break;
            }
            default:                                  //Parametros
            {
                parametros [parameters++] = argv [word];
            }
        }
    }

printf("options:%d parametros:%d\n",options,parameters);

    printf ("Nombre del programa: %s\n", nombre);
    for (int counter= 1; counter<=options; counter++)
    {
        printf ("\nOpción %d:", counter);
        printf ("\nClave: %s", opciones[0][counter-1]+1);
        printf ("\tValor: %s\n", opciones[1][counter-1]);
    }
    for (counter= 1; counter<=parameters; counter++)
    {
        printf ("\nParámetro %d: %s\n", counter, parametros[counter-1]);
    }

    return 0;
}
