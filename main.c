#include <stdio.h>
#include <stdlib.h>
#include"float_add.h"
int main(int argc, char *argv[])
{
    float a , b ;
    
    if(argc ==3){
    	a = atof(argv[1]);
    	b = atof(argv[2]);
    }else{
    	printf("command line invalid\n");
    	return 1;
    }
    
    float c = (float)float_add(a,b);
    
    printf("(%f)+(%f) = %f\n",a,b,c);
    return 0;
}
