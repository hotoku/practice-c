#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int main() {
  int data_file = open("prj13/data.txt", O_RDONLY);
  char buf[1024];

  // data.txtは小さいので、一撃で全部読める。10文字読むはず
  ssize_t ret = read(data_file, buf, 1024);
  printf("ret=%ld\n", ret);

  // すでにEOFに達しているので、0が返る
  ret = read(data_file, buf, 1024);
  printf("ret=%ld\n", ret);

  // 変なファイルディスクリプタを指定すると、-1が返る
  ret = read(100, buf, 1024);
  printf("ret=%ld\n", ret);
  printf("errno=%d\n", errno);
  perror("read");

  close(data_file);
  return 0;
}
