#include <stdio.h>
#include"float_add.h"
int main()
{
    float a = 1.23,b = 2.56;
    float c = float_add(a,b);
    
    printf("%f+%f = %f\n",a,b,c);
}
