#include <stdio.h>

int read_int() {
    int x;
    scanf("%d", &x);
    return x;
}

int main() {
  int input1 = read_int(); // read first number
  int input2 = read_int(); // read second number

  printf("%d", input1 + input2); // print out the sum

  return 0;   
}
