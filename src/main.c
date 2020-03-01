#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>

#include "utils.h"
#include "codegen.h"
#include "error.h"

extern FILE	*yyin;
extern int	error_count;

int	yyparse();

int	process_file(char const *name)
{
	FILE	*fp;
	char	*obj_file;
	int	ret;

	obj_file = get_object_file(name);
	fp = fopen(name, "r");
	if (!fp)
	{
		error("%s: %s", name, strerror(errno));
		return (-1);
	}
	yyin = fp;
	ret = yyparse();
	fclose(fp);
	if (ret != 0)
	{
		error("Invalid Syntax");
		return (-1);
	}
	codegen(obj_file);
	free(obj_file);
	return (0);
}

int	main(int argc, char **argv)
{
	(void)argc;
	error_count = 0;
	process_file(argv[1]);
	return (error_count);
}
