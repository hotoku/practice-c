// ungetcでシンプルな足し算パーサーを実装してみる

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool is_digit(const char c) { return '0' <= c && c <= '9'; }
bool is_blank(const char c) {
  if (c == ' ') return true;
  if (c == '\t') return true;
  return false;
}
bool is_operator(const char c) {
  return c == '+' || c == '-' || c == '*' || c == '/';
}

int drop_blank(void) {
  int c;
  while (true) {
    if ((c = fgetc(stdin)) == EOF) return EOF;
    if (is_blank((char)c)) continue;
    ungetc(c, stdin);
    return 0;
  }
  assert(false);
}

int read_number(int *num) {
  *num = 0;
  int c;
  if ((c = fgetc(stdin)) == EOF) return EOF;
  if (!is_digit((char)c)) return EOF;
  *num = c - '0';

  while (true) {
    if ((c = fgetc(stdin)) == EOF) return EOF;
    if (is_digit((char)c)) {
      *num = *num * 10 + (c - '0');
    } else {
      ungetc(c, stdin);
      return 0;
    }
  }
  assert(false);
}

int read_operator(char *op) {
  int c;
  if ((c = fgetc(stdin)) == EOF) return EOF;
  if (is_operator((char)c)) {
    *op = (char)c;
    return 0;
  } else {
    return -1;
  }
}

int main() {
  char err_msg[256];
  drop_blank();
  int n1;
  int ret;
  if ((ret = read_number(&n1)) != 0) {
    strcpy(err_msg, "failed to read n1");
    goto panic;
  }
  drop_blank();

  char op;
  if ((ret = read_operator(&op)) != 0) {
    strcpy(err_msg, "failed to read op");
    goto panic;
  }

  drop_blank();
  int n2;
  if ((ret = read_number(&n2)) != 0) {
    strcpy(err_msg, "failed to read n2");
    goto panic;
  }

  printf("%d %c %d\n", n1, op, n2);
  exit(0);
panic:
  printf("error: %s\n", err_msg);
  exit(1);
}
