#include "utils.h"

void	check(char *description, int b)
{
	evaluation(b ? OK : KO, description);
	if (g_debug)
	{
		printf("[   test   ] %s\n", input);
		if (!b)
			printf("[ expected ] %s\n", ex);
		printf("[  output  ] %s\n", output);
		printf("\n");
	}
}

void	mcheck(char *description, void *p, size_t required_size)
{
	void	*p2;
	int		b;

	p2 = malloc(required_size);
	b = malloc_size(p) == malloc_size(p2);
	free(p2);
	evaluation(b ? MOK : MKO, description);
}