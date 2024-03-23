int64_t read_int64();
size_t read_size();

void array_int_fill( int64_t* array, size_t size ) {
    for (size_t i = 0; i < size; i++) {
        int64_t n;
        scanf( "%" SCNd64, &n);
        array[i] = n;
    }
}

int64_t* array_int_read( size_t* size ) {
    scanf("%zu", size);
    int64_t* array = malloc(sizeof( int64_t ) * (*size));
    array_int_fill( array, *size );
    return array;
}
