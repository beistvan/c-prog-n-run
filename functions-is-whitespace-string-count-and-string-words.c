int is_whitespace(char c) { return c == ' ' || c == '\t' || c == '\n'; }

int string_count(char* str) { 
    int len = 0;
    while (str[len] != '\0')
        len++;
    return len;       
}

int string_words(char* str)  {
    int words_count = 0;
    for (int i = 0; str[i] != '\0'; i++) 
        if (!is_whitespace(str[i]) && (is_whitespace(str[i + 1]) || str[i + 1] == '\0')) words_count++;
    return words_count; 
}
