#ifndef CREATION_H
#define CREATION_H

 #ifndef MAX
 #define MAX 102 //Es el tamaño de las matrices
 #endif

void create(int n, int *p,char arr1[MAX][MAX],char arr2[MAX][MAX]); //Creal la matriz elegida por el USUARIO
int deadoralive (char arr1[MAX][MAX],char arr2[MAX][MAX], int *p);  //Esta función revisa las células y las actualiza en una matriz provisoria

#endif
