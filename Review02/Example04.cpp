// Example04.cpp
#include <stdio.h>

unsigned int Fibbonaci(unsigned int i);

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
