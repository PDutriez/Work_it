#include <stdio.h>
#define MAX 101 //Es el tamaño de las matrices
void lgame (void);
void create(int n); //Creal la matriz elegida por el USUARIO
void copypaste(int copy[MAX][MAX],int paste[MAX][MAX]); //Copia una matriz en otra
void print_mundo(int arr[MAX][MAX]); //Esta funcion imprime la matriz en pantalla
void deadoralive (int arr1[MAX][MAX],int arr2[MAX][MAX]); //Esta función revisa las células y las actualiza en una matriz provisoria

int input, num, inicio, tope;
char universe [MAX][MAX];
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
          (num<=100 && num>=1)? create(num) : printf("\nVuelva a ingresar los datos");
          putchar('\n');
          num=0; //Si se cargaron bien lo datos no pasa nada pero en caso contrario se necesita resetear este valor
      }
      if (input == 'S' || input == 's') //Se inicia el juego
      {
          printf("Si quiere parar el juego aprete 'ENTER'\n");
          while((input=getchar()) != '\n')
          {
              print_mundo(universe);
              deadoralive(universe,future);
              copypaste(future, universe);
          }

          lgame ();
      }
      else if (input == 'R' || input == 'r')
      {
          //DEBERIA REINICIAR TODAS LAS COSAS
      }
      input=getchar();
    }
}
void create(int n) //Creal la matriz elegida por el USUARIO
{                  //Ademas de los punteros de la misma dentro de la amtriz original
    inicio=(MAX - n)/2; //Se creal el inicio de la matriz a nostrar
    tope=MAX-inicio; //Se creal el tope de la matriz a mostrar
    (n%2)? :--tope; //Al ser un numero par se trunca el valor y se agega un casillero falso
    int i, j; //Variables punteros
    for(j=inicio ; j<tope ; ++j)
    {
      for(i=inicio ; i<tope ; i+=n)
      universe[i][j]='*';
    }
    printf("Tamaño cargado correctamente, por favor aprete 'S' para iniciar\n")
}

void copypaste(int copy[MAX][MAX], int paste[MAX][MAX]) //Copia una matriz en otra
{
    int countfil, countcol;
    countfil=inicio; //Primerea fila
    while(countfil<tope)  //Menos a la cantidad de columnas totales
    {
        countcol=0; //Primera columna
        while(countcol<tope)  //Menor a la cantidad de filas totales
        {
            paste[countfil][countcol]=copy[countfil][countcol]; //Igualamos sus valores
            ++countcol; //Columna siguiente dentro de la fila
        }
        ++countfil; //Fila siguiente
    }
}
void print_mundo(int arr[MAX][MAX]) //Esta funcion imprime la matriz en pantalla
{
    int countfil, countcol;
    countfil=inicio;
    while(countfil<tope)
    {
        countcol=inicio; //Con esto señalamos el segundo elemento de la segunda fila
        while(countcol<tope)
        {
            printf("%c",arr[countfil][countcol]);
            ++countcol;
        }
        ++countfil;
        putchar('\n');
    }
}

void deadoralive (int arr1[MAX][MAX],int arr2[MAX][MAX])  //Esta función revisa las células y las actualiza en una matriz provisoria
{
    int col;                                      //Puntero para columnas en la matriz
    int row;                                      //Puntero para filas en la matriz
    for (row=inicio; row<tope; row++)              //Consecituivamente se desplazará en un arreglo menor al original ya que los bordes no se modifican
    {
        for (col=inicio; col<tope; col++)
        {
            int y, x;                              //Se crean 2 variables provisorias como punteros auxiliares para revisar los alrededores de la célula
            int alive;                            //Se crea una variable local como contador para las células vivas que 'rodean' a la célula analizada

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
            if (arr1 [row][col] == '*')      //Dependiendo de si la célula estaba originalmente viva o muerta se aplicarán distintos criterios dictados por las reglas
            {
                if (alive == 2 || alive == 3)
                {
                    arr2 [row][col] = '*';
                }
                else
                {
                    arr2 [row][col] = ' ';
                }
            }
            else                                //En caso de estar nuerta debemos analizar si revive
            {
                if (alive == 3)
                {
                    arr2 [row] [col] = '*';    //La celula revive
                }
                else
                {
                    arr2 [row] [col] = ' ';   //La ccelula sigue muerta
                }

            }
                                              //El proceso se repite para todas las células del arreglo interior
        }
    }
}
