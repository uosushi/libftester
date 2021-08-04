#include <stdio.h>
#include <string.h>
#include <malloc/malloc.h>
#include "../../libft.h"

/* Memory leaks */
void	leak_detect_init(void);
void	*leaks_malloc(size_t, const char*, unsigned int);
void	leak_detect_free(void*);
void	leaks_check(int case_i);

#define init leak_detect_init
#define malloc(s) leaks_malloc(s, __FILE__, __LINE__)
#define free leak_detect_free
#define leaks(i) leaks_check(i)

#define OK "\033[32mOK\033[39m"
#define KO "\033[31mKO\033[39m"
#define MOK "\033[32mMOK\033[39m"
#define MKO "\033[31mMKO\033[39m"
#define LOK "\033[32mLOK\033[39m"
#define LKO "\033[31mLKO\033[39m"

#define evaluation(eval, description) printf(" %02d | %s | %s\n", g_case++, eval, description);

extern int	g_case;
extern int	g_debug;

extern char	input[50];
extern char	ex[50];
extern char	output[50];