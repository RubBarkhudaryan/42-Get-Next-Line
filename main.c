#include "get_next_line.h"
#include <stdio.h>

int main()
{
	int fd = open("file.txt", O_RDONLY);
	char *line;

	line = get_next_line(fd);
	printf("%s", line);
	line = get_next_line(fd);
	printf("%s", line);

	close(fd);
	return 0;
}