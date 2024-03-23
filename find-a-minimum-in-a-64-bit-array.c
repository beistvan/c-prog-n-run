int64_t* array_int_min( int64_t* array, size_t size ) {
  if (size <= 0) return NULL;
  int64_t* min = &array[0];
  for (size_t i = 1; i < size; i++) {
    if (array[i] < *min) min = &array[i];
  }
  return min;
}
