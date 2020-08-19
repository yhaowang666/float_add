#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "float_add.h"
float float_add(float a,float b)
{
	int *p1,*p2,*p3;
	int sign1,sign2,sign3,exp1,exp2,exp3,mantissa1,mantissa2,mantissa3;
	
	p1 = (int *)&a;
	p2 = (int *)&b;
	
	sign1 = (*p1) >> 31;
	exp1 = ((*p1) & 0x7FFFFFFF) >> 23;
	mantissa1 = ((*p1) & 0x007FFFFF) | (0x00800000);
	//mantissa1 = ((*p1) & 0x007FFFFF) + pow(10,7);
	printf("%d,%d,%d\n",sign1,exp1,mantissa1);
	
	sign2 = (*p2) >> 31;
	exp2 = ((*p2) & 0x7FFFFFFF) >> 23;
	mantissa2 = ((*p2) & 0x007FFFFF) | (0x00800000);
	//mantissa2 = ((*p2) & 0x007FFFFF) + pow(10,7);
	printf("%d,%d,%d\n",sign2,exp2,mantissa2);
	
	//return a+b;
	int x,y;
	x = mantissa1 * pow(2,exp1-127)*(2*sign1+1);
	y = mantissa2 * pow(2,exp2-127)*(2*sign2+1);
	printf("x = %d,y = %d\n",x,y);
	//return a+b;
	
	//得到后23位
	exp3 = 127;
	int m = x+y ;
	p3 = (int *)&m;
	printf("%d\n",m);
	printf("************\n");
	if (abs(m)<pow(2,23)){
		while(abs(m)<pow(2,23)){
			m = (*p3) << 1;
			exp3--;
			printf("%d\n",m);	
		}
	}else{
		while(abs(m)>=pow(2,24)){
			m = (*p3) >> 1;
			exp3++;
			printf("%d\n",m);
		}	
	}
	printf("************\n");
	mantissa3 = abs(m) & (0x7FFFFF);//添加abs去除m为负数对结果的影响
	printf("%d,%d\n",mantissa3,exp3);
	
	//得到符号位
	if(m < 0) sign3 = -1;
	else sign3 = 0;
	printf("%d\n",sign3);
	
	//拼接
	int n,*p4,*p5,*p6,*p7;
	p4 = (int *)&sign3;
	p5 = (int *)&exp3;
	p6 = (int *)&mantissa3;
	n = (sign3 << 31) | (exp3 << 23) | mantissa3;
	printf("%d\n",n);
	float *p;
	p = (float *)&n;
	return *p;
	
	
	
	
	
	
}
