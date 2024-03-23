enum either_type { ET_INT, ET_STRING };

struct either_int_string {
  enum either_type type;
  union {
    char* as_string;
    int64_t as_int;
  };
};


struct either_int_string either_from_string(char* s) {
    return (struct either_int_string) {
        .type = ET_STRING,
        .as_string = s
    };
}
struct either_int_string either_from_int(int64_t i) {
    return (struct either_int_string) {
        .type = ET_INT,
        .as_int = i
    };
}

void either_int_string_destroy(struct either_int_string e) {
    if (e.type == ET_STRING) {
        free(e.as_string);
    }
}

void print(struct either_int_string e) {
  switch (e.type) {
  case ET_INT: {
       printf("Int %" PRId64, e.as_int);
       break;
  }
  case ET_STRING: {
       printf("String %s", e.as_string);  
       break;
  }
  default: {
      break;
  }
  }
}
