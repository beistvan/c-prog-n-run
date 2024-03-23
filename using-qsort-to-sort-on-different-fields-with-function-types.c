typedef struct { char* addr; } string_heap ;

typedef uint64_t uid;
#define PRI_uid PRIu64
#define SCN_uid SCNu64

enum city {C_SARATOV, C_MOSCOW, C_PARIS, C_LOS_ANGELES, C_OTHER};

const char* city_string[] = {
  [C_SARATOV] = "Saratov",
  [C_MOSCOW] = "Moscow",
  [C_PARIS] = "Paris",
  [C_LOS_ANGELES] = "Los Angeles",
  [C_OTHER] = "Other"
};


struct user {
  const uid id;
  const string_heap name;
  enum city city;
};

size_t string_length(const char* s) {
    size_t length = 0;
    while(*s != 0) {
        ++length;
        ++s;
    }
    return length;
}

char* copy_string(const char* s) {
    size_t length = string_length(s);
    char* result = malloc(sizeof(char)*(length+1));
    for (size_t i = 0; i <= length; ++i) {
        result[i] = s[i];
    }
    return result;
}

string_heap halloc( const char* s ) {
    return (string_heap) {.addr = copy_string(s)};
}

void heap_string_free( string_heap h ) {
    free(h.addr);
}

int users_sort_uid_func(const void* a, const void* b) {
    struct user userA = *((struct user*) a);
        struct user userB = *((struct user*) b);
        if (userA.id > userB.id)
            return 1;
        else if (userB.id > userA.id)
            return -1;
        else
            return 0;
}

int compare_strings(const string_heap a, const string_heap b) {
    size_t i = 0;
    while (a.addr[i] != 0 && b.addr[i] != 0) {
        if (a.addr[i] > b.addr[i])
            return 1;
        if (a.addr[i] < b.addr[i])
            return -1;
        ++i;
    }
    if (a.addr[i] != 0)
        return 1;
    if (b.addr[i] != 0)
        return -1;
    return 0;
}

int users_sort_name_func(const void* a, const void* b) {
    struct user userA = *((struct user*) a);
    struct user userB = *((struct user*) b);
    return compare_strings(userA.name, userB.name);
}

int compare_cities(enum city cityA, enum city cityB) {
    string_heap cityA_name = halloc(city_string[cityA]);
    string_heap cityB_name = halloc(city_string[cityB]);
    int result = compare_strings(cityA_name, cityB_name);
    heap_string_free(cityA_name);
    heap_string_free(cityB_name);
    return result;
}

int users_sort_city_func(const void* a, const void* b) {
    struct user userA = *((struct user*) a);
    struct user userB = *((struct user*) b);
    return compare_cities(userA.city, userB.city);
}

void users_sort_uid(struct user users[], size_t sz) {
  qsort(users, sz, sizeof(struct user), users_sort_uid_func);
}

void users_sort_name(struct user users[], size_t sz) {
  qsort(users, sz, sizeof(struct user), users_sort_name_func);
}

void users_sort_city(struct user users[], size_t sz) {
  qsort(users, sz, sizeof(struct user), users_sort_city_func);
}
