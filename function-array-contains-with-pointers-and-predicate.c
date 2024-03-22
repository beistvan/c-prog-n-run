int array_contains(int* array, int* limit, int** position) {
    if (array >= limit) return 0;
    for( int* cur = array;
        cur < limit; 
        cur = cur + 1 )
    {
        if ( predicate(*cur) ) {
            *position = cur;
            return 1;
        }
    }
    return 0;
}
