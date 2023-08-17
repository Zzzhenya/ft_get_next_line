/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-silv <sde-silv@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 15:23:59 by sde-silv          #+#    #+#             */
/*   Updated: 2023/07/31 15:34:40 by sde-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin_fr(char const *s1, char const *s2)
{
	size_t	len;
	char	*ptr;

	if (!s1)
		//s1 = ft_calloc(1, sizeof(char));
	{
		s1 = malloc(1 * sizeof(char));
		// s1[0] = '\0'; 
	}
	len = ft_strlen(s1) + ft_strlen(s2);
	//ptr = ft_calloc((len + 1), sizeof(char));
	ptr = malloc((len + 1) * sizeof(char));
	if (!ptr)
	{
		free ((void *)s1);
		free ((void *)s2);
		return (NULL);
	}
	else
	{
		ft_strlcpy(ptr, s1, ft_strlen(s1) + 1);
		ft_strlcpy(ptr + ft_strlen(s1), s2, ft_strlen(s2) + 1);
		free ((void *)s1);
		free ((void *)s2);
		return (ptr);
	}
}

char	*read_from_file(int fd, char *line)
{
	char	*buff;
	int		read_bytes;

	buff = 0;
	read_bytes = 1;
	while (!ft_strchr(line, '\n') && read_bytes != 0)
	{
		//buff = ft_calloc (BUFFER_SIZE + 1, sizeof(char));
		buff = malloc (BUFFER_SIZE + 1 * sizeof(char));
		if (!buff)
			return (NULL);
		read_bytes = read(fd, buff, BUFFER_SIZE);
		if (read_bytes <= 0)
		{
			free (buff);
			if (line)
				free (line);
			return (NULL);
		}
		//if (read_bytes == 0)
		//	break;
		line = ft_strjoin_fr (line, buff);
		if (read_bytes < BUFFER_SIZE)
			return (line);
	}
	return (line);
}

char	*post_process(char *line, char *lb)
{
	char	*temp;

	//temp = ft_calloc(ft_strlen(line) - ft_strlen(lb) + 2, sizeof(char));
	temp = malloc((ft_strlen(line) - ft_strlen(lb) + 2 )* sizeof(char));
	if (!temp)
		return (NULL);
	ft_strlcpy(temp, line, ft_strlen(line) - ft_strlen(lb) + 2);
	free (line);
	return (temp);
}

char	*get_next_line(int fd)
{
	static char	*carry_over;
	char		*line;
	char		*lb;

	line = 0;
	lb = 0;
	if (fd < 0)
		return (NULL);
	if (carry_over != 0)
	{
		//line = ft_calloc(ft_strlen(carry_over) + 1, sizeof(char));
		line = malloc(ft_strlen(carry_over) + 1 * sizeof(char));
		if (!line)
		{
			free (carry_over);
			return (NULL);
		}
		ft_strlcpy(line, carry_over, ft_strlen(carry_over) + 1);
		free (carry_over);
	}
	else
	{
		//line = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
		line = malloc (BUFFER_SIZE + 1 * sizeof(char));
		if (!line)
			return (NULL);
	}
	line = read_from_file(fd, line);
	if (line)
	{
		lb = ft_strchr(line, '\n');
		if (!lb ) //&& ft_strlen(line) == 0)
		{
			//carry_over = ft_calloc(1, sizeof(char));
			carry_over = malloc(1 * sizeof(char));
			carry_over[0] = '\0';
		}
		else
		{
			//carry_over = ft_calloc(ft_strlen(lb), sizeof(char));
			carry_over = malloc(ft_strlen(lb) * sizeof(char));
			if (!carry_over)
			{
				free (line);
				return (NULL);
			}
			ft_strlcpy(carry_over, lb + 1, ft_strlen(lb));
			line = post_process(line, lb);
		}
	}
	return (line);
}