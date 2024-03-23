size_t list_length( const struct list* list ) {
    struct list *currentPtr = (struct list *)list; 
    size_t length = 0;
    while (currentPtr != NULL) {
        length++;
        currentPtr = currentPtr -> next;            
    }
    return length;
}
