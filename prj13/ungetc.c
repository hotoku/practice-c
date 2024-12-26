#include <stdio.h>
#include <stdlib.h>

int main() {
  FILE *input = fopen("prj13/ungetc.c", "r");

  char buf[2];
  buf[1] = '\0';

  int c = fgetc(input);
  int ret = ungetc(c, input);
  buf[0] = (char)ret;
  printf("ret=%s\n", buf);

  fclose(input);
  exit(0);
}
