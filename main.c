/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 11:04:28 by amalsago          #+#    #+#             */
/*   Updated: 2018/11/29 17:41:14 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"
#include "libft/libft.h"
#include <time.h> ////////////////////////////////// SUPPRIMER //////////////////////////////////////

int		main(int argc, char **argv)
{
	(void)argc;
	char	*line;
	int		fd1 = open(argv[1], O_RDONLY);
	int		fd2 = open(argv[2], O_RDONLY);
	clock_t begin = clock();
	while (get_next_line(fd1, &line) == 1)
	{
		ft_putstr("fd1: \t"); ft_putendl(line);		// print 1st line of 1st fd (fd1)
		if (fd2 > 0)
			if (get_next_line(fd2, &line) > 0)
			{
				ft_putstr("fd2: \t");
				ft_putendl(line);		// print 1st line of 2nd fd (fd2)
			}
		//usleep(50000);
		free(line);
	}
	clock_t end = clock();
	double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	printf("%f\n\n", time_spent);
	ft_putnbr(OPEN_MAX);
	ft_putendl(" = OPEN_MAX");
	close(fd1);
	close(fd2);
	return (0);
}
