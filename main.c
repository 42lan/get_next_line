/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 11:04:28 by amalsago          #+#    #+#             */
/*   Updated: 2018/11/30 11:51:47 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft/libft.h"
#include <fcntl.h>
#include <stdio.h>
#include <time.h>

void	open_fd(int *fd1, int *fd2, char **argv)
{
	*fd1 = open(argv[1], O_RDONLY);
	*fd2 = open(argv[2], O_RDONLY);
}

void	close_fd(int *fd1, int *fd2)
{
	close(*fd1);
	close(*fd2);
}

int		main(int argc, char **argv)
{
	char		*line;
	int			fd1;
	int			fd2;
	clock_t		begin;
	clock_t		end;

	(void)argc;
	open_fd(&fd1, &fd2, argv);
	begin = clock();
	while (get_next_line(fd1, &line))
	{
		printf("fd1: \t%s\n", line);
		if (fd2 > 0)
			if (get_next_line(fd2, &line))
				printf("fd2: \t%s\n", line);
		free(line);
	}
	end = clock();
	printf("%f\n\n", (double)(end - begin) / CLOCKS_PER_SEC);
	close_fd(&fd1, &fd2);
	return (0);
}
