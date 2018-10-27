#include <stdio.h>
#include <string.h>
int pali (const char *str, int dim);
int check (const char *str, int dim);

int main (void)
{                     //ya se que esto no tiene que ir asi pero se puede optimizar despues
    int i;            // por ahora capta los que estan todo junto, pero no capta los que tienen espacios
    printf ("la palabra ana na");
    i = pali ("ana na", strlen ("ana na"));
    if (i == 1)
        printf (" es palíndromo\n");
    else
        printf (" no es palíndromo\n");
    return 0;

}


int pali (const char *str, int dim)
{
    if (dim <= 1)
    {
        return 1;
    }
    if (str [0] == str [dim-1])
    {
        return pali (str+1, dim-2);
    }
    else    //antes de darlo por descartado hay que revisar que este comparando dos leras
    {
        check (str, dim);
    }
}



//Revisa si se trata del primer o el ultimo lugar (o los dos) y corrige el string

int check (const char *str, int dim)
{
    if (((str [0]< 'a') && (str [0]> 'z'))&&((str [0]< 'A') && (str [0]> 'Z')))
    {
        str++;
        if (str [0] == str [dim-1])
        {
            return pali (str+1, dim-2);
        }
        else
            return 0;
    }
    else
    {
        return 0;
    }
    if (((str [dim-1]< 'a') && (str [dim-1]> 'z'))&&((str [dim-1]< 'A') && (str [dim-1]>'Z')))
    {
        dim--;
        if (str [0] == str [dim-1])
        {
            return pali (str+1, dim-2);
        }
        else
            return 0;
    }       //si efectivamente son dos letras distintas devuelve 0
    else
    {
        return 0;
    }

}
