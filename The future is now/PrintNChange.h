#ifndef PRINTNCHANGE_H
#define PRINTNCHANGE_H

#ifndef MAX
#define MAX 102 //Es el tamaño de las matrices
#endif

void copypaste(char copy[MAX][MAX],char paste[MAX][MAX], int *p);    //Copia una matriz en otra
void print_mundo(char arr[MAX][MAX], int *p);                        //Esta funcion imprime la matriz en pantalla
void time_clean(int *p);                                             //Esta funcion se encarga de hacer tiempo y limpiar la pantalla para hacer que se vea bien la nueva generacion

#endif
