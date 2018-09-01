#include <stdio.h>
#define MAX 101 //Es el tamaño de las matrices
void lgame (void);

int input, num, SIZE, inicio;
char universe [MAX] [MAX];
char future [MAX] [MAX];

int main (void)
{
    input=getchar();
    //DEBERIA INICIAR ALGUNAS COSAS (MATRIZ ETC)
    printf("Este es el juego de la vida, usted tiene la opcion de elegir el tamaño \n");
    printf("de la matriz entre 1 y 100, indique el tamaño que desea usar:...\n", );
    while((input=getchar()) != EOF)
    {
      if(input<='9' && input>='0')
      {
          input-='0';
          num=(num*10)+input; //Se actualiza el tamaño de la matriz
      }
      else if (input=='\n')
      {
          (num<=100 && num>=1)? create(num) : printf("\n<Vuelva a ingresar los datos");
          putchar('\n');
          num=0; //Si se cargaron bien lo datos no pasa nada...
      }       //pero en caso contrario se necesita resetear este valor
      if (input == 'S' || input == 's')
      {
          lgame ();
      }
      else (input == 'R' || input == 'r')
      {
          universe = primordial;
      }
      input=getchar();
    }


}
void create(int n)
{
    int i, j; //Variables punteros
    for(j=1 ; j<MAX ; ++j)
    {
      for(i=1 ; i<MAX ; i+=n)
      universe[i][j]='*';
    }
    inicio=(MAX - n)/2;
    clean(inicio,(MAX-n));
  printf("Tamaño cargado correctamente, por favor aprete 'S' para iniciar\n")
}
