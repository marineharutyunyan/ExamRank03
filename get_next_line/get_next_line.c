#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char	*main;
	char	*copy;

	main = malloc(10000);
	copy = main;
	while (read(fd, copy, 1) > 0 && *copy++ != '\n')
		;
	if (copy > main)
	{
		copy = 0;
		return (main);
	}
	free(main);
	return (0);
}
char *func()
{

	return (0);
}

int	main(void)
{
	int	fd;

	fd = open("txt.txt", O_RDONLY);
	printf("gnl = %s\n", get_next_line(fd));
	printf("gnl = %s\n", get_next_line(fd));
	printf("gnl = %s\n", get_next_line(fd));
	printf("gnl = %s\n", get_next_line(fd));
	printf("gnl = %s\n", func());
	return (0);
}
