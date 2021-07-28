#include <stdio.h>
#include <string.h>
#include "libft.h"

#define OK "\033[32m[OK]\033[39m"
#define KO "\033[31m[KO]\033[39m"

void	atoi_main(void);
void	calloc_main(void);
void	strrchr_main(void);

void	detail(char *input, char *ex, char *output);

int	g_case = 1;
int	g_detail = 1;

char	*input;
char	*ex;
char	*output;

const char	*fname[] =
{
	"atoi",
	"calloc",
	"strrchr"
};
void	(*f_mains[])() = 
{
	atoi_main,
	calloc_main,
	strrchr_main
};

int	main(int argc, char const *argv[])
{
	int			i;

	if (argc == 3)
	{
		if (strcmp(argv[2], "-d") == 0)
			g_detail = 0;
	}
	printf("[Mondatory]\n");
	i = 0;
	while (f_mains[i])
	{
		if (argc == 1 || strcmp(argv[1], fname[i]) == 0)
		{
			g_case = 1;
			f_mains[i]();
		}
		i++;
	}
	return (0);
}

void	check(char *description, int b)
{
	printf("CASE %d [%s] %s\n", g_case++, description, b ? OK : KO);
	if (g_detail)
	{
		detail(input, ex, output);
	}
}

void	detail(char *input, char *ex, char *output)
{
	if (g_detail)
	{
		printf(" INPUT	  : %s\n", input);
		printf(" EXPECTED : %s\n", ex);
		printf(" OUTPUT	  : %s\n", output);
		printf("\n");
	}
}

int		ATOI(const char *str)
{
	input = malloc(50);
	ex = malloc(50);
	output = malloc(50);
	sprintf(input, "%s", str);
	sprintf(ex, "%d", atoi(str));
	sprintf(output, "%d", ft_atoi(str));
	return (ft_atoi(str) == atoi(str));
}

void	atoi_main(void)
{
	check("Conversion error", ATOI(" &000123   "));
	check("Conversion error", ATOI("           "));
	check("in space",         ATOI(" 12&3456   "));
	check("INT_MAX - 1",      ATOI(" 2147483646"));
	check("INT_MAX",          ATOI(" 2147483647"));
	check("INT_MAX + 1",      ATOI(" 2147483648"));
	check("INT_MAX + 2",      ATOI(" 2147483649"));
	check("INT_MIN + 1",      ATOI("-2147483647"));
	check("INT_MIN",          ATOI("-2147483648"));
	check("INT_MIN - 1",      ATOI("-2147483649"));
	check("",                 ATOI(" 63410682753376583680"));
	check("",                 ATOI("-63410682753376583680"));
	check("LONG_MAX - 2",     ATOI(" 9223372036854775805"));
	check("LONG_MAX - 1",     ATOI(" 9223372036854775806"));
	check("LONG_MAX",         ATOI(" 9223372036854775807"));
	check("LONG_MAX + 1",     ATOI(" 9223372036854775808"));
	check("LONG_MAX + 2",     ATOI(" 9223372036854775809"));
	check("LONG_MIN + 3",     ATOI("-9223372036854775805"));
	check("LONG_MIN + 2",     ATOI("-9223372036854775806"));
	check("LONG_MIN + 1",     ATOI("-9223372036854775807"));
	check("LONG_MIN",         ATOI("-9223372036854775808"));
	check("LONG_MIN - 1",     ATOI("-9223372036854775809"));
	check("Zero padding",     ATOI("+0000000000123456789"));
}

#define CALLOC(count, size) check_calloc(count, size)

static int	check_calloc(size_t count, size_t size)
{
	void	*tmpex = calloc(count, size);
	void	*tmpmy = ft_calloc(count, size);

	input = malloc(50);
	ex = malloc(50);
	output = malloc(50);
	sprintf(input, "!calloc(%zu, %zu)", count, size);
	sprintf(ex, "%d", !tmpex);
	sprintf(output, "%d", !tmpmy);
	free(tmpex);
	free(tmpmy);
	return (ex == output);
}

void	calloc_main(void)
{
	check("Normal input", !CALLOC(100, 8));
	check("Zero",         !CALLOC(1, 0));
	check("SIZE_MAX",     !CALLOC(SIZE_MAX, 1));
	check("Wrap around",  !CALLOC(SIZE_MAX, 8));
}

int	STRRCHR(const char *s, int c)
{
	input = malloc(256);
	sprintf(input, "%s, %c", s, c);
	output = ft_strrchr(s, c);
	ex = strrchr(s, c);
	return (ex == output);
}

void	strrchr_main(void)
{
	check("Match head",   STRRCHR("42Tokyo", '4'));
	check("Match i=2",    STRRCHR("42Tokyo", 'T'));
	check("Zero",         STRRCHR("42Tokyo", 0));
	check("Out of range", STRRCHR("42Tokyo", 257));
}
