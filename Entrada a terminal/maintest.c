#include <stdio.h>
#include "justpoint.h"
# define NAME "modulall"
int main(int argc,char* argv[])
{
      int parameters,options;
      checkname(argv[0],NAME);
      parameters=checkpar(argc,argv);
      options=checkopt(argc,argv);

      printf("options:%d parametros:%d\n",options,parameters);
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
