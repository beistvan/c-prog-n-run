#include <stdio.h>

int read_int() {
    int res = 0; 
    scanf("%d", &res);
    return res; 
}

int main() {
    /* - прочитайте одно число i с помощью read_int
       - используя цикл while выведите числа от i до 10 включительно;
         после каждого числа должен стоять один пробел
       - если i > 10, выведите одно слово "No"
    */
    int i = read_int();
    if (i > 10)
        printf("No");
    else
        while (i < 11)
            printf("%d ", i++);
    return 0;
}
