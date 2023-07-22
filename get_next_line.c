#include "get_next_line.h"


#ifdef BUFFER_SIZE

char	*get_next_line(int fd)
{
	char 				*ptr;
	ssize_t	read_bytes;
	//static ssize_t	read_bytes;

	read_bytes = 0;
	ptr = (char *)malloc(sizeof(char) * BUFFER_SIZE);
	if (!ptr)
		return (NULL);
	read_bytes = read(fd, ptr, BUFFER_SIZE);
	//read_bytes = read_bytes + read(fd, ptr, BUFFER_SIZE);
	printf("read_bytes :%zd\n", read_bytes);

/*
if line end is not in buffer 
	add buffer to current line
if line end is in buffer 
	add upto line end to current line
*/


	return(ptr);
}

#else
# define BUFFER_SIZE 10

char	*get_next_line(int fd)
{
	char 				*ptr;
	ssize_t	read_bytes;
	//static ssize_t	read_bytes;

	read_bytes = 0;
	ptr = (char *)malloc(sizeof(char) * BUFFER_SIZE);
	if (!ptr)
		return (NULL);
	read_bytes = read(fd, ptr, BUFFER_SIZE);
	//read_bytes = read_bytes + read(fd, ptr, BUFFER_SIZE);
	printf("read_bytes :%zd\n", read_bytes);

/*
if line end is not in buffer 
	add buffer to current line
if line end is in buffer 
	add upto line end to current line
*/


	return(ptr);
}

#endif