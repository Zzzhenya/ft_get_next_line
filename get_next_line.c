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
/*
static char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len;
	char	*ptr;

	len = ft_strlen(s1) + ft_strlen(s2);
	ptr = malloc((len + 1) * sizeof(char));
	if (!ptr)
		return (NULL);
	else
	{
		ft_strlcpy(ptr, s1, ft_strlen(s1) + 1);
		ft_strlcpy(ptr + ft_strlen(s1), s2, ft_strlen(s2) + 1);
		return (ptr);
	}
}


static char	*read_from_file(int fd, char *line)
{
	ssize_t	read_bytes;
	char	*buff;

	buff = malloc (sizeof(char) * BUFFER_SIZE);
	if (!buff)
		return (NULL);
	read_bytes = read(fd, buff, BUFFER_SIZE);
	if (read_bytes <= 0)
		return (NULL);
	while (buff[i] != '\n' && buff[i] != EOF)
	{
		line[i] = buff[i]
		i ++;
	}
}
*/


static char	*process_carry_over(char *line, char *carry_over)
{
	char	*line_break_loc;
	char	*temp;

	line_break_loc = 0;
	temp = 0;
	if (carry_over)
	{
		line_break_loc = ft_strchr(carry_over, '\n');
		if (line_break_loc)
		{
			line = malloc (sizeof(char) * BUFFER_SIZE);
			if (!line)
				return (NULL);
			ft_strlcpy(line, carry_over, (ft_strlen(carry_over) - ft_strlen(line_break_loc)));
			line[(ft_strlen(carry_over) - ft_strlen(line_break_loc) + 1)] = '\n';
			printf("Carry_over :%s\n", carry_over);
			printf("Size of line :%zu\n", ft_strlen(line));
			printf("Size after linebreak loc :%zu\n", ft_strlen(line_break_loc));
			printf("Size of carry_over :%zu\n", ft_strlen(carry_over));
		}
	}
	return (line);
}


char	*get_next_line(int fd)
{
	static char *carry_over;
	char		*line;

	carry_over = "ABCDE\nFGHI\n!!";
	line = process_carry_over(line, carry_over);
//	line = read_from_file();
//	carry_over = store_balance();
	return (line);
	return ("HELLO");
}