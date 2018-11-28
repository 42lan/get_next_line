/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 11:04:28 by amalsago          #+#    #+#             */
/*   Updated: 2018/11/28 09:23:33 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"
#include "libft/libft.h"

int		main(int argc, char **argv)
{
	int		fd;
	char	*line;

	if (argc < 2)
	{
		ft_putstr("usage: ./a.out <filename>\n");
		return (1);
	}

	fd = open(argv[1], O_RDONLY);
	while (get_next_line(fd, &line) == 1)
	{
		ft_putendl(line);
		usleep(50000);
		free(line);
	}
	close(fd);
	return (0);
}
