/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 09:12:15 by amalsago          #+#    #+#             */
/*   Updated: 2018/11/28 09:40:17 by amalsago         ###   ########.fr       */
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

int				get_next_line(const int fd, char **line)
{
	int				bytes_read;
	char			buff[BUFF_SIZE + 1];
	static char		*tmp;
	int				nl;

	if (fd < 0 || !line)
		return (-1);
	if (!tmp)
		tmp = (char *)ft_memalloc(sizeof(char));
	while ((bytes_read = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[bytes_read] = '\0';
		tmp = ft_strjoin(tmp, buff);
		if (ft_strchr(tmp, '\n') != NULL)
			break ;
	}
	if (bytes_read <= 0 && !ft_strlen(tmp))
		return (bytes_read);
	
	nl = ft_strclen(tmp, '\n');
	*line = ft_strsub(tmp, 0, nl);
	if (tmp[nl] != '\0')
		tmp = ft_strcpy(tmp, (tmp + nl) + 1);
	else
		ft_strdel(&tmp);
	return (1);
}
