#include "get_next_line.h"

static size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len] != '\0')
		len ++;
	return (len);
}

static size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (dst[i] != '\0' && i < size)
		i ++;
	while (src[j] != '\0' && (i + j + 1) < size)
	{
		dst[i + j] = src[j];
		j ++;
	}
	if (i < size)
		dst[i + j] = '\0';
	return (i + ft_strlen(src));
}

static size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{	
	size_t	i;

	i = 0;
	if (size == 0)
	{
		while (src[i] != '\0')
			i ++;
		return (i);
	}
	while (i < size - 1 && src[i] != '\0')
	{
		dest[i] = src[i];
		i ++;
	}
	if (i < size)
		dest [i] = '\0';
	while (src[i] != '\0')
		i ++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	while ((unsigned char)*s != (unsigned char)c && *s != '\0')
		s ++;
	if (*s == (char)c)
		return ((char *)s);
	return (NULL);
}

//char	*get_next_line(int fd)
void	get_next_line(int fd)
{
	static char *carry_over;
	char		*line;
	char		*next_line_loc;
	char		*buff;
	char		*temp;

	next_line_loc = NULL;
	if (carry_over == NULL)
	{
		printf("Nothing Here\n");
		buff = malloc(sizeof(char) * BUFFER_SIZE);
		read(fd, buff, BUFFER_SIZE);
		printf("buff: %s\n", buff);
		next_line_loc = ft_strchr(buff, '\n');
		printf("next_line_loc: %s\n", next_line_loc);
		if (next_line_loc == NULL)
		{
			line = malloc(sizeof(char) * BUFFER_SIZE + 1);
			ft_strlcpy(line, buff, (BUFFER_SIZE * 2) + 1);
			free(buff);
		}
		
		while (next_line_loc == NULL)
		{
			//printf("next_line_loc: %s\n", next_line_loc);
			temp = malloc(sizeof(char) * ft_strlen(line) + 1);
			ft_strlcpy(temp, line, ft_strlen(line) + 1);
			//printf("temp: %s\n", temp);
			free (line);
			buff = malloc(sizeof(char) * BUFFER_SIZE);
			read(fd, buff, BUFFER_SIZE);
			next_line_loc = ft_strchr(line, '\n');
			line = malloc(sizeof(char) * ft_strlen(temp) + BUFFER_SIZE + 1);
			ft_strlcpy(line, temp, ft_strlen(temp) + 1);
			free(temp);
			ft_strlcat(line, buff, (ft_strlen(line) + BUFFER_SIZE) + 1);
			free(buff);
			if (next_line_loc != NULL)
			{
				carry_over = malloc(sizeof(char) * ft_strlen(next_line_loc));
				ft_strlcpy(carry_over, temp, ft_strlen(temp));
				printf("line: %s\n", line);
			}
		}
		
	//	return (line);
		printf("line: %s\n", line);
	}
	else
		printf("carry_over: %s\n",carry_over);
	//	return(carry_over);
/*
	if (carry_over is empty)
		while not '\n' in buffer
			keep adding the buffer to the line 
		if '\n' in buffer
			add until '\n' to line;
			add a '\n' at line end;
			add rest to carry_over;
			return (line)
	if (carry_over is not empty)
		add to line until first '\n' or until carry_over is empty
			if no more '\n' in carry_over
				while not '\n' in buffer
					keep adding the buffer to the line 
				if '\n' in buffer
					add until '\n' to line;
					add a '\n' at line end;
					add rest to carry_over;
					return (line)
			while more '\n' in carry_over
				keep the rest in carry_over
				don't empty the carry_over
				return (line)
*/
}