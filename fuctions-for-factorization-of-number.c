int is_more_then_one(int n) {
    if (n > 1){
        return 1;
    } 
    return 0;
}

int divides(int a, int b) { 
    return a % b == 0;
}

int is_prime(int n) { 
    if (!is_more_then_one(n)) { 
        return 0;
    } 
    for( int i = 1; i <= n/2; i++ ) { 
        if (divides(n, i)) { 
            if(i != 1 && i != n) {
                return 0;}
        }
    } 
    return 1;
}

void factorize( int n, int* a, int* b )
{ 
    *a = 0;  
    *b = 0; 
    if (n == 1 || is_prime(n)) {
        *a = 1; *b = n;
    }  
    if (!is_prime(n)) {  
        int i = 2;
        while (n > 1) {  
            if (divides(n, i)) {  
                if(*a == 0) {
                    *a = i; n = n / i;
                } else if (*b == 0) {
                    *b = i; n = n / i;
                } else if (*b > 0) {
                    *b = *b * i; 
                    n = n / i;
                }
            } else {
                i += 1;
            }
        }
    }
}

