#include <stdio.h>
#include <stdint.h>

#include <inttypes.h>

union qword {
    int64_t integer;
    int32_t parts[2];
}; 

int main()
{
  
   union qword test;
   test.integer = 0xAABBCCDDEEFF1122;

   printf( "%" PRIx32 ", %" PRIx32 "\n", test.parts[0], test.parts[1] );
   return 0;
}
