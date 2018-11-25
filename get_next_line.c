/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 09:12:15 by amalsago          #+#    #+#             */
/*   Updated: 2018/11/25 19:22:47 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "get_next_line.h"

int		get_next_line(const int fd, char **line)
{
	int				bytes_read;
	char			buff[BUFF_SIZE + 1];

	if (fd < 0 || !(line))
		return (-1);
	while ((bytes_read = read(fd, buff, BUFF_SIZE)) > 0)
	{
		if (bytes_read < 0)
			return (-1);
		if (!(*line = ft_strnew(bytes_read)))
			return (-1);
		ft_memcpy(*line, buff, bytes_read);
		
		ft_putstr(*line);
	}
	return (0);
}
