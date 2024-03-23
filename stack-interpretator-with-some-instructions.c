enum opcode { BC_PUSH, BC_IPRINT, BC_IREAD, BC_IADD, BC_STOP };

struct bc_noarg {
  enum opcode opcode;
};
struct bc_arg64 {
  enum opcode opcode;
  int64_t arg;
};
union ins {
  enum opcode opcode;
  struct bc_arg64 as_arg64;
  struct bc_noarg as_noarg;
};

/* ------------------------ */

struct vm_state {
  const union ins *ip;
  struct stack data_stack;
};

struct vm_state state_create(const union ins *ip) {
  return (struct vm_state){.ip = ip,
                           .data_stack = stack_create(STACK_CAPACITY)};
}

void state_destroy(struct vm_state *state) {
   stack_destroy(&state->data_stack);
}


void print_int64(int64_t);
struct maybe_int64 maybe_read_int64();

struct stack stack_create(size_t size);
void stack_destroy(struct stack *s);
bool stack_push(struct stack *s, int64_t value);
struct maybe_int64 stack_pop(struct stack *s);

void interpret(struct vm_state *state) {
    bool _continue = true;
    size_t ip_pos = 0;
    while(_continue) {
       struct stack* s = &(state->data_stack);
       switch((state->ip)[ip_pos].opcode) {
           case (BC_IREAD): {
               struct maybe_int64 n = maybe_read_int64();
               if (n.valid) {
                   stack_push(s, n.value);
               }
           break;} 
           case (BC_IPRINT): {
               struct maybe_int64 n = stack_pop(s);
               if (n.valid) {
                   print_int64(n.value);
               }
           break;}
           case (BC_PUSH): {
               int64_t n = (state->ip)[ip_pos].as_arg64.arg;
               stack_push(s, n);
           break;}
           case (BC_IADD): {
               struct maybe_int64 a = stack_pop(s);
               struct maybe_int64 b = stack_pop(s);
               if (a.valid && b.valid)
                   stack_push(s, a.value+b.value);
           break;}
           case (BC_STOP): {
               _continue = false;
           break;}
           default: {
               // ????
           }
       }
       ip_pos += 1;
   }
}

void interpret_program(const union ins *program) {
  struct vm_state state = state_create(program);
  interpret(&state);
  state_destroy(&state);
}
