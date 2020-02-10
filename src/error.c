#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include "utils.h"
#include "color.h"

static char	*create_message(const char *str, va_list ap)
{
	char	*buffer;
	int	size;
	va_list	temp;

	va_copy(temp, ap);
	size = vsnprintf(NULL, 0, str, temp);
	va_end(temp);
	buffer = (char *)malloc((++size) * sizeof(char));
	vsnprintf(buffer, size, str, ap);
	return (buffer);
}

void	error(char const *txt, ...)
{
	va_list	ap;
	char	*buffer;

	set_color(STDERR, RED);

	va_start(ap, txt);
	buffer = create_message(txt, ap);
	va_end(ap);
	fprintf(stderr, "[Error] %s\n", buffer);
	free(buffer);

	set_color(STDERR, WHITE);
}

void	warn(char const *txt)
{
	set_color(STDERR, YELLOW);
	fprintf(stderr, "[Warning] %s\n", txt);
	set_color(STDERR, WHITE);
}
