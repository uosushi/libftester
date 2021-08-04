#include "../utils/utils.h"
#include "../utils/check.h"

static int	STRRCHR(const char *s, int c)
{
	memset(input, 0, 50);
	memset(ex, 0, 50);
	memset(output, 0, 50);
	sprintf(input, "(\"%s\", \'%c\'", s, c);
	sprintf(output, "%s", ft_strrchr(s, c));
	sprintf(ex, "%s", strrchr(s, c));
	return (!strcmp(ex, output));
}

void	test_case(void)
{
	check("Match head",   STRRCHR("42Tokyo", '4'));
	check("Match i=2",    STRRCHR("42Tokyo", 'T'));
	check("int 0",        STRRCHR("42Tokyo", 0));
	check("int 257",      STRRCHR("42Tokyo", 257));
}
