#include <stdint.h>
#include <stddef.h>
#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>

int int64_comparer (const int64_t * x, const int64_t * y)
{
  if (*x > *y)
	return 1;
  if (*x < *y)
	return -1;
  return 0;
}

int int64_void_comparer (const void *_x, const void *_y)
{
  return int64_comparer (_x, _y);
}

int main ()
{
  int64_t array[] = { 5, 4213, 2381, -1231, 23912309, 3883 };
  
  const size_t count = sizeof (array) / sizeof (array[0]);

  qsort (array, count, sizeof (int64_t), int64_void_comparer);
  
  for( size_t i = 0; i < count; i++ )
  {
    printf("% " PRId64, array[i]);
  }

  return 0;
}
