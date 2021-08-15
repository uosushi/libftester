#include "../utils/utils.h"
#include "../utils/check.h"

static int	ATOI(const char *str)
{
	memset(input, 0, 50);
	memset(ex, 0, 50);
	memset(ft, 0, 50);
	sprintf(input, "\"%s\"", str);
	sprintf(ex, "%d", atoi(str));
	sprintf(ft, "%d", ft_atoi(str));
	return (ft_atoi(str) == atoi(str));
}

static int	ATOI_ERRNO(const char *str)
{
	int	result;

	memset(input, 0, 50);
	memset(ex, 0, 50);
	memset(ft, 0, 50);
	sprintf(input, "\"%s\"", str);
	errno = 0;
	result = atoi(str);
	sprintf(ex, "%s", strerror(errno));
	errno = 0;
	result = ft_atoi(str);
	sprintf(ft, "%s", strerror(errno));
	return (!strcmp(ex, ft));
}

void	test_case(void)
{
	char	case26[] = {'1', -1, '2', -2, '3', -3, '4', 0};

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
	check("",                 ATOI(" 63410682753376583681"));
	check("",                 ATOI("-63410682753376583680"));
	check("",                 ATOI("-63410682753376583681"));
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
	check("LONG_MIN - 1",     ATOI("-9223372036854775809"));
	check("ULONG_MAX - 2",    ATOI("+18446744073709551613"));
	check("ULONG_MAX - 1",    ATOI("+18446744073709551614"));
	check("ULONG_MAX",        ATOI("+18446744073709551615"));
	check("ULONG_MAX + 1",    ATOI("+18446744073709551616"));
	check("ULONG_MAX + 2",    ATOI("+18446744073709551617"));
	check("Zero padding",     ATOI("+0000000000123456789"));
	check("unsigned char",    ATOI(case26));
	check("ERRNO ULONG_MAX + 1", ATOI_ERRNO("+18446744073709551616"));
	check("ERRNO LONG_MAX + 1",  ATOI_ERRNO("+9223372036854775808"));
	check("ERRNO INT_MAX + 1",   ATOI_ERRNO("+2147483648"));
}
