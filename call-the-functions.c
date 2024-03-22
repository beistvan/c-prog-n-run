#include<stdio.h>

void greet() {
	printf("Hello, ");
}

void b() {
	printf("John");
}

void v() {
	printf("Jack");
}

void print_newline() {
	printf("\n");
}

void main(void) {

	greet();
	b();
	print_newline();
	greet();
	v();
	print_newline();
	greet();
	b();
}
