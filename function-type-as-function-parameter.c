#include <stdint.h>
#include <stddef.h>
#include <stdio.h>
#include <inttypes.h>

int64_t square( int64_t x ) { return x * x; }
int64_t cube  ( int64_t x ) { return x * x * x; }


void map( int64_t* array, size_t count, int64_t func(int64_t) ) {
  for( size_t i = 0; i < count; i++ ) {
      array[i] = func( array[i] );
      printf("% " PRId64, array[i]);
  }
  printf("\n");
}

int main() {

   int64_t array[] = { 1, 2, 3, 4, 5 };

   const size_t count = sizeof(array) / sizeof(array[0]);
 
   map( array, count, square );
   map( array, count, cube );

   return 0;
}

// Output:
// 1 4 9 16 25
// 1 64 729 4096 15625
