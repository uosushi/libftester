#include "../utils/utils.h"
#include "../utils/check.h"

static int	split_cmp_array(char **expected, char **got)
{
	while (*expected || *got)
	{
		if (*got == NULL || strcmp(*expected, *got))
		{
			return (0);
		}
		expected++;
		got++;
	}
	return (1);
}

static int	SPLIT(char const *s, char c, char **expected)
{
	char	**result;

	result = ft_split(s, c);
	return (split_cmp_array(expected, result));
}

void	test_case(void)
{
	char	**case1 = ((char *[1]){NULL});

	check("SEGV PROTECT", SPLIT("\0aa\0bbb", '\0', case1));
}
