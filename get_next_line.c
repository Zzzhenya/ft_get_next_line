#include "get_next_line.h"

static size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len] != '\0')
		len ++;
	return (len);
}
/*
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
	if (i < size)
		dst[i + j] = '\0';
	return (i + ft_strlen(src));
}
*/
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

static char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len;
	char	*ptr;

	len = ft_strlen(s1) + ft_strlen(s2);
	ptr = malloc((len + 1) * sizeof(char));
	if (!ptr)
	{
		free ((void *)s2);
		return (NULL);
	}
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
	char	*temp;

	buff = 0;
	temp = 0;
	while (!ft_strchr(buff, '\n'))
	{
		buff = malloc (sizeof(char) * BUFFER_SIZE);
		if (!buff)
		{
			free (line);
			return (NULL);
		}
		read_bytes = read(fd, buff, BUFFER_SIZE);
		if (read_bytes <= 0)
		{
			free (buff);
			free (line);
			return (NULL);
		}
		temp = malloc (sizeof(char) * ft_strlen(line) + 1);
		if (!temp)
		{
			free (buff);
			free (line);
			return (NULL);
		}
		ft_strlcpy(temp, line, ft_strlen(line));
		free (line);
		//line = malloc (sizeof(char) *  (ft_strlen(temp) + ft_strlen(line) + 2));
		//if (!line)
		//{
		//	free (buff);
		//	return (NULL);
		//}
		line = ft_strjoin(temp, buff);
		free(temp);
		free(buff);
	}
	return(line);
}

static char	*process_carry_over(char *line, char *carry_over)
{
	char	*line_break_loc;
	char	*temp;

	temp = 0;
	line_break_loc = 0;
	line_break_loc = ft_strchr(carry_over, '\n');
	if (!line_break_loc)
	{
		line = malloc (sizeof(char) * (ft_strlen(carry_over) + 1));
		if (!line)
			return (NULL);
		ft_strlcpy(line, carry_over, ft_strlen(carry_over) + 1);
		carry_over = 0; /* comment this
		// Uncomment this once the carry_over creation at the end of reading is done! Can't free what's not malloc'd
		//free (carry_over); 
		
		printf("_________________No line break in carry over\n");
		printf("Carry_over :%s:END\n", carry_over);
		printf("temp :%s:END\n", temp);
		printf("Size of line :%zu\n", ft_strlen(line)); */
	}
	else 
	{
		line = malloc (sizeof(char) *  (ft_strlen(carry_over) - ft_strlen(line_break_loc) + 2));
		if (!line)
			return (NULL);
		ft_strlcpy(line, carry_over, (ft_strlen(carry_over) - ft_strlen(line_break_loc) + 1));
		temp = malloc (sizeof(char) * ft_strlen(line_break_loc) + 1);
		if (!temp)
		{
			free (line);
			return (NULL);
		}
		ft_strlcpy(temp, carry_over + ft_strlen(carry_over) - ft_strlen(line_break_loc) + 1, ft_strlen(line_break_loc));
		// Uncomment this once the carry_over creation at the end of reading is done! Can't free what's not malloc'd
		//free (carry_over);
		carry_over = malloc (sizeof(char) * ft_strlen(line_break_loc));
		if (!carry_over)
		{
			free (temp);
			free (line);
			return (NULL);
		}
		ft_strlcpy(carry_over, temp, ft_strlen(line_break_loc));
		free (temp); /*
		printf("_________________Line break in carry over\n");
		printf("Carry_over :%s:END\n", carry_over);
		printf("temp :%s:END\n", temp);
		printf("Size of line :%zu\n", ft_strlen(line));
		printf("Size after linebreak loc :%zu\n", ft_strlen(line_break_loc));
		printf("Size of carry_over :%zu\n", ft_strlen(carry_over));
		printf("Size of temp :%zu\n", ft_strlen(temp)); */
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char *carry_over;
	char		*line;
	//carry_over = "ABCDE\nFGH";
	
	line = NULL;
	printf("fd : %i\n", fd);
	if (carry_over)
		line = process_carry_over(line, carry_over);
	else
		line = malloc (sizeof(char) * BUFFER_SIZE + 1);
	if (!ft_strchr(line, '\n'))
		line = read_from_file(fd, line);
//	line = read_from_file();
//	carry_over = store_balance();
	return (line);
	return ("HELLO");
}