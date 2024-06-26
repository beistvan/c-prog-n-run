/*
struct list {
    int64_t value;
    struct list* next;
};
*/
void print_int64(int64_t i);

struct list* node_create( int64_t value );
void list_destroy( struct list* list );

struct list* list_add_node(struct list* current_node, int64_t value) {
    struct list* new_node = node_create(value);
    if (current_node != NULL) {
        current_node->next = new_node;
    }
    return new_node;
}

// init, f(init), f(f(init)), ... 
struct list* list_iterate( int64_t init, size_t sz, int64_t(f)(int64_t)) {
    int64_t value = init;
    struct list* first_node = NULL;
    struct list* last_node = NULL;
    for (size_t i = 0; i < sz; ++i) {
        last_node = list_add_node(last_node, value);
        if (first_node == NULL)
            first_node = last_node;
        value = f(value);
    }
    return first_node;
}

