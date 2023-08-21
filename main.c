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
	int 	fd;
	char	*ptr;

	fd = 1;
	if (argc < 2)
	{
		printf("Where's the text file?\n");
	}
	else if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		int i = 1;
		while (1)
		{
			ptr = get_next_line(fd);
			if (ptr == NULL)
				break;
			printf("[%i]:%i:%s", fd, i, ptr);
			free(ptr);
			ptr = NULL;
			i ++;	
		}
		close(fd);
	}
	else
	{
		printf("Too many arguments. Can't argue all day!\n");
	}
	return (0);
}