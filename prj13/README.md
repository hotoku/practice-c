# futsu-no-linux

入出力関係をまとめる

## システムコール

### `read`

`ssize_t read(int fd, void *buf, size_t bufsize)`

**返り値**：読み込んだ文字数 or 終端に達していたら 0 or エラーが起きたら-1。

読み込んだバイトをそのまま buf にコピーするだけで、0 終端はしないので注意。

### `write`

`ssize_t write(int fd, const void *buf, size_t bufsize)`

**返り値**：書き込んだ文字数 or エラーが起きたら-1。

### `open`

- `int open(const char* path, int flags)`
- `int open(const char* path, int flags, mode_t mode)`

**返り値**：ファイルディスクリプタ or エラーが起きたら-1。

**引数**：

- `flags` 読み込み専用か、とか、ファイルが存在しないときにどうするか、とか。詳細は使うときに調べる
- `mode` 作成する場合のファイルのパーミッション。umask が絡んでくるので注意。

## stdio ライブラリ

システムコールでは、ただの int 型のファイルディスクリプタでストリームを識別していたが、stdio の世界には`FILE`構造体がある。

また、システムコールでは指定された分だけの読み書きを愚直にストリームに対して行うが、stdio ライブラリの関数は、内部でバッファリングを行う。実際にシステムコールを行ってストリームへの読み書きを行うのはコストが高いが、ある程度の量をバッファにためておけばメモリの読み書きだけで済むので効率が上がる。

### 標準入出力

ファイルディスクリプタの既定の値として、`unistd.h`に

- `STDIN_FILENO`
- `STDOUT_FILENO`
- `STDERR_FILENO`

が定義されていた。同じように、`stdio.h`をインクルードすると、

- `stdin`
- `stdout`
- `stderr`

という`FILE*`型の変数が使える。

### `fgetc`

`int fgetc(FILE *stream)`

**返り値**：読み込んだ文字。char じゃなくて int なのは、ストリームの終わり or エラーの場合は EOF が返るから。

### `fputc`

`int fputc(int c, FILE *stream)`

**返り値**：書き込んだ文字。エラーの場合は EOF。char じゃなくて int なのは、fgetc の返り値をそのまま使えるように。

### `fopen`

- `FILE *fopen(const char *path, const char *mode)`

`mode`は、`"r"`, `"w"`, `"a"`とか。他にもあるが、細かいことは使うときに調べる。

**返り値**: 成功したら`FILE*`ポインタ。失敗したら NULL。

### `fclose`

- `int fclose(FILE *stream)`

**返り値**: 失敗したら EOF。成功したときは、気にしなくてよいだろう。

### `getc` `putc` `getchar` `putchar`

`getc`, `putc`は略。`fgetc`, `fputc`を使っとけばよい。`getchar`, `putchar`は、入出力の相手を標準入出力に固定したもの。

### `ungetc`

`int ungetc(int c, FILE *stream)`

`c`をストリームに戻す。ただし、1 文字しか戻せない。

**返り値**: 成功したら`c`。失敗したら EOF。
