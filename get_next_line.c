#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <errno.h>
#include <stdlib.h>

#define BUFFER_SIZE 10
//char	*get_next_line(int fd);

//ssize_t	read(int fildes, void *buf, size_t nbyte);
//int open (const char* Path, int flags);

extern int errno;


char	*get_next_line(int fd)
{
	ssize_t ret;
	void 	*ptr;

	ptr = (void *)malloc(sizeof(char) * 100);
	if (!ptr)
		return (NULL);
	ret = read(fd, ptr, 100);
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
	return (0);
}
/*
    #ifdef BUFFER_SIZE=n   
       printf("Debug run\n");
    #else
       printf("Release run\n");
    #endif
	*/