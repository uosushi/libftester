#include <stdio.h>
#include <string.h>
#include <malloc/malloc.h>
#include <errno.h>
#include "../../libft.h"

/* Memory leaks */
void	leak_detect_init(void);
void	*leaks_malloc(size_t, const char*, unsigned int);
void	leak_detect_free(void*);
void	leaks_check(void);

#define init leak_detect_init
#define malloc(s) leaks_malloc(s, __FILE__, __LINE__)
#define free leak_detect_free
#define leaks leaks_check

#define OK "\033[32m[OK]\033[39m"
#define KO "\033[31m[KO]\033[39m"
#define MOK "\033[32m[MOK]\033[39m"
#define MKO "\033[31m[MKO]\033[39m"
#define POK "\x1b[37m[PROTECTED]\033[39m"
#define PKO "\033[31m[NO PROTECTED]\033[39m"

extern int	g_case;
extern int	g_debug;

#define evaluation(eval, description) printf(" %02d %s %s\n", g_case++, eval, description);

extern char	input[50];
extern char	ex[50];
extern char	ft[50];