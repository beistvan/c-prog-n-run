#include <stdint.h>
#include <stddef.h>
#include <stdio.h>
#include <inttypes.h>

int64_t square( int64_t x ) { return x * x; }

int main(void) {

   int64_t array[] = { 1, 2, 3, 4, 5 };

   const size_t count = sizeof(array) / sizeof(array[0]);


   // function pointer int64_t -> int64_t

   int64_t (*mapper)(int64_t) = &square;

   for( size_t i = 0; i < count; i = i + 1 ) {
      array[i] = (*mapper)( array[i] );
      printf("% " PRId64, array[i]);
   }


   return 0;
}
