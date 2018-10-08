#ifndef JUSTPOINT_H
#define JUSTPOINT_H
/*******************************************************************************
 * PROTOTIPOS DE FUNCIONES
 ******************************************************************************/
void checkname(const char* name,const char* mainname);
int checkpar(int argc,char *argv[]);
int checkopt(int argc,char* argv[]);
/*******************************************************************************
 * CONSTANTES
 ******************************************************************************/
#define O_MAX 10

/*******************************************************************************
 * VARIABLES UTILIZABLES
 ******************************************************************************/
 extern char * opciones[2][O_MAX];
 extern char * nombre;
 extern char * parametros [O_MAX];
/*Elegimos hacer las variables globales para que en un futuro si se las
necesita, sea mas facil utilizar dichos parametros*/
#endif
