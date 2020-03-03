#ifndef CPCSC_COLOR_H
# define CPCSC_COLOR_H

# ifdef _WIN32
#  include <windows.h>

#  define BLACK		0
#  define RED		4
#  define GREEN		2
#  define YELLOW	14
#  define BLUE		1
#  define MAGENTA	5
#  define CYAN		3
#  define WHITE		15

#  define STDOUT	STD_OUTPUT_HANDLE
#  define STDERR	STD_ERROR_HANDLE

# else
#  define BLACK		30
#  define RED		31
#  define GREEN		32
#  define YELLOW	33
#  define BLUE		34
#  define MAGENTA	35
#  define CYAN		36
#  define WHITE		37

#  define STDOUT	1
#  define STDERR	2

# endif /* _WIN32 */

void	set_color(int, int);

#endif /* !CPCSC_COLOR_H */
