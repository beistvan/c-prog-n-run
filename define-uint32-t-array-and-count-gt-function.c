uint32_t data[8*1024*1024] = {0};

size_t count_gt(uint32_t * array, size_t size) {
    size_t count = 0;
    for (size_t i = 0; i < size; i++)
        if (data[i] > LIMIT) count++;
    return count;
}
