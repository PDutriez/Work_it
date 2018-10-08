#include <stdio.h>
#include "justpoint.h"
/*******************************************************************************
 * arreglos para guardar los argumentos que vamos a separar más adelante
 * en tres secciones distintas
 ******************************************************************************/
char * opciones [2][O_MAX];
char * parametros [O_MAX];
/******************************************************************************/
int checkopt(int argc,char* argv[])
{
    int word,options=0;
    for(word=1;word<argc;word++) //Empezamos en 1 para saltear el nombre
    {
       if(*argv[word]=='-')
       {
               opciones[0][options] = argv [word];
               opciones[1][options++] = argv [++word];
       }
   }
   return options;
}

int checkpar(int argc,char *argv[])
{
  int word,parameters=0;
  for(word=1;word<argc;word++) //Empezamos en 1 para saltear el nombre
  {
     if(*argv [word]=='-')
          word++;
     else
          parametros[parameters++] = argv[word];
  }
  return parameters;
}

void checkname(const char* name,const char* mainname)
{
    int status=1;    //Inicialmente creemos que ambas son iguales
    name+=2;         //Seteamos el puntero al inicio del nombre
    printf("Nombre actual del archivo: %s\n",name);
    while((*name!=0 || *mainname!=0) && status!=0) //No es necesario "!=0" pero ayuda a la comprension
    {
        if(*name++ != *mainname++)
          {
          status=0; //Implica que son distintos sus valore
          printf("\n ERROR: Se ha modificado el nombre original del archivo\n");
          }
    }
}
