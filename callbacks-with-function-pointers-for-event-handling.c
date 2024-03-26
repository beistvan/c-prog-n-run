#include <inttypes.h>
#include <stdio.h>

struct context { int64_t counter; };

struct button {
  const char* label;
  void (*handler)( const struct button*, struct context* );
};

typedef void (onclick_handler)(struct button*, struct context*);

struct buttons { struct button* array; size_t count; } ;

size_t read_size() { size_t sz = 0; scanf("%zu", &sz); return sz; }

void click(const struct button* b, struct context* ctx) {
  b->handler( b, ctx );
}

void print_meow_handler(const struct button* b, struct context* ctx) {
  printf("Meow!\n");
  ctx-> counter = ctx-> counter + 1;
}

void print_ctx_handler(const struct button* b, struct context* c) {
  printf("Said \"Meow!\" %" PRId64 " times.\n", c->counter );
}

void print_buttons( struct buttons buttons ) {
  for (size_t i = 0; i < buttons.count; i = i + 1 ) {
    printf("%zu : %s \n", i, buttons.array[i].label );
  }
}

void prompt_click_button( struct buttons buttons, struct context* ctx ) {
  for(;;) {
    print_buttons( buttons );
    printf("Input button index: ");
    const size_t idx = read_size();
    if ( idx >= buttons.count ) { printf("No such button, bye.\n"); break; }
    else { click( buttons.array + idx, ctx ); }
  }
}


int main() {

  struct button buttons[] = {
    { "Say Meow" , print_meow_handler },
    { "Status", print_ctx_handler },
  };

  const size_t count = sizeof(buttons) / sizeof(buttons[0]);

  struct context ctx = { 0 };

  prompt_click_button( (struct buttons) { buttons, count } , &ctx );

  return 0;
}

/*
Output:

0 : Say Meow 
1 : Status 
Input button index: 0
Meow!
0 : Say Meow 
1 : Status 
Input button index: 1
Said "Meow!" 1 times.
0 : Say Meow 
1 : Status 
Input button index: 2
No such button, bye.
*/
