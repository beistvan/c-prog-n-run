void normalize( int* n ) {
    while (!(*n % 2) && *n > 0)      
        *n /= 2;
}

/*
Example:
100 becomes 25 (100->50->25), 5 reamins 5, 8 becomes 1 (8->4->2->1)
 */
