/**
 * テンプレートメソッドパターン その2
 * - 複数のポインタを管理する
 * - 引数や返り値を複数持てる
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct object_holder {
  void **objects;
  size_t n_objects;
} object_holder;

typedef void (*object_processor)(void *);
void run_and_free(void *holder_, object_processor processor) {
  object_holder *holder = (object_holder *)holder_;
  processor(holder);

  printf("releasing objects\n");
  for (size_t i = 0; i < holder->n_objects; i++) {
    free(holder->objects[i]);
  }
}

typedef struct {
  void **objects;
  size_t n_objects;
  size_t n;
  double *sumproduct;
} sumproduct_context;

void sumproduct_processor(void *self_) {
  sumproduct_context *self = (sumproduct_context *)self_;
  double *x = (double *)self->objects[0];
  double *y = (double *)self->objects[1];
  *self->sumproduct = 0;
  for (size_t i = 0; i < self->n; i++) {
    *self->sumproduct += x[i] * y[i];
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
  sumproduct_context ctx = {objects, 2, n, &sumproduct};
  run_and_free(&ctx, sumproduct_processor);
  printf("%f\n", sumproduct);

  return 0;
}
