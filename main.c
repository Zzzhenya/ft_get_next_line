#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include "get_next_line.h"

//extern int errno;

char	*get_next_line(int fd);

int main(int argc, char **argv)
{
	int fd;

	//ptr = malloc(sizeof(char) * BUFFER_SIZE);
	fd = 1;
	if (argc != 2)
		return (0);
	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		if (fd > 0)
		{
			printf("fd: %i\n", fd);
			int i = 0;
			while (i < 6)
			{
				printf("\nLine %i : \n", i);
				const char *ptr = get_next_line(fd);
				write(1, ptr, strlen(ptr));
				i ++;
			}
		}
		//else
		//{
		//	printf("Error Number % d\n", errno);
		//	perror("Program");
		//}
	}
	//free (ptr);
//	printf("\n Buffer %d\n", BUFFER_SIZE);
	return (0);
}