#ifndef JUSTPOINT_H
#define JUSTPOINT_H
/************************************************************************************
 * PROTOTIPOS DE FUNCIONES
 ***********************************************************************************/
void checkname(const char* name,const char* mainname);
/*Funcion que se encarga de verificar la veracidad del nombre, tiene incorporado
un mensaje de error en caso de ser distito el nombre del archivo y el nombre
del ejecutable*/
int checkpar(int argc,char *argv[]);
/*Funcion que se encarga de detectar todos los parametros enviados por la terminal,
devuelve la cantidad de parametros que fueron encontrados*/
int checkopt(int argc,char* argv[]);
/*Funcion que se encarga de detectar todas las opciones enviadas por la terminal,
devuelve la cantidad de opciones que fueron encontradas */
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
