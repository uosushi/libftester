#include "../utils/utils.h"
#include "../utils/check.h"

static int	ATOI(const char *str)
{
	memset(input, 0, 50);
	memset(ex, 0, 50);
	memset(output, 0, 50);
	sprintf(input, "\"%s\"", str);
	sprintf(ex, "%d", atoi(str));
	sprintf(output, "%d", ft_atoi(str));
	return (ft_atoi(str) == atoi(str));
}

void	test_case(void)
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
