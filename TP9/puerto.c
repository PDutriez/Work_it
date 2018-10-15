#include <stdint.h>
#include <stdio.h>
#include "puerto.h"

typedef struct {
  uint8_t   a;
  uint8_t   b;
} byte_t;
typedef union {
  uint16_t   d;
  byte_t    ab;
} acum_t;


static acum_t registro; //Registro que usan todas las funciones para trabajar
/*******************************************************************************
* Las funciones bitSet,bitClr y bitToggle tienen la misma logica pero se
* diferencian en sus operandos entre puerto y la mascara establecida. */
void bitSet(char puerto,int bit)
{ //Necesitamos hacer un OR entre la mascara y el reistro
    if(puerto=='b' || puerto=='B')
    {
      registro.ab.b|=(1<<bit);
    }
    else if(puerto=='a' || puerto=='A')
    {
      registro.ab.a|=(1<<bit);
    }
    else if(puerto=='d' || puerto=='D')
    {
      registro.d|=(1<<bit);
    }
}

void bitClr(char puerto,int bit)
{//Necesitamos hacer un AND entre el registro y el complemento a uno de ma mascara
    if(puerto=='b' || puerto=='B')
    {
      registro.ab.b&= ~(1<<bit);
    }
    else if(puerto=='a' || puerto=='A')
    {
      registro.ab.a&= ~(1<<bit);
    }
    else if(puerto=='d' || puerto=='D')
    {
      registro.d&= ~(1<<bit);
    }
}

void bitToggle(char puerto,int bit)
{ //Necesitamos hacer un XOR entre el registro y la mascara
    if(puerto=='b' || puerto=='B')
    {
      registro.ab.b^=(1<<bit);
    }
    else if(puerto=='a' || puerto=='A')
    {
      registro.ab.a^=(1<<bit);
    }
    else if(puerto=='d' || puerto=='D')
    {
      registro.d^=(1<<bit);
    }
}

void bitGet(char puerto,int bit)
{//Necesitamos aplicar la mascara para saber el valor del bit deseado
    int copy;
    if(puerto=='b' || puerto=='B')
    {
      copy=registro.ab.b&(1<<bit);
    }
    else if(puerto=='a' || puerto=='A')
    {
      copy=registro.ab.a&(1<<bit);
    }
    else if(puerto=='d' || puerto=='D')
    {
      copy=registro.d&(1<<bit);
    }
    printf("\nRegistro:%c\tBit:%d\tValor:%d\n",puerto,bit,!!copy);
    //Con !!copy obtenemos si su valor es 0 o 1
}
/*******************************************************************************
* Las funciones maskOn, maskOff, maskToggle llevan la misma logica pero,
* se diferencian en la funcion que utilizan, es por eso que necesitamos una
* para cada una. Su logica es hacer una mascara bit a bit, en vez de aplicar,
* toda la mascara de una.
*******************************************************************************/
void maskOn(char puerto,int mask)
{
    for(int count=0;count<=16;++count)
    {
        if(mask%2)
        {
            bitSet(puerto,count);
        }
        mask/=2;
    }
}

void maskOff(char puerto,int mask)
{ //Hacemos bit a bit la mascara, utilizando las otras funciones
    for(int count=0;count<=16;++count)
    {
        if(mask%2)
        {
            bitClr(puerto,count);
        }
        mask/=2;
    }
}

void maskToggle(char puerto,int mask)
{
    for(int count=0;count<=16;++count)
    {
        if(mask%2)
        {
            bitToggle(puerto,count);
        }
        mask/=2;
    }
}
