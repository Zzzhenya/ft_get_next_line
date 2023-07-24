#include "get_next_line.h"
/*
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



char	*get_next_line(int fd)
{
	return ("HELLO");
}

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