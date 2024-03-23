union u {
   int64_t a;
   int32_t as_32[2];
   char raw[64];
};

int main () {
   printf("%zu", sizeof( union u ) ); // 64
   return 0;
}
