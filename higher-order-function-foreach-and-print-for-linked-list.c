/*
struct list {
    int64_t value;
    struct list* next;
};
*/

void print_int64(int64_t i);


void list_foreach( const struct list* l, void (f)(int64_t)) {
    struct list *current = (struct list*)l;
    while (current) {
        (f)(current->value);
        current = current->next;
    }
}

void list_print( const struct list* l) { 
    list_foreach(l, print_int64_space);
}
