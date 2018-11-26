/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 09:12:15 by amalsago          #+#    #+#             */
/*   Updated: 2018/11/26 16:21:43 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "get_next_line.h"

static void		cut_until_new_line(char *tmp)
{
	char	*ptr;
	ptr = ft_strchr(tmp, '\n');
	if (ptr)
		*ptr = '\0';
}

int				get_next_line(const int fd, char **line)
{
	int				bytes_read;
	char			buff[BUFF_SIZE + 1];
	static char		*tmp;

	if (fd < 0 || !(line))
		return (-1);
	tmp = (char *)ft_memalloc(sizeof(char));
	while ((bytes_read = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[bytes_read] = '\0';
		tmp = ft_strjoin(tmp, buff);
		if (ft_strchr(buff, '\n') != NULL)
			break ;
	}
	cut_until_new_line(tmp);
	*line = ft_strdup(tmp);
	return (1);
}
