/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubaujar <lubaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/19 23:16:10 by lubaujar          #+#    #+#             */
/*   Updated: 2014/12/08 01:07:13 by lubaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "get_next_line.h"

int	main(int argc, char **argv)
{
	int		fd;
	int		i;
	char	*buff_main;

	if (argc > 1)
	{
		i = 1;
		fd = open(argv[i], O_RDONLY);
		buff_main = *argv;
		buff_main = (char *)malloc(sizeof(char *) * BUFF_SIZE);
		while (get_next_line(fd, &buff_main) == 1)
		{
			ft_putendl(buff_main);
			ft_putchar('\n');
		}
	}
	return (0);
}
