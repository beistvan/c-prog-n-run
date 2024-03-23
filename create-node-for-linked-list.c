struct list {
  int64_t value;
  struct list* next;
};

struct list* node_create( int64_t value ) {
  struct list* node_ptr = malloc(sizeof(struct list));
  if (node_ptr) {
    node_ptr -> value = value;
    node_ptr -> next = NULL;
  }
  return node_ptr;
}
