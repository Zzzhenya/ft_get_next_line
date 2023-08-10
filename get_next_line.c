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

char	*read_from_file(int fd, char *line)
{
	char	*buff;
	int		read_bytes;

	buff = 0;
	read_bytes = 1;
	while (read_bytes > 0)
	{
		buff = ft_calloc (BUFFER_SIZE + 1, sizeof(char));
		if (!buff)
			return (NULL);
		read_bytes = read(fd, buff, BUFFER_SIZE);
		//printf("%s", buff);
		if (read_bytes < 0)
		{
			free (buff);
			//printf("%s", line);
			if (line)
				free (line);
			return (NULL);
		}
		line = ft_strjoin_fr (line, buff);
		if (ft_strchr(line, '\n'))
			break;
		//if (read_bytes < BUFFER_SIZE)
		//	return (line);
		//printf("%s", line);
	}
	if (read_bytes == 0)
	{
	//	free (buff);
		printf("%s", line);
		return (line);
	}
	//printf("%s", line);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*carry_over;
	char		*line = NULL;
	char		*lb = NULL;
	char		*temp;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!ft_strchr(carry_over, '\n'))
		carry_over = read_from_file(fd, carry_over);
	if(!carry_over)
		return (NULL);
	if (carry_over != 0 && ft_strchr(carry_over, '\n'))
	{
		lb = ft_strchr(carry_over, '\n');
		if (lb)
		{
			line = ft_calloc(ft_strlen(carry_over) - ft_strlen(lb) + 2, sizeof(char));
			if (!line)
				return (NULL);
			ft_strlcpy(line, carry_over, ft_strlen(carry_over) - ft_strlen(lb) + 2);
			temp = ft_calloc(ft_strlen(lb), sizeof(char));
			if (!temp)
				return (NULL);
			ft_strlcpy(temp, lb + 1, ft_strlen(lb));
			free(carry_over);
			carry_over = ft_calloc (ft_strlen(temp),sizeof(char));
			if (!carry_over)
				return (NULL);
			ft_strlcpy(carry_over, temp, ft_strlen(temp));
			free(temp);
		}
	}
	else if (carry_over != 0 && !ft_strchr(carry_over, '\n'))
	{
		line = ft_calloc (ft_strlen(carry_over) ,sizeof(char));
		if (!line)
			return (NULL);
		ft_strlcpy(line, carry_over, ft_strlen(carry_over));
		free (carry_over);
		return (line);
	}
	else if (carry_over == 0)
	{
		line = ft_calloc(1, sizeof(char));
		if (!line)
			return (NULL);
		return (line);
	}
	return (line);
	/*
	if (line)
	{
		lb = ft_strchr(line, '\n');
		if (!lb ) //&& ft_strlen(line) == 0)
			carry_over = ft_calloc(1, sizeof(char));
		else
		{
			carry_over = ft_calloc(ft_strlen(lb), sizeof(char));
			if (!carry_over)
			{
				free (line);
				return (NULL);
			}
			ft_strlcpy(carry_over, lb + 1, ft_strlen(lb));
			line = post_process(line, lb);

		}
	//	return (line);
	}
	else
		return (NULL);
	*/
}