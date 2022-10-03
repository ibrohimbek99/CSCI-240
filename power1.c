#include <stdio.h>
#include <stdlib.h>
int Power(int base, int pow);

void main()
{
    printf("%d\n", Power(3,4));
    return;
}
int Power(int base, int pow)
{
	if (pow==0) 
		return 1;
    else if (pow==1)
        return base;
	else
		return base*Power(base, pow-1);
}