/*
struct list {
    int64_t value;
    struct list* next;
};
*/
void print_int64(int64_t i);
struct list* node_create( int64_t value );
void list_destroy( struct list* list );

static int64_t sum( int64_t x, int64_t y) { return x + y; }

typedef int64_t folding(int64_t, int64_t);

int64_t list_fold( 
        const struct list* l, 
        int64_t init, 
        folding f) {
    int64_t result = init;
    while (l != NULL) {
        result = f(result, l->value);
        l = l->next;
    }
    return result;
}

int64_t list_sum( const struct list* l ) {
     return list_fold(l, 0, sum);
}
