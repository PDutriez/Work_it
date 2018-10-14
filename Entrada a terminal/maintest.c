#include <stdio.h>
#include "modulall.h"
# define NAME "modulall"
int main(int argc,char* argv[])
{
      int parameters,options;

      checkname(argv[0],NAME);
      parameters=checkpar(argc,argv);
      options=checkopt(argc,argv);

//Imprimimos todos los valores mandados en la terminal, ya organizados
      printf("opciones:%d parámetros:%d\n",options,parameters);
      for (int counter= 1; counter<=options; counter++)
      {
          printf ("\nOpción %d:", counter);
          printf ("\nClave: %s", opciones[0][counter-1]+1);
          printf ("\tValor: %s\n", opciones[1][counter-1]);
      }
      for (int counter= 1; counter<=parameters; counter++)
      {
          printf ("\nParámetro %d: %s\n", counter, parametros[counter-1]);
      }
}
