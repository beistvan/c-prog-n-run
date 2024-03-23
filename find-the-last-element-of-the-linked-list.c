struct list* list_last( struct list * list ) {
    struct list * buff = list;
    while (list) {
        buff = list;
        list = list -> next;
    }
    return buff;
}
