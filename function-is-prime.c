int is_prime (int arg) {
    int flag = 1;
    if (arg == 0 || arg == 1 || arg < 0) flag = 0;
    for (int i = 2; i <= arg; i++) {
        if (!(arg % i) && i != arg) { flag = 0; break; }
    }
    return flag;
}
