#ifndef LEAKDETECT_H
#define LEAKDETECT_H

#include <stdio.h>
#include <stdlib.h>

/* 管理数の上限 */
#define MAX_NUM 500

#define LOK "\033[32m[LOK]\033[39m"
#define LKO "\033[31m[LKO]\033[39m"

#define evaluation(eval, description) printf(" %02d %s %s\n", g_case++, eval, description);

/* メモリ管理構造体 */
typedef struct {
	void *ptr;
	size_t size;
	const char *file;
	unsigned int line;
} MEM_T;

/* 管理するメモリの情報の最大数 */
#define N 500

/* メモリ情報を格納する構造体の配列 */
MEM_T mem_info[N];
int	g_leaki;

extern int g_case;

#endif
