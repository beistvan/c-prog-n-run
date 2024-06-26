int64_t* array_int_read( size_t* size );
int64_t* array_int_min( int64_t* array, size_t size); 

void intptr_print( int64_t* x ) {
    if (x == NULL) printf("None");
    else printf("%" PRId64, *x);  
}

void perform() {
    size_t size = 0;  
    int64_t* array = array_int_read(&size);
    if((array == NULL) || (size == NULL) || (size <= 0))
    {
        intptr_print(NULL);
        return;
    }
    int64_t* min = array_int_min(array, size);
    intptr_print(min);
    free(array);
}
