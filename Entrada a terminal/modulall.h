#ifndef JUSTPOINT_H
#define JUSTPOINT_H
/************************************************************************************
 * PROTOTIPOS DE FUNCIONES
 ***********************************************************************************/
void checkname(const char* name,const char* mainname);
/*Funcion que se encarga de verificar la veracidad del nombre, tiene incorporado
un mensaje de error en caso de ser distinto el nombre del archivo (mainname) y el
 nombre del ejecutable (name)*/
int checkpar(int argc,char *argv[]);
/*Funcion que se encarga de detectar y ordenar todos los parametros enviados por la
 terminal. Devuelve la cantidad de parametros que fueron encontrados*/
int checkopt(int argc,char* argv[]);
/*Funcion que se encarga de detectar y ordenar todas las opciones enviadas por la
 terminal. Devuelve la cantidad de opciones que fueron encontradas */
/************************************************************************************
 * CONSTANTES
 ***********************************************************************************/
#define O_MAX 10
/************************************************************************************
 * VARIABLES UTILIZABLES
 ***********************************************************************************/
 extern char * opciones[2][O_MAX];
 extern char * parametros [O_MAX];
/*Elegimos hacer las variables globales para que en un futuro si se las necesita,
sea mas facil utilizar dichos parametros*/
#endif
