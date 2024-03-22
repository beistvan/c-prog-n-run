int array_min(int* array, int* limit, int** min) {
    if (array >= limit) return 0;
    *min = array;
    for( int* cur = array + 1;
              cur < limit; 
              cur = cur + 1 )
    {
       if ( *cur < **min ) {
            *min = cur;
       }
    }
    return 1;
}


int main() {
    int array[] = {4,29,42,2,3};
    int* lmin = NULL;
    
    if ( array_min( array, 
                    array + sizeof(array)/sizeof(array[0]), 
                    &lmin ) )
    {
        printf("Min is: %d\n", *lmin );
    } 
    else
    {
        printf("Array is empty\n");
    }
    return 0;
}
