#include <stdlib.h>

int	yyparse();

int	main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	yyparse();
	return (EXIT_SUCCESS);
}
