#include "../utils/utils.h"
#include "../utils/check.h"

static int	STRLCPY(char *dst, const char *src, size_t dstsize)
{
	size_t	ex_src_len;
	size_t	my_src_len;
	char	*dst2;

	memset(input, 0, 50);
	memset(ex, 0, 50);
	memset(ft, 0, 50);
	sprintf(input, "strlcpy(\"%s\", \"%s\", %zu)", dst, src, dstsize);
	dst2 = strdup(dst);
	ex_src_len = strlcpy(dst, src, dstsize);
	my_src_len = ft_strlcpy(dst2, src, dstsize);
	sprintf(ex, "\"%s\", return (%zu)", dst, ex_src_len);
	sprintf(ft, "\"%s\", return (%zu)", dst2, my_src_len);
	return (ex_src_len == my_src_len && !strcmp(dst, dst2));
}

void	test_case(void)
{
	protect(!ft_strlcpy(NULL, "AC", 10));
	check("", STRLCPY("A", "C", 2));
	//pcheck(STRLCPY(NULL, NULL, 10));
}
