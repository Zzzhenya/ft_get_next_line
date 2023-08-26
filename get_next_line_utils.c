#include "get_next_line.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;
	size_t	byte_size;
	unsigned char	*p;

	byte_size = nmemb * size;
	ptr = malloc(byte_size);
	if (!ptr)
		return (NULL);
	p = ptr;
	while (byte_size > 0)
	{
		*p = '\0';
		p ++;
		byte_size --;
	}
	return (ptr);
}

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	if (!s)
		return (len);
	while (s[len] != '\0')
		len ++;
	return (len);
}

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{	
	size_t	i;

	i = 0;
	if (!dest || !src)
		return (i);
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
	if (!s)
		return (NULL);
	while ((unsigned char)*s != (unsigned char)c && *s != '\0')
		s ++;
	if (*s == (char)c)
		return ((char *)s);
	return (NULL);
}