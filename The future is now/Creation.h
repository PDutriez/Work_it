#ifndef CREATION_H
#define CREATION_H
/*******************************************************************************
 * PROTOTIPOS DE FUNCIONES
 ******************************************************************************/
void create(int n, int *p,char arr1[MAX][MAX],char arr2[MAX][MAX]); //Creal la matriz elegida por el USUARIO
int deadoralive (char arr1[MAX][MAX],char arr2[MAX][MAX], int *p);  //Esta función revisa las células y las actualiza en una matriz provisoria
static void clean(char arr1 [MAX][MAX]);             //Funcion que se encarga de la limpieza de matrices
/*******************************************************************************
 * CONSTANTES
 ******************************************************************************/

#define MAX 102 //Es el tamaño de las matrices

/*******************************************************************************
 * VARIABLES UTILIZABLES
 ******************************************************************************/
extern int  inicio, tope;
extern char universe [MAX][MAX];
extern char future [MAX] [MAX];

#endif
