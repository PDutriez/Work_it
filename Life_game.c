#include <stdio.h>
#define SIZE 8
void lgame (void);


int main (void)
{
    int input;
    char primordial [SIZE] [SIZE];
    char universe [SIZE] [SIZE];
    char future [SIZE] [SIZE];
    universe = primordial;

    input=getchar();

    if (input == 'N')
    {
        lgame ();
    }
    else (input == 'R')
    {
        universe = primordial;
    }
    input=getchar();
    return 0;
}
