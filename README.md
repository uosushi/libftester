# Libftester
作成中です

# 使用方法
```
gcc 必要なファイル.c main.c
./a.out 関数名
```
何も指定しなければ全て実行される  
2つめの引数に`-d`をつけると詳細を表示しない

# 使用例
```
gcc main.c ft_calloc.c ft_bzero.c ft_atoi.c ft_strlen.c ft_strrchr.c
# detailなし
./a.out strrchr -d
# detailあり
./a.out strrchr
```