#include <stdio.h>

typedef union {
  int i;
  char c[4];
} myunion;

int main() {
  myunion u;
  u.i = 1 + 2 * (1 << 8) + 3 * (1 << 16) + 4 * (1 << 24);
  // u.iを16進数で表示すると0x04030201となる。
  // x64の場合、リトルエンディアンで格納されるので、
  // メモリ上では0x01, 0x02, 0x03, 0x04の順に格納される。

  // u.iを16進数で表示
  printf("u.i = %08x\n", u.i);

  // unionを使うと、同じメモリ領域を異なる型として参照できる。
  printf("u.c[0] = %d\n", u.c[0]);
  printf("u.c[1] = %d\n", u.c[1]);
  printf("u.c[2] = %d\n", u.c[2]);
  printf("u.c[3] = %d\n", u.c[3]);

  return 0;
}
