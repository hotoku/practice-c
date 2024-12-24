#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
  const char* path = "/tmp/test.txt";
  unlink(path);

  // 存在しないファイルなので失敗する。-1が返るはず
  int fd = open(path, O_WRONLY);
  printf("fd=%d\n", fd);

  // 存在しない場合は作成する。
  fd = open(path, O_WRONLY | O_CREAT, 0644);
  printf("fd=%d\n", fd);

  if (write(fd, "Hello, world!\n", 14) < 0) goto panic;
  close(fd);

  if ((fd = open(path, O_RDONLY)) < 0) goto panic;

  char buf[1024];
  ssize_t ret;
  if ((ret = read(fd, buf, sizeof buf - 1)) < 0) goto panic;
  buf[ret] = '\0';
  printf("buf=%s\n", buf);

  exit(0);

panic:
  close(fd);
  exit(1);
}
