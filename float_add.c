
float float_add(float a,float b)
{
	int *p1,*p2;
	int sign1,sign2,exp1,exp2,mantissa1,mantissa2;
	
	p1 = (int *)&a;
	p2 = (int *)&b;
	
	sign1 = (*p1) >> 31;
	exp1 = ((*p1) & 0x7FFFFFFF) >> 23;
	mantissa1 = ((*p1) & 0x007FFFFF) | (0x00800000);
	
	sign2 = (*p2) >> 31;
	exp2 = ((*p2) & 0x7FFFFFFF) >> 23;
	mantissa2 = ((*p2) & 0x007FFFFF) | (0x00800000);
	return a+b;
}
