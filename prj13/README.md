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
