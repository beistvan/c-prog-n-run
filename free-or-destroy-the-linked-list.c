void list_destroy( struct list* list ) {
    while (list) {
        struct list* tmp = list -> next;
        free( list );
        list = tmp; 
    }
}
