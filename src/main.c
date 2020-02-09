#include <stdlib.h>
#include <stdio.h>

#include "utils.h"
#include "codegen.h"

extern FILE	*yyin;

int	yyparse();

int	process_file(char const *name)
{
	FILE	*fp;
	char	*obj_file;
	int	ret;

	obj_file = get_object_file(name);
	fp = fopen(name, "r");
	if (!fp)
		return (-1);
	yyin = fp;
	ret = yyparse();
	fclose(fp);
	if (ret < 0)
		return (-1);
	codegen(obj_file);
	free(obj_file);
	return (0);
}

int	main(int argc, char **argv)
{
	(void)argc;
	process_file(argv[1]);
	return (EXIT_SUCCESS);
}
