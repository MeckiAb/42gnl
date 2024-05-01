#include <stdio.h>
#include "get_next_line.h"
#include <fcntl.h>

int	main(void)
{
	int		fd = open("../gnlTester/files/41_with_nl", O_RDONLY);
	
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	return (0);
}