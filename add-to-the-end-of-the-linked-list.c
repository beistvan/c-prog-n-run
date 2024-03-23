void list_add_back( struct list** old, int64_t value ) {
    if (!*old) 
        list_add_front( old, value );
    else {
        struct list* new_node = node_create( value );
        struct list* last_node = list_last( *old );
        last_node -> next = new_node;    
    }
}
