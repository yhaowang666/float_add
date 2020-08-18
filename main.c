#include <stdio.h>
#include <stdlib.h>
#include"float_add.h"
int main(int argc, char *argv[])
{
    float a = 1.23,b = 2.34;
    float c = (float)float_add(a,b);
    
    printf("%f+%f = %f\n",a,b,c);
}
