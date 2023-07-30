#include "get_next_line.h"

char	*ft_strjoin_fr(char const *s1, char const *s2)
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

char	*read_from_file(int fd, char *line)
{
	char	*buff;
	int		read_bytes;

	buff = 0;
	read_bytes = 1;
	while (!ft_strchr(line, '\n'))
	{
		buff = ft_calloc (BUFFER_SIZE + 2, sizeof(char));
		if (!buff)
			return (NULL);
		read_bytes = read(fd, buff, BUFFER_SIZE);
		if (read_bytes <= 0)
		{
			free (buff);
			return (NULL);
		}
		line = ft_strjoin_fr (line, buff);
		free (buff);
		if (read_bytes < BUFFER_SIZE)
			return (line);
	}
	return (line);
}


char	*post_process(char *line, char *lb)
{
	char	*temp;

	temp = ft_calloc(ft_strlen(line) - ft_strlen(lb + 1) + 1, sizeof(char));
	if (!temp)
		return (NULL);
	ft_strlcpy(temp, line, ft_strlen(line) - ft_strlen(lb + 1));
	free (line);
	return (temp);
}

char	*get_next_line(int fd)
{
	static char *carry_over;
	char		*line;
	char		*lb;
	
	line = 0;
	lb = 0;
	if (!fd || fd < 0)
		return (NULL);
	if (carry_over != 0)
	{
		line = ft_calloc(ft_strlen(carry_over) + 1, sizeof(char));
		if (!line)
			return(NULL);
		ft_strlcpy(line, carry_over, ft_strlen(carry_over) + 1);
		free (carry_over);
	}
	else
	{
		line = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
		if (!line)
			return (NULL);
	}
	line = read_from_file(fd, line);
	//if (ft_strchr(line, '\n'))
	if (line)
	{
		lb = ft_strchr(line, '\n');
		if (!lb)
			carry_over = ft_calloc( 1, sizeof(char));
		else
		{
			carry_over = ft_calloc(ft_strlen(lb), sizeof(char));
			if (!carry_over)
				return (NULL);
			ft_strlcpy(carry_over, lb + 1, ft_strlen(lb));
			line = post_process(line, lb);
		}
//		return (line);
	}
	return (line);
}