#include "../utils/utils.h"
#include "../utils/check.h"

static int	CALLOC(size_t count, size_t size)
{
	void	*tmpex = calloc(count, size);
	void	*tmpmy = ft_calloc(count, size);
	int		b;

	memset(input, 0, 50);
	memset(ex, 0, 50);
	memset(ft, 0, 50);
	sprintf(input, "!calloc(%zu, %zu)", count, size);
	b = !tmpex == !tmpmy;
	sprintf(ex, "%d", !tmpex);
	sprintf(ft, "%d", !tmpmy);
	free(tmpex);
	free(tmpmy);
	return (b);
}

static int	CALLOC_ERRNO(size_t count, size_t size)
{
	void	*tmp;

	memset(input, 0, 50);
	memset(ex, 0, 50);
	memset(ft, 0, 50);
	// Cannot allocate memory ?
	errno = 0;
	tmp = calloc(count, size);
	sprintf(ex, "%s", strerror(errno));
	errno = 0;
	tmp = ft_calloc(count, size);
	sprintf(ft, "%s", strerror(errno));
	return (!strcmp(ex, ft));
}

void	test_case(void)
{
	check("Normal input", CALLOC(100, 2));
	check("Zero",         CALLOC(1, 0));
	check("SIZE_MAX",     CALLOC(SIZE_MAX, 1));
	check("Wrap around",  CALLOC(SIZE_MAX, 8));
	check("ERRNO ENOMEM", CALLOC_ERRNO(SIZE_MAX, 2));
	check("ERRNO NORMAL", CALLOC_ERRNO(100, 2));
	check("ERRNO ZERO",   CALLOC_ERRNO(1, 0));
}
