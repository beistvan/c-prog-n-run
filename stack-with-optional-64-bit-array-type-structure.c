/* 

struct maybe_int64 {int64_t value; bool valid;};
struct maybe_int64 some_int64(int64_t i);
const struct maybe_int64 none_int64 = { 0, false };
void maybe_int64_print( struct maybe_int64 i );


struct array_int {int64_t* data; size_t size;};
struct array_int array_int_create( size_t sz );

struct array_int array_int_create( size_t sz ) {
    return (struct array_int) { .data = malloc( sizeof( int64_t ) * sz ), .size = sz };
}

int64_t* array_int_last( struct array_int a );
struct maybe_int64 array_int_get( struct array_int a, size_t i );
bool array_int_set( struct array_int a, size_t i, int64_t value );
void array_int_print( struct array_int array );
void array_int_free( struct array_int* a );

*/

struct stack {
  size_t count;
  struct array_int data;
};

size_t stack_count( const struct stack* s ) {
    return s->count;
}

struct stack stack_create( size_t size ){
    return (struct stack) {
        .count = 0,
        .data = array_int_create(size)
    };
}

void stack_destroy( struct stack* s ) {
    array_int_free(&s->data);
}

bool stack_is_full( const struct stack * s){
    return stack_count(s) == s->data.size;
}

bool stack_is_empty( const struct stack * s) {
    return stack_count(s) == 0;
}

bool stack_push( struct stack* s, int64_t value ){
    if (stack_is_full(s))
        return false;
    size_t pos = stack_count(s);
    s->data.data[pos] = value;
    s->count = pos+1;
    return true;
}

struct maybe_int64
stack_pop( struct stack* s ){
    if (stack_is_empty(s))
        return none_int64;
    size_t pos = stack_count(s)-1;
    int64_t value = s->data.data[pos];
    s->count = pos;
    return (struct maybe_int64) {.valid = true, .value = value};
}

void stack_print( const struct stack* s ) {
  for (size_t i = 0; i < stack_count( s ); i = i + 1 ) {
    print_int64( array_int_get( s->data, i).value );
    printf(" ");
  }
}
