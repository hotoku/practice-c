/**
 * テンプレートメソッドパターン その2
 * - 複数のポインタを管理する
 * - 引数や返り値を複数持てる
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct object_holder {
  void **objects;
  size_t size;
  void (*processor)(void *);
} object_holder;

void run_and_free(object_holder *holder) {
  holder->processor(holder);

  for (size_t i = 0; i < holder->size; i++) {
    free(holder->objects[i]);
  }
}

typedef struct {
  void **objects;
  size_t size;
  void (*processor)(void *);
  size_t n;
  double *sumproduct;
} sumproduct_context;

void sumproduct_processor(void *context) {
  sumproduct_context *ctx = (sumproduct_context *)context;
  double *x = (double *)ctx->objects[0];
  double *y = (double *)ctx->objects[1];
  *ctx->sumproduct = 0;
  for (size_t i = 0; i < ctx->n; i++) {
    *ctx->sumproduct += x[i] * y[i];
  }
}

int main() {
  size_t n = 3;
  double *x = (double *)malloc(sizeof(double) * n);
  double *y = (double *)malloc(sizeof(double) * n);
  for (size_t i = 0; i < 3; i++) {
    x[i] = i;
    y[i] = i;
  }
  void *objects[2] = {x, y};
  double sumproduct = 0;
  sumproduct_context ctx = {objects, 2, sumproduct_processor, n, &sumproduct};
  sumproduct_processor(&ctx);
  printf("%f\n", sumproduct);

  return 0;
}
