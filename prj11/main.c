#include <stdio.h>

int main() {
  int x = 1 + 2 * (1 << 8) + 3 * (1 << 16) + 4 * (1 << 24);
  // xを16進数で表示すると0x04030201となる。
  // x64の場合、リトルエンディアンで格納されるので、
  // メモリ上では0x01, 0x02, 0x03, 0x04の順に格納される。
  printf("x = %08x\n", x);

  char *px = (char *)(&x);
  printf("px[0] = %d\n", px[0]);
  printf("px[1] = %d\n", px[1]);
  printf("px[2] = %d\n", px[2]);
  printf("px[3] = %d\n", px[3]);
  return 0;
}
