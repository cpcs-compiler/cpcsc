#include <stdio.h>
#ifdef _WIN32
# include <windows.h>
#endif /* !_WIN32 */

void set_color(int fd, int color)
{
#ifdef _WIN32
	HANDLE	handle;

	handle = GetStdHandle(fd);
	SetConsoleTextAttribute(handle, color*16);
#else
	dprintf(fd, "\033[%dm", color);
#endif /* !_WIN32 */
}
