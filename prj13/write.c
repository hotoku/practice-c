#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

int main() {
  const char *buf = "Hello, world!\n";
  const int len = strlen(buf);

  ssize_t ret = write(STDOUT_FILENO, buf, len);
  printf("ret=%ld\n", ret);

  return 0;
}
