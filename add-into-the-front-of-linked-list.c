struct list* node_create( int64_t value );

void list_add_front( struct list** old, int64_t value ) {
    struct list* result = node_create(value);
    result->value = value;
    result->next = *old;
    *old = result;
}
