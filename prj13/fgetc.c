#include <stdio.h>
#include <stdlib.h>

int main() {
  char c;
  while ((c = fgetc(stdin)) != EOF) {
    fputc(c, stdout);
  }
  exit(0);
}
