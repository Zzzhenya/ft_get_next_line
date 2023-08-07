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

	len = ft_strlen(s1) + ft_strlen(s2);
	ptr = ft_calloc((len + 1), sizeof(char));
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

char	*get_next_line(int fd)
{
//	static char	*carry_over;
	char		*buff = 0;
	char		*line = 0;
	int		bytes_read = 0;

	if (fd < 0)
		return (NULL);
	while (!ft_strchr(line, '\n'))
	{
		buff = ft_calloc (BUFFER_SIZE + 1, sizeof(char));
		if (!buff)
			return (NULL);
		bytes_read = read(fd, buff, BUFFER_SIZE);
		printf("%s", buff);
		if (bytes_read < 0)
		{
			free (buff);
    		return (NULL);
		}
		line = ft_strjoin_fr(line, buff);
	}
	return (line);
}