#include <stdio.h>
#define MAX 102 //Es el tamaño de las matrices
void create(int n, int *p); //Creal la matriz elegida por el USUARIO
void copypaste(char copy[MAX][MAX],char paste[MAX][MAX], int *p); //Copia una matriz en otra
void print_mundo(char arr[MAX][MAX], int *p); //Esta funcion imprime la matriz en pantalla
int deadoralive (char arr1[MAX][MAX],char arr2[MAX][MAX], int *p); //Esta función revisa las células y las actualiza en una matriz provisoria
void time_clean(int *p); //Esta funcion se encarga de hacer tiempo y limpiar la pantalla para hacer que se vea bien la nueva generacion
int input, num, i, talive=1;
char universe [MAX][MAX];
char future [MAX] [MAX];
int walls [2];

int main (void)
{
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
          if(num<=100 && num>=1)
              create(num, walls);
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
void create(int n, int *p) //Creal la matriz elegida por el USUARIO
{                  //Ademas de los punteros de la misma dentro de la amtriz original
    deadoralive(universe,universe, walls); //Al estar ambos arreglos con 0s lo que hacemos con esto llenarlo de...
    deadoralive(future,future, walls);     //espacios para que tengan los requisitos del juego
    p[1]=(MAX - n)/2; //Se creal el inicio de la matriz a nostrar
    p[2]=MAX-p[1]; //Se creal el tope de la matriz a mostrar
    p[2]-=((n%2)?1:0); //Al ser un numero inpar se trunca el valor y se agega un casillero falso
    int i, j; //Variables punteros
    for(i=p[1] ; i<p[2] ; ++i)
    {
      for(j=p[1] ; j<p[2] ; j+=(n/2-1))
      universe[i][j]='*';
    }
    printf("Tamaño cargado correctamente, por favor aprete 'S' para iniciar\n");
}

void copypaste(char copy[MAX][MAX], char paste[MAX][MAX], int *p) //Copia una matriz en otra
{
    int countfil, countcol;
    countfil=p[1]; //Primerea fila
    while(countfil<p[2])  //Menos a la cantidad de columnas totales
    {
        countcol=0; //Primera columna
        while(countcol<p[2])  //Menor a la cantidad de filas totales
        {
            paste[countfil][countcol]=copy[countfil][countcol]; //Igualamos sus valores
            ++countcol; //Columna siguiente dentro de la fila
        }
        ++countfil; //Fila siguiente
    }
}
void print_mundo(char arr[MAX][MAX], int *p) //Esta funcion imprime la matriz en pantalla
{
    int countfil, countcol;
    countfil=p[1];
    while(countfil<p[2])
    {
        countcol=p[1]; //Con esto señalamos el segundo elemento de la segunda fila
        while(countcol<p[2])
        {
            putchar('|'); //Separacion entre columnas
            printf("%c ",arr[countfil][countcol]);
            ++countcol;
        }
        ++countfil;
        putchar('|'); //se ponen guiones para separar el borde
        putchar('\n'); //Se pone ENTER para que inicie la nueva linea
    }
}

int deadoralive (char arr1[MAX][MAX],char arr2[MAX][MAX], int *p)  //Esta función revisa las células y las actualiza en una matriz provisoria
{
    int col;                                      //Puntero para columnas en la matriz
    int row;                                      //Puntero para filas en la matriz
    int falive=0;                                   //Cantidad final de celulas vivas
    for (row=p[1]; row<p[2]; row++)              //Consecituivamente se desplazará en un arreglo menor al original ya que los bordes no se modifican
    {
        for (col=p[1]; col<p[2]; col++)
        {
            int y, x;                              //Se crean 2 variables provisorias como punteros auxiliares para revisar los alrededores de la célula
            int alive=0;                            //Se crea una variable local como contador para las células vivas que 'rodean' a la célula analizada

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
            if (arr1[row][col] == '*')      //Dependiendo de si la célula estaba originalmente viva o muerta se aplicarán distintos criterios dictados por las reglas
            {
                if (alive == 2 || alive == 3)
                {
                    arr2[row][col] = '*';
                    ++falive;
                }
                else
                {
                    arr2[row][col] = ' ';
                }
            }
            else                                //En caso de estar nuerta debemos analizar si revive
            {
                if (alive == 3)
                {
                    arr2[row][col] = '*';    //La celula revive
                    ++falive;
                }
                else
                {
                    arr2[row][col] = ' ';   //La ccelula sigue muerta
                }

            }
                                              //El proceso se repite para todas las células del arreglo interior
        }
    }
    return falive; //Devolvemos la cantidad de celulas vivas en el nuevo mundo
}
void time_clean(int *p) //Esta funcion se encarga de hacer tiempo y limpiar la pantalla para hacer que se vea bien la nueva generacion
{
    long time;
    for(time=0;time<300000000;++time); //El tiempo fijado fue elegido a ojo y gusto del programador
    for(time=0;time<p[1];++time) //Se limia la pantalla para que aparezca ordenado
    printf("\n");

}
