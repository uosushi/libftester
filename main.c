#include <stdio.h>
#include <string.h>

int	g_case;
// view details on=1 / off=0
int	g_debug = 0;

char	input[50];
char	ex[50];
char	ft[50];

void	test_case(void);

int	main(int argc, char const *argv[])
{
	memset(input, 0, 50);
	memset(ex, 0, 50);
	memset(ft, 0, 50);
	g_case = 1;
	if (argc == 2 && !strcmp(argv[1], "-debug"))
		g_debug = 1;
	test_case();
	if (g_debug)
		printf("\n");
	return (0);
}
