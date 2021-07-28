#include <stdio.h>
#include <string.h>
#include "libft.h"

#define OK "\033[32m[OK]\033[39m"
#define KO "\033[31m[KO]\033[39m"

void	atoi_main(void);
void	calloc_main(void);

int	g_case_i = 1;
int	g_detail = 1;

const char	*fname[2] =
{
	"atoi",
	"calloc"
};
void	(*f_mains[])() = 
{
	atoi_main,
	calloc_main
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
			f_mains[i]();
		i++;
	}
	return (0);
}

static void	check_atoi(const char *str, const char *description)
{
	int	ex = atoi(str);
	int	my = ft_atoi(str);
	printf("CASE %d [%s] %s\n", g_case_i++, description, ex == my ? OK : KO);
	if (g_detail)
	{
		printf(" INPUT	  : \"%s\"\n", str);
		printf(" EXPECTED : %d\n", ex);
		printf(" OUTPUT	  : %d\n\n", my);
	}
}

void	atoi_main(void)
{
	check_atoi(" &000123 ", "Conversion error");
	check_atoi("         ", "Conversion error");
	check_atoi(" 12&3456 ", "in is_space");
	check_atoi(" 2147483646", "INT_MAX - 1");
	check_atoi(" 2147483647", "INT_MAX");
	check_atoi(" 2147483648", "INT_MAX + 1");
	check_atoi(" 2147483649", "INT_MAX + 2");
	check_atoi("-2147483647", "INT_MIN + 1");
	check_atoi("-2147483648", "INT_MIN");
	check_atoi("-2147483649", "INT_MIN - 1");
	check_atoi(" 63410682753376583680", "");
	check_atoi("-63410682753376583680", "");
	check_atoi(" 9223372036854775805", "LONG_MAX - 2");
	check_atoi(" 9223372036854775806", "LONG_MAX - 1");
	check_atoi(" 9223372036854775807", "LONG_MAX");
	check_atoi(" 9223372036854775808", "LONG_MAX + 1");
	check_atoi(" 9223372036854775809", "LONG_MAX + 2");
	check_atoi("-9223372036854775805", "LONG_MIN + 3");
	check_atoi("-9223372036854775806", "LONG_MIN + 2");
	check_atoi("-9223372036854775807", "LONG_MIN + 1");
	check_atoi("-9223372036854775808", "LONG_MIN");
	check_atoi("-9223372036854775809", "LONG_MIN - 1");
	check_atoi("+0000000000123456789", "Zero padding");
}

#define CALLOC(count, size) check_calloc(count, size)

static void	check_calloc(size_t count, size_t size, const char *description)
{
	void	*ex = calloc(count, size);
	void	*my = ft_calloc(count, size);
	printf("CASE %d [%s] %s\n", g_case_i++, description, !ex == !my ? OK : KO);
	if (g_detail) {
		printf(" INPUT	  : !calloc(%zu, %zu)\n", count, size);
		printf(" EXPECTED : %d\n", !ex);
		printf(" OUTPUT	  : %d\n\n", !my);
	}
	free(ex);
	free(my);
}

void	calloc_main(void)
{
	check_calloc(100, sizeof(long), "Normal input");
	check_calloc(1, 0, "Zero");
	check_calloc(SIZE_MAX, 1, "SIZE_MAX");
	check_calloc(SIZE_MAX, sizeof(long), "Wrap around");
}

#define STRRCHR(s, c) ft_strrchr(s, c) == strrchr(s, c)

void	strrchr_main(void)
{
	check("Match head", STRRCHR("42Tokyo", '4'));
	check("Match i=2", STRRCHR("42Tokyo", 'T'));
}