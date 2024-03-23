void list_add_front( struct list** old, int64_t value );

struct list* list_reverse( const struct list * list ) {
    struct list* reverse_list = NULL;
    while (list) {
        list_add_front(&reverse_list, list -> value);
        list = list -> next;
    }
    return reverse_list;
}
