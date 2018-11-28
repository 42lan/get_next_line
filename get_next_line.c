/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 09:12:15 by amalsago          #+#    #+#             */
/*   Updated: 2018/11/28 17:20:14 by amalsago         ###   ########.fr       */
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
	*line = ft_strsub(*save, 0, nl);
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
	static char		*save;

	if (fd < 0 || !line)
		return (-1);
	if (!save)
		save = (char *)ft_memalloc(sizeof(char));
	while ((bytes_read = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[bytes_read] = '\0';
		tmp = save;
		save = ft_strjoin(save, buff);
		free(tmp);
		if (ft_strchr(save, '\n') != NULL)
			break ;
	}
	if (bytes_read <= 0 && !ft_strlen(save))
		return (bytes_read);
	return (get_line(&save, line));
}
