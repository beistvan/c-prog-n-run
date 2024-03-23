struct maybe_int64 list_at( const struct list* list, size_t idx ) {
    if (!list || list_length(list) == 0 || list_length(list) <= idx || idx < 0) return none_int64;
    size_t index = 0;
    while (index++ != idx && list -> next) {
        list = list -> next;
    }
    return some_int64(list -> value);
    
}
