#include<stdio.h>
#include<stdint.h>
#include"puerto.h"

typedef struct {
  unit8_t   a;
  unit8_t   b;
} byte_t;
typedef union {
  unit16_t   d;
  byte_t    ab;
} acum_t;

static int checknum(); //Funcion que recibe distintos tipos de numero y los transforma a decimal
static unit16_t makeMask(int bit); //Funcion que crea mascaras para las funciones
static acum_t registro;

void bitSet(char registro,int bit)
{ //Necesitamos hacer un OR entre la mascara y el reistro
    if(registro='b' || registro='B')
    {
      registro.ab.b|=(1<<bit);
    }
    else if(registro='a' || registro='A')
    {
      registro.ab.a|=(1<<bit);
    }
    else if(registro='d' || registro='D')
    {
      registro.d|=(1<<bit);
    }
}

void bitClr(char registro,int bit)
{ //Necesitamos hacer un AND entre el registro y el complemento a uno de ma mascara
    if(registro='b' || registro='B')
    {
      registro.ab.b&= ~(1<<bit);
    }
    else if(registro='a' || registro='A')
    {
      registro.ab.a&= ~(1<<bit);
    }
    else if(registro='d' || registro='D')
    {
      registro.d&= ~(1<<bit);
    }
}

void bitToggle(char registro,int bit)
{ //Necesitamos hacer un XOR entre el registro y la mascara
    if(registro='b' || registro='B')
    {
      registro.ab.b^=(1<<bit);
    }
    else if(registro='a' || registro='A')
    {
      registro.ab.a^=(1<<bit);
    }
    else if(registro='d' || registro='D')
    {
      registro.d^=(1<<bit);
    }
}

void bitGet(char registro,int bit)
{
    int copy;
    copy=registro&(1<<bit); //Aplicamos una mascara para saber el valor del bit deseado
    printf("\nRegistro:%c\tBit:%d\tValor:%d\n",registro,bit,!!copy); //Con !!copy obtenemos si su valor es 0 o 1
}

void maskOn(char registro,int mask)
{
    for(int count=1;count<=16;++count,mask/2)
    {
        if(mask%2)
        {
            bitSet(registro,count);
        }
    }
}

void maskOff(char registro,int mask)
{ //Hacemos bit a bit la mascara, utilizando las otras funciones
    for(int count=1;count<=16;++count,mask/2)
    {
        if(mask%2)
        {
            bitClr(registro,count);
        }
    }
}

void maskToggle(char registro,int mask)
{
    for(int count=1;count<=16;++count,mask/2)
    {
        if(mask%2)
        {
            bitToggle(registro,count);
        }
    }
}
