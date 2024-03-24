#include <stdio.h>

typedef int function_type(const char*, float);

int my_function(const char*, float);

int another_function (const char* str, float num) {
    printf("In another_function(\"%s\", %3.2ff).\n", str, num);
}

int main()
{
    my_function("Hello World", 1.0f);
    
    function_type *function_of_function_type = &my_function;
    (*function_of_function_type)("Hello World from (*function_of_function_type)", 2.0f);
    
    function_of_function_type = another_function;
    (*function_of_function_type)("Hello World from (*function_of_function_type) = another_function", 3.0f);

    return 0;
}

int my_function(const char* str, float num) {
    printf("In my_function(\"%s\", %3.1ff).\n", str, num);
}
