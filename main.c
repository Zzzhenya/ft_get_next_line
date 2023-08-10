#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "get_next_line.h"
#include "get_next_line_utils.c"
//extern int errno;

char	*get_next_line(int fd);
void	*ft_calloc(size_t nmemb, size_t size);
size_t	ft_strlen(const char *s);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
char	*ft_strchr(const char *s, int c);

int main(int argc, char **argv)
{
	int fd;

	//printf("Open_max: %d\n", OPEN_MAX);
	//printf("Fopen_max: %d\n", FOPEN_MAX);
	//ptr = malloc(sizeof(char) * BUFFER_SIZE);
	fd = 1;
	if (argc < 2)
	{
		printf("Where's the text file?\n");
		return (0);
	}
	else if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		if (fd > 0)
		{
			printf("fd: %i\n", fd);
			
			int i = 1;
			char *ptr = "Start";
			while (ptr)
			{
				ptr = get_next_line(fd);
				printf("%i:%s", i, ptr);
//				write(1, ptr, strlen(ptr));
				free(ptr);
				i ++;
			}
			
			/*
			printf("\nLine %i : \n", i);
			//get_next_line(fd);
			char *ptr = get_next_line(fd);
			write(1, ptr, strlen(ptr));
			*/
			
		} 
		//else
		//{
		//	printf("Error Number % d\n", errno);
		//	perror("Program");
		//}
	}
	else
	{
		printf("Too many arguments. Can't argue all day!\n");
		return (0);
	}

//	printf("\n Buffer %d\n", BUFFER_SIZE);
	return (0);
}