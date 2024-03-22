#include <stdio.h>

int read_int() {
    int x;
    scanf("%d", &x);
    return x;
}

int discriminant(int a, int b, int c) {
    return b * b - 4 * a * c;
}

int root_count(int a, int b, int c) {
   int D = discriminant(a, b, c);
   if (D > 0) return 2;
   else if (D == 0) return 1;
   else return 0;
}

int main() {
    // Read three integers
    int a = read_int();
    int b = read_int();
    int c = read_int();
    // print out the runnig of root_count with arguments a, b, c
    printf("%d", root_count(a, b, c));

    return 0;
}
