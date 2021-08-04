#include "../utils/utils.h"
#include "../utils/check.h"

static int SPLIT(char const *s, char c)
{
	// char	**ft_split(char const *s, char c);
}

void	test_case(void)
{
	check("SEGV PROTECT", SPLIT("\0aa\0bbb", '\0'));
}