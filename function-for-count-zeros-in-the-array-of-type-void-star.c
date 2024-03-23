size_t count_zeroes( const void* data, size_t sz ) {
    size_t cnt = 0;
    for (size_t i = 0; i < sz; i++)
        if (*((char*) data + i) == 0)
            cnt++;
    return cnt;
}
