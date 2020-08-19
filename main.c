#include <stdio.h>
#include <stdlib.h>
#include"float_add.h"
int main(int argc, char *argv[])
{
    float a , b ,c;
    
    
    if(argc == 4){
    	a = atof(argv[1]);
    	b = atof(argv[3]);
    	
    	c = atof(argv[2]);
    	
    	/*printf("%c\n",c[0]);
    	d[0] = '+';
    	printf("%d\n",d[0]);
    	e[0] = '-';
    	printf("%d\n",e[0]);
    	*/
    	
    	if(c == 0){
    		float c = float_add(a,b);
    		printf("(%f)+(%f) = %f\n",a,b,c);
    	}	
    	else if(c == 1){
    		float c = float_add(a,-b);
    		printf("(%f)-(%f) = %f\n",a,b,c);
    	}
	else{
		printf("command line invalid\n");
		return 1;
	} 
		   		
    }else{
    	printf("command line invalid\n");
    	return 1;
    }
    
    
    //printf("(%f)+(%f) = %f\n",a,b,c);
    return 0;
}
