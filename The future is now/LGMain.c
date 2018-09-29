#include <stdio.h>
#include "PrintNChange.h"
#include "Creation.h"

int main (void)
{
    int input, num, talive=1;
    char universe [MAX][MAX];
    char future [MAX] [MAX];
    int walls [2];
    printf("Este es el juego de la vida, usted tiene la opcion de elegir el tamaño \n");
    printf("de la matriz entre 1 y 100, indique el tamaño que desea usar:...\n");
    while((input=getchar()) != EOF)
    {
      if(input<='9' && input>='0')
      {
          input-='0';
          num=(num*10)+input; //Se actualiza el tamaño de la matriz
      }
      else if (input=='\n')
      {
          if (num<=100 && num>=1)
              create(num, walls, universe, future);
          else
               printf("\nVuelva a ingresar los datos");
          putchar('\n');
          num=0; //Si se cargaron bien lo datos no pasa nada pero en caso contrario se necesita resetear este valor
      }
      else if (input == 'S' || input == 's') //Se inicia el juego
      {
          printf("Si quiere parar el juego aprete 'CTRL + C'\n");
          time_clean(walls);
          while(talive!=0)
          {
              print_mundo(universe, walls);  //Se imprime el mundo actual
              talive=deadoralive(universe,future, walls);  //Se lo analiza y ademas verifica que no este vacio
              copypaste(future, universe, walls); //Se lo copia en la otra matriz para imprimirlo al empezar el while
              time_clean(walls);
          }
          printf("Parece que el juego ha terminado....\n");
          walls[1]=0, walls[2]=0, talive=1; //Se cargan estos valores para poder reiniciar el juego en caso de terminarse
      }
    }

}
