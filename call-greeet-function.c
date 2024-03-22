#include <stdio.h>

void greet( int n ) {
	printf("Hello ");
	printf("%d", n);
	printf("\n");
}

void main(void) 
{
	greet(10);
	greet(20);
	greet(42);
}
