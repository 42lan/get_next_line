/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 11:04:28 by amalsago          #+#    #+#             */
/*   Updated: 2018/11/26 16:10:31 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
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
	if (get_next_line(fd, &line) == 1)
	{
		ft_putstr("\n-----------FIRST CALL----------------\n");
		ft_putchar('|');
		ft_putstr(line);
		ft_putchar('|');
	}
	if (get_next_line(fd, &line) == 1)
	{
		ft_putstr("\n----------SECOND CALL--------------\n");
		ft_putchar('|');
		ft_putstr(line);
		ft_putchar('|');
	}
	if (get_next_line(fd, &line) == 1)
	{
		ft_putstr("\n----------THIRD CALL--------------\n");
		ft_putchar('|');
		ft_putstr(line);
		ft_putchar('|');
	}
	close(fd);
	return (0);
}
