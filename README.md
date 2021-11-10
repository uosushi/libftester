# Libftester
鋭意作成中ですが、利用できます
Makefileを使わないバージョンは[こちら](https://github.com/uosushi/libftester/tree/a8923ef93477d8ead6ee9985e31af9bab7198617)へどうぞ。

## Usage
### Install
```
cd Libft
git clone https://github.com/uosushi/libftester.git
```
### Run
```
cd libftester
```
```bash
# func_name に該当する関数のみをテスト（ft_はいらない）
make func_name

# テストケースと結果の詳細を表示する
make func_name DETAIL=1
```

## Functions
- [x] test (debug)
- [ ] memset
- [ ] bzero
- [ ] memcpy
- [ ] memmove
- [ ] memchr
- [ ] memcmp
- [ ] strlen
- [ ] isalpha
- [ ] isdigit
- [ ] isalnum
- [ ] isascii
- [ ] isprint
- [ ] toupper
- [ ] tolower
- [ ] strchr
- [x] strrchr
- [ ] strncmp
- [x] strlcpy
- [x] strlcat
- [ ] strnstr
- [x] atoi
- [x] calloc
- [ ] strdup
- [ ] substr
- [ ] strjoin
- [ ] strtrim
- [x] split
- [ ] itoa
- [ ] strmapi
- [ ] putchar_fd
- [ ] putstr_fd
- [ ] putendl_fd
- [ ] putnbr_fd
- [ ] striteri

# 未実装（エラーを起こすため実質まだ動かせないオプション）
```bash
# mandatory part をテスト
make m

# bonus part をテスト
make b
```