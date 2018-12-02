/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 11:04:28 by amalsago          #+#    #+#             */
/*   Updated: 2018/12/01 20:47:42 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft/includes/libft.h"
#include <fcntl.h>
#include <stdio.h>

int		main(int argc, char **argv)
{
	char		*line;
	int			fd1;

	(void)argc;
	fd1 = open(argv[1], O_RDONLY);
	while (get_next_line(1000000, &line) == 1)
		ft_putendl(line);
	close(fd1);
	return (0);
}
