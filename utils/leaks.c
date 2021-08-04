#include "leaks.h"

/* メモリ管理配列を初期化する関数 */
void	leak_detect_init(void){
	int	i;

	i = 0;
	while (i < N)
	{
		mem_info[i].ptr = NULL;
		mem_info[i].size = 0;
		mem_info[i].file = NULL;
		mem_info[i].line = 0;
		i++;
	}
}

/* メモリ確保とそのメモリの情報を記録する関数 */
void	*leaks_malloc(size_t size, const char *file, unsigned int line){
	int		i = 0;
	void	*ptr = NULL;

	/* まずはメモリを確保 */
	ptr = malloc(size);

	/* メモリ確保に失敗した場合はメモリ管理構造体には情報を格納しない */
	if(ptr == NULL){
		return NULL;
	}

	for(i = 0; i < N; i++){
		/* 情報が格納されていない要素にメモリの情報を格納 */
		if(mem_info[i].ptr == NULL){
			mem_info[i].ptr = ptr;
			mem_info[i].size = size;
			mem_info[i].file = file;
			mem_info[i].line = line;
			break;
		}
	}

	/* 確保したメモリのアドレスを返却 */
	return ptr;
}

/* メモリの確保とそのアドレスのメモリ情報を記録から削除する関数 */
void leak_detect_free(void *ptr){
	int	i;

	i = 0;
	while (i < N)
	{
		/* free しようとしているアドレスのメモリ構造体を探す */
		if(mem_info[i].ptr == ptr){
			/* そのメモリはちゃんと解放されるのでその構造体の情報を消す */
			mem_info[i].ptr = NULL;
			mem_info[i].size = 0;
			mem_info[i].file = NULL;
			mem_info[i].line = 0;
			break ;
		}
		i++;
	}

	/* メモリを解放 */
	free(ptr);
}

/* 解放が行われていないメモリの情報を表示する関数 */
void	leaks_check(int case_i)
{
	int	leak;
	int	i;

	leak = 0;
	i = 0;
	while (i < N)
	{
		/* 情報が消されていないメモリ管理構造体を探す */
		if(mem_info[i].ptr != NULL)
		{
			/* 情報が消されていない構造体の ptr が指すメモリは解放忘れ */
			printf(" %02d | \033[31mLKO\033[39m\n", case_i);
			printf("Error: Memory leak! (%s, line: %u)\n", mem_info[i].file, mem_info[i].line);
			printf("[ address ] %p\n", mem_info[i].ptr);
			printf("[  size   ] %u\n", (unsigned int)mem_info[i].size);
			leak = 1;
		}
		i++;
	}
	if (!leak)
		printf(" %02d \033[32mLOK\033[39m\n", case_i);
}