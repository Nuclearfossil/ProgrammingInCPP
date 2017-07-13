// ProgrammingInCPP.cpp : Defines the entry point for the console application.
//

#include <stdio.h>
#include "Functions.h"


int main()
{
    for (unsigned int index = 0; index < 10; index++)
    {
        printf("The Fibbonaci series of %d is %d\n", index, Fibbonaci(index));
    }

    printf("press any key to continue");
    scanf("-");
    return 0;
}

