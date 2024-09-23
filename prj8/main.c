/**
 * c言語でのオブジェクト指向の例。
 * 与えられた配列が、条件を満たすかどうかを調べたい。
 * ただし、チェックすべき条件の内容は案件によって変わるので、チェックのロジックは分離して実装したい。
 * というような気持ちのサンプル。
 */

#include <limits.h>
#include <stdbool.h>
#include <stdio.h>

/**
 * バリデータのインターフェース。
 * 判断基準のパラメータとしてvoid*のdataを持つ。
 * また、判断を実行するメソッドとしてvalidateを持つ。
 * validateが、チェック対象の値valの他に、selfを引数に持っている。
 * これによって、validate内でdataを参照できる。
 * ただ、void*を使っているので、dataの型はvalidate内でキャストする必要があり、コンパイル時の型チェックができない。
 */
typedef struct Validator {
  bool (*validate)(struct Validator *self, int val);
  void *data;
} Validator;

bool allok(Validator *self, int x) { return 1; }

typedef struct {
  int min;
  int max;
} range;
bool range_check(Validator *self, int x) {
  range *r = (range *)self->data;
  return r->min <= x && x <= r->max;
}
bool ascendant(Validator *self, int x) {
  int *prev = (int *)self->data;
  if (x < *prev) {
    return false;
  }
  *prev = x;
  return true;
}

bool check(int *arr, size_t len, Validator *validator) {
  for (size_t i = 0; i < len; i++) {
    if (!validator->validate(validator, arr[i])) {
      return false;
    }
  }
  return true;
}

int main() {
  range r = {0, 3};
  int last_val = INT_MIN;

  Validator v_allok = {allok, NULL};
  Validator v_range = {range_check, &r};
  Validator v_ascendant = {ascendant, &last_val};

  int range_ng[] = {0, 1, 100};
  int ascendant_ng[] = {1, 2, 1};

  Validator *validators[] = {&v_allok, &v_range, &v_ascendant};
  int *data[3] = {range_ng, ascendant_ng};
  for (size_t i = 0; i < 2; i++) {
    for (size_t j = 0; j < 3; j++) {
      const bool ret = check(data[i], 3, validators[j]);
      printf("%d\t", ret);
    }
    printf("\n");
  }

  return 0;
}
