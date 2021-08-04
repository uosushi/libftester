#include "../utils/utils.h"
#include "../utils/check.h"

static int	STRLCAT(char *dst, const char *src, size_t dstsize)
{
	char	*dst2;
	int		b;
	size_t	ex_src_len;
	size_t	my_src_len;

	memset(input, 0, 50);
	memset(ex, 0, 50);
	memset(output, 0, 50);
	dst2 = strdup(dst);
	sprintf(input, "(\"%s\", \"%s\", %zu)", dst, src, dstsize);
	ex_src_len = strlcat(dst, src, dstsize);
	my_src_len = ft_strlcat(dst2, src, dstsize);
	b = (ex_src_len == my_src_len && !strcmp(dst2, dst));
	sprintf(ex, "dst=\"%s\", return (%zu)", dst, ex_src_len);
	sprintf(output, "dst=\"%s\", return (%zu)", dst2, my_src_len);
	free(dst2);
	return (b);
}

void	test_case(void)
{
	char	dst[8];

	memset(dst, 0, 8);
	dst[0] = '4';
	check("\'4\' + \'2\'", STRLCAT(dst, "2", sizeof(dst)));
	memset(dst, 0, 8);
	check("\'\' + \'\'", STRLCAT(dst, "", sizeof(dst)));
	memset(dst, 0, 8);
	check("\'\' + \'42\'", STRLCAT(dst, "42", sizeof(dst)));
	memset(dst, 0, 8);
	dst[0] = '4';
	check("\'4\' + \'\'", STRLCAT(dst, "", sizeof(dst)));
	check("\'4\' + \'2\'", STRLCAT(dst, "2", 0));
	memset(dst, 0, 8);
	check("\'4\' + \'2\'", STRLCAT(dst, "2", 10));
}
