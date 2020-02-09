#include <stdlib.h>
#include <string.h>

static char	*get_file_ext(char *file)
{
	char *ext;
	
	ext = strrchr(file, '.');
	if (ext == NULL || ext == file) return NULL;
	return (ext + 1);
}

char *get_object_file(const char *file)
{
	char	*str;
	char	*ext;
	size_t	len;

	str = strdup(file);
	if (!str) return (NULL);
	ext = get_file_ext(str);
	if (ext == NULL || *ext == '\0')
	{
		len = strlen(str);
		str = (char *)realloc(str, (len + 3) * sizeof(char));
		if (!str) return (NULL);
		strcat(str, ".o");
		return (str);
	}
	*ext++ = 'o';
	*ext = '\0';
	return (str);
}
