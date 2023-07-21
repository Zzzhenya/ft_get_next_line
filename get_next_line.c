#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <errno.h>
#include <stdlib.h>

#ifdef BUFFER_SIZE
/*
extern int errno;


char	*get_next_line(int fd)
{
	ssize_t ret;
	void 	*ptr;

	ptr = (void *)malloc(sizeof(char) * BUFFER_SIZE);
	if (!ptr)
		return (NULL);
	ret = read(fd, ptr, BUFFER_SIZE);
	printf("ret :%zd", ret);
	if (ret != 0) 
		return((char *)ptr);
	else
		return (0);
}

int main(int argc, char **argv)
{
	int fd;
	char *ptr;

	ptr = malloc(sizeof(char) * BUFFER_SIZE);
	fd = 1;
	if (argc != 2)
		return (0);
	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		if (fd > 0)
		{
			printf("fd: %i \n", fd);
			ptr = get_next_line(fd);
			write(1, ptr, 100);
		}
		else
		{
			printf("Error Number % d\n", errno);
			perror("Program");
		}
	}
	free (ptr);
	printf("\n Buffer %d\n", BUFFER_SIZE);
	return (0);
}
*/
#else
#define BUFFER_SIZE 10

extern int errno;


char	*get_next_line(int fd)
{
	ssize_t ret;
	void 	*ptr;

	ptr = (void *)malloc(sizeof(char) * BUFFER_SIZE);
	if (!ptr)
		return (NULL);
	ret = read(fd, ptr, BUFFER_SIZE);
	printf("ret :%zd", ret);
	if (ret != 0) 
		return((char *)ptr);
	else
		return (0);
}


int main(int argc, char **argv)
{
	int fd;
	char *ptr;

	ptr = malloc(sizeof(char) * BUFFER_SIZE);
	fd = 1;
	if (argc != 2)
		return (0);
	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		if (fd > 0)
		{
			printf("fd: %i \n", fd);
			ptr = get_next_line(fd);
			write(1, ptr, 100);
		}
		else
		{
			printf("Error Number % d\n", errno);
			perror("Program");
		}
	}
	free (ptr);
	printf("\n Buffer %d\n", BUFFER_SIZE);
	return (0);
}

#endif