/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 09:12:15 by amalsago          #+#    #+#             */
/*   Updated: 2018/11/26 19:42:34 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "get_next_line.h"

int				get_next_line(const int fd, char **line)
{
	int				bytes_read;
	char			buff[BUFF_SIZE + 1];
	static char		*tmp;
	char			*ptr;

	if (fd < 0 || !line)
		return (-1);
	tmp = (char *)ft_memalloc(sizeof(char));
	while ((bytes_read = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[bytes_read] = '\0';
		tmp = ft_strjoin(tmp, buff);
		if (ft_strchr(buff, '\n') != NULL)
			break ;
	}
	if (bytes_read <= 0 && !ft_strlen(tmp))
		return (bytes_read);
	
	ptr = ft_strchr(tmp, '\0');
	*line = ft_strsub(tmp, tmp + ptr, ); //strSUB
	return (1);
}
