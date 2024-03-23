/*
struct list {
    int64_t value;
    struct list* next;
};
*/

void print_int64(int64_t i);

struct list* node_create( int64_t value );

struct list* list_add_node(struct list* current_node, int64_t value) {
    struct list* new_node = node_create(value);
    if (current_node != NULL) {
        current_node->next = new_node;
    }
    return new_node;
}

struct list* list_map( const struct list* l, int64_t (f) (int64_t))  {
    struct list* new_list_start = NULL;
    struct list* new_list = NULL;
    while(l) {
        int64_t new_value = f(l->value);
        new_list = list_add_node(new_list, new_value);
        if (new_list_start == NULL)
            new_list_start = new_list;
        l = l->next;
    }
    return new_list_start;
}

int64_t copy_int64_t(int64_t a) {
    return a;
}

struct list* list_copy( const struct list* l ) {
    return list_map(l, &copy_int64_t);
}

int64_t abs_int64_t(int64_t a) {
    return a > 0 ? a : -a;
}

struct list* list_abs( const struct list* l ) {
    return list_map(l, &abs_int64_t);
}
