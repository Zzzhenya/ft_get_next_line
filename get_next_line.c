#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
//char	*get_next_line(int fd);

//ssize_t	read(int fildes, void *buf, size_t nbyte);
//int open (const char* Path, int flags);


int main(int argc, char **argv)
{
	int fd;
	fd = 1;
	if (argc != 2)
		return (0);
	if (argc == 2)
	{
		fd = open(argv[0], O_RDONLY);
		printf("fd: %i \n", fd);
		fd = open(argv[1], O_RDONLY);
		printf("fd: %i \n", fd);
	}
	return (0);
}