/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibalbako <ibalbako@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 12:13:39 by ibalbako          #+#    #+#             */
/*   Updated: 2022/10/24 12:13:41 by ibalbako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "fdf.h"

int		get_dots_from_line(char *line, t_dot **tab_of_dots, int y)
{
	char	**dots;
	int		x;

	dots = ft_strsplit(line, ' ');
	x = 0;
	while (dots[x])
	{
		tab_of_dots[y][x].z = ft_atoi(dots[x]);
		tab_of_dots[y][x].x = x;
		tab_of_dots[y][x].y = y;
		tab_of_dots[y][x].is_last = 0;
		free(dots[x++]);
	}
	free(dots);
	free(line);
	tab_of_dots[y][--x].is_last = 1;
	return (x);
}

t_dot	**memory_allocete(char *file_name)
{
	t_dot	**new;
	int		x;
	int		y;
	int		fd;
	char	*line;

	if ((fd = open(file_name, O_RDONLY, 0)) <= 0)
		ft_error();
	line = get_next_line(fd);
	x = ft_wdcounter(line, ' ');
	free(line);
	y = 0;
	line = get_next_line(fd);
	while (line > 0)
	{
		y++;
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	new = (t_dot **)malloc(sizeof(t_dot *) * (++y + 1));
	while (y > 0)
		new[--y] = (t_dot *)malloc(sizeof(t_dot) * (x + 1));
	close(fd);
	return (new);
}

t_dot	**read_map(char *file_name)
{
	t_dot	**tab_of_dots;
	int		y;
	int		fd;
	char	*line;

	tab_of_dots = memory_allocete(file_name);
	fd = open(file_name, O_RDONLY, 0);
	y = 0;
	line = get_next_line(fd);
	while (line > 0)
	{
		get_dots_from_line(line, tab_of_dots, y++);
		line = get_next_line(fd);
	}
	free(line);
	tab_of_dots[y] = NULL;
	close(fd);
	return (tab_of_dots);
}
