これは落書き。あとで整形する。

## c 言語についての疑問・覚書

### 外部からの入力で構造体を初期化したいときはどうするか

```
typedef struct {
  int length;
  double[] rii;
} rii_values;
```

みたいな構造体があったとして、この情報をファイルから読み込んで初期化したい、とする。rii の長さが不明の場合、動的に確保した rii を渡さないといけない。
が、この rii を適切に解放するのは難しくない・・？

シンプルな解決策は、最大長を定義してそこまで予めメモリを確保しておいて、それ以上は無視すること。その欠点は、最大長を長くし過ぎると、無駄が多いこと。

真面目にやるなら、GC などのメモリ管理の仕組みを実装する必要がある。大変。

しかし、構造体に配列をもたせるときに常に定数になっちゃうのはかなりしんどいな。

現実的な解決策としては、この構造体は常にポインタで扱うようにする。で、create してポインタを返す関数と destruct する関数を用意して、常にこれらの関数で確保/解放をする。
なるほど、ほとんどコンストラクタとデストラクタだ。

[この例](https://github.com/kgabis/parson/blob/ba29f4eda9ea7703a9f6a9cf2b0532a2605723c3/parson.c#L746)では、簡易的な vector みたいなものを定義している。
リサイズの関数を用意しておき、メモリ確保に失敗したら呼び出し元に失敗を知らせる、みたいな感じ。
こんな感じで、失敗する可能性があるものは常に、それを意識して書く、しか解決策はないっぽい。
しかし、例外を投げられない環境で、失敗をどう扱えば良いのか・・というと。
帯域脱出が return しかないので、`return 失敗値`みたいなコードを書くしかない。
もしくは、`goto panic`か。

### サンプルコードをさがす

- csv パーサ
  - https://koturn.hatenablog.com/entry/2021/04/05/200000
- json パーサ
  - https://github.com/kgabis/parson/blob/master/parson.c#L746
- 本のサンプルコード（ゲーム）
  - https://book.impress.co.jp/books/1122101108
- json パーサの例が色々
  - https://ken-ohwada.hatenadiary.org/entry/2022/07/26/130045

## 覚書

.c で、static な関数や static なグローバル変数は、他のファイルからは見えなくなる。疑問: static がついてないとバッティングするのか・・？

`typedef struct {int x;} hoge` みたいな形で定義すると、利用するときに struct キーワードを書かなくて良い。