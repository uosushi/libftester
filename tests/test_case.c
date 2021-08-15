#include "../utils/utils.h"
#include "../utils/check.h"

void	test_case(void)
{
	void	*mem;

	mem = malloc(16 * sizeof(char));
	check("OK", 1);
	check("KO", 0);
	mcheck("MOK", mem, 16 * sizeof(char));
	mcheck("MKO", mem, 32 * sizeof(char));
	leaks();
	free(mem);
	leaks();
	protect(1);
	protect(0);
}
