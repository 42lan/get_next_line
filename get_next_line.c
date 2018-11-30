/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 09:12:15 by amalsago          #+#    #+#             */
/*   Updated: 2018/11/30 14:26:25 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "get_next_line.h"
#include <string.h>

int				ft_strclen(const char *s, int c)
{
	int		index;

	index = 0;
	while (s[index] != '\0' && s[index] != c)
		index++;
	return (index);
}

int				get_line(char **save, char **line)
{
	int				nl;

	nl = ft_strclen(*save, '\n');
	if (!(*line = ft_strsub(*save, 0, nl)))
		return (-1);
	if ((*save)[nl] != '\0')
		*save = ft_strcpy(*save, (*save + nl) + 1);
	else
		ft_strdel(save);
	return (1);
}

int				get_next_line(const int fd, char **line)
{
	int				bytes_read;
	char			buff[BUFF_SIZE + 1];
	char			*tmp;
	static char		*save[OPEN_MAX];

	if (fd < 0 || !line)
		return (-1);
	if (!save[fd])
		save[fd] = ft_strnew(0);
	while ((bytes_read = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[bytes_read] = '\0';
		tmp = save[fd];
		if (!(save[fd] = ft_strjoin(save[fd], buff)))
			return (-1);
		free(tmp);
		if (ft_strchr(save[fd], '\n') != NULL)
			break ;
	}
	if (bytes_read <= 0 && !ft_strlen(save[fd]))
		return (bytes_read);
	return (get_line(&save[fd], line));
}
