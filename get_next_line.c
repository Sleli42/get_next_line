/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubaujar <lubaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/18 23:18:08 by lubaujar          #+#    #+#             */
/*   Updated: 2014/12/08 01:07:03 by lubaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "get_next_line.h"

int		ft_strlen_line(char *buff)
{
	int	len;

	len = 0;
	while (buff[len] && buff[len] != '\n')
		len++;
	return (len);
}

char	*ft_read_file(int fd)
{
	char	*ret;
	char	buff[BUFF_SIZE + 1];
	int		read_all;

	read_all = 1;
	ret = ft_strnew(sizeof(char) + 1);
	if (buff == NULL)
		return (NULL);
	while ((read_all = read(fd, buff, BUFF_SIZE)) != 0)
	{
		if (read_all < 0)
			return (NULL);
		buff[read_all] = '\0';
		ret = ft_strjoin(ret, buff);
		if (ret == NULL)
			return (NULL);
		ft_memset(buff, 0, read_all);
	}
	return (ret);
}

int	get_next_line(int const fd, char **line)
{
	static char	*buff;

	if (fd < 0 && fd > 2)
		return (-1);
	if (buff == NULL)
	{
		buff = ft_read_file(fd);
		if (buff == NULL)
			return (-1);
	}
	*line = ft_strsub(buff, 0, ft_strlen_line(buff));
	if (*line == NULL)
		return (-1);
	buff = buff + ft_strlen_line(buff);
	if (*buff == '\0')
		return (0);
	buff++;
	return (1);
}
