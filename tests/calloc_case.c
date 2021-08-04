#include "../utils/utils.h"
#include "../utils/check.h"

static int	CALLOC(size_t count, size_t size)
{
	void	*tmpex = calloc(count, size);
	void	*tmpmy = ft_calloc(count, size);
	int		b;

	memset(input, 0, 50);
	memset(ex, 0, 50);
	memset(output, 0, 50);
	sprintf(input, "!calloc(%zu, %zu)", count, size);
	b = !tmpex == !tmpmy;
	sprintf(ex, "%d", !tmpex);
	sprintf(output, "%d", !tmpmy);
	free(tmpex);
	free(tmpmy);
	return (b);
}

void	test_case(void)
{
	check("Normal input", CALLOC(100, 8));
	check("Zero",         CALLOC(1, 0));
	check("SIZE_MAX",     CALLOC(SIZE_MAX, 1));
	check("Wrap around",  CALLOC(SIZE_MAX, 8));
}