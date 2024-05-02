#include <stdio.h>
#include "get_next_line.h"
#include <fcntl.h>

int	main(void)
{
	int		fd = open("test.txt", O_RDONLY);
	
	printf("%s---\n", get_next_line(fd));
	printf("%s---\n", get_next_line(fd));
	printf("%s---\n", get_next_line(fd));
	printf("%s---\n", get_next_line(fd));
	return (0);
}