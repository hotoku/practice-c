// テンプレートメソッドパターンによってファイルの確保・解放と、ファイル内容に対する処理を分離する

#include <stdio.h>

typedef int (*file_processor)(FILE *);

int read_file(const char *filename, file_processor processor) {
  FILE *file = fopen(filename, "r");
  if (file == NULL) {
    return -1;
  }
  int result = processor(file);
  fclose(file);
  return result;
}

/**
 * ファイルから最大値と最小値の差を計算する
 */
int calc_range(FILE *file) {
  int min = 1000000;
  int max = -1000000;
  int x;
  while (fscanf(file, "%d", &x) != EOF) {
    if (x < min) {
      min = x;
    }
    if (x > max) {
      max = x;
    }
  }
  return max - min;
}

int main() {
  int result = read_file("prj7/data.txt", calc_range);
  if (result == -1) {
    printf("ファイルが開けませんでした\n");
  } else {
    printf("最大値と最小値の差は %d です\n", result);
  }
  return 0;
}
