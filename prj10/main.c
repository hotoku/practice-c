#include <assert.h>
#include <stdbool.h>

int main() {
  /**
   * コンパイル時に-NDEBUGオプションが付いていると、次の式は評価されない。
   */
  assert(false);
  return 0;
}
