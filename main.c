/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mloeffer <mloeffer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 05:38:59 by mloeffer          #+#    #+#             */
/*   Updated: 2024/12/22 03:52:22 by mloeffer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*new_line_handler(char *line, char *save)
{
	char	*new_line;

	new_line = ft_strchr(save, '\n');
	if (new_line)
		ft_strlcpy(save, new_line + 1, BUFFER_SIZE);
	else
		save[0] = '\0';
	return (line);
}

char	*get_next_line(int fd)
{
	static char	save[FD_MAX][BUFFER_SIZE + 1];
	char		*line;
	int			nb_bytes;

	line = NULL;
	if (fd < 0 || fd > FD_MAX || BUFFER_SIZE <= 0)
		return (NULL);
	while (1)
	{
		if (!save[fd][0])
		{
			nb_bytes = read(fd, save[fd], BUFFER_SIZE);
			if (nb_bytes > 0)
				save[fd][nb_bytes] = '\0';
			if (nb_bytes < 0)
				return (free_and_return(line));
			if (nb_bytes == 0)
				return (line);
		}
		line = ft_strjoin(line, save[fd]);
		if (ft_strchr(save[fd], '\n'))
			return (new_line_handler(line, save[fd]));
		save[fd][0] = '\0';
	}
}
