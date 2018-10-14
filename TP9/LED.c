/*******************************************************************************
 * Liberías utilizadas
 ******************************************************************************/
#include <stdio.h>
#include <stdint.h>
#include "puerto.h"
#include "LED.h"

/*******************************************************************************
 * variables propias de este archivo
 ******************************************************************************/
static int input;
static int mask = 0xFF;
static char Port_A;
/******************************************************************************/


/*******************************************************************************
 * función principal, analiza el input y responde segun corresponda
 ******************************************************************************/
int main (int argc, char *argv[])
{
    printf ("Ingrese el numero de LED o el comando\n");
    while ((input= getchar () ) != ('q' || 'Q'))
    {
        /***********************************************************************
        * primero revisa se se trata de un numero de led
        ***********************************************************************/
        if ((input <= '7') && (input >= '0'))
        {
            input-='0';
            bitSet (Port_A, input);
        }
        /***********************************************************************
        * como el puerto solo tiene 8 espacios avisa en caso de que el numero
        * no coincida con alguno de ellos
        ***********************************************************************/
        else if ((input <= '9') && (input >= '8'))
        {
            printf ("el número ingresado no es válido");
        }
        /***********************************************************************
        * si se presiona la letra 'T' todos los bits cambian a su opuesto
        ***********************************************************************/
        else if ((input == 't') || (input == 'T'))
        {
            maskToggle (Port_A, mask);
        }
        /***********************************************************************
        * si se presiona la letra 'S' prende todos los bits
        ***********************************************************************/
        else if ((input == 's') || (input == 'S'))
        {
            maskOn (Port_A, mask);
        }
        /***********************************************************************
        * si se presiona la letra 'C' apaga todos los bits
        ***********************************************************************/
        else if ((input == 'c') || (input == 'C'))
        {
            maskOff (Port_A, mask);
        }
        /***********************************************************************
        * en caso de tocar cualquier otra letra (excepto la Q, pues con ella
        * se termina el programa)se notificará que no hay acciones disponibles
        ***********************************************************************/
        else if ((input != 'Q') || (input != 'q'))
        {
            printf ("El comando ingresado no es válido\n");
        }
        /***********************************************************************
        * para finalizar, muestra el puerto en la pantalla para que se puedan
        * apreciar los cambios realizados
        ***********************************************************************/
        show_port (Port_A);

    }

    return 0;
}

/*******************************************************************************
 * función secundaria, muestra el puerto indicado en la pantalla
 ******************************************************************************/
void show_port (char Port_A)
{
    printf ("\nEstado del puerto A:\n");
    int bit_number;
    /***************************************************************************
    * toma cada bit e imprime el valor que le corresponde en la pantalla
    ***************************************************************************/
    for (bit_number=7; bit_number>=0; bit_number--)
    {
        printf ("%d\t", bitGet (Port_A, bit_number));
    }
    printf ("\n");
}
