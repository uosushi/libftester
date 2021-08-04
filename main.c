#include <stdio.h>
#include <string.h>

int	g_case;
// view details on=1 / off=0
int	g_debug = 0;

char	input[50];
char	ex[50];
char	output[50];

void	test_case(void);

int	main(int argc, char const *argv[])
{
	memset(input, 0, 50);
	memset(ex, 0, 50);
	memset(output, 0, 50);
	g_case = 1;
	if (argc == 2 && argv)
		g_debug = 1;
	if (!g_debug)
		printf("\033[34m\033[4mCASE\033[0m \033[34m\033[4mEVAL\033[0m\n");
	test_case();
	if (g_debug)
		printf("\n");
	return (0);
}
