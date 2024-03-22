// Returns 1 if number has one digit, otherwise 0
int is_single_digit(int n) {
    if (n < 0) { 
        return 0;
    } 
    if (n > 9) {
            return 0;
    }
    if (n <= 9 || n >= 0) {
        return 1;
    }
}

// Returns 1 if number has two digits, otherwise 0
int is_double_digit(int n) {
    if (n < 10) { 
        return 0;
    } 
    else {
        if (n > 99) {
            return 0;
        }
        else {
            if (n <= 99 || n >= 10) {
                return 1;
            }
        }
    }
}
