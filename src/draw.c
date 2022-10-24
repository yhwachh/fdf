/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibalbako <ibalbako@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 12:12:54 by ibalbako          #+#    #+#             */
/*   Updated: 2022/10/24 14:26:56 by ibalbako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

float	mod(float i)
{
	if (i < 0)
		return (-i);
	return (i);
}

void	line(t_dot a, t_dot b, t_dot *tab)
{
	float	max;
	int		color;

	set_param(&a, &b, tab);
	tab->step_x = b.x - a.x;
	tab->step_y = b.y - a.y;
	if (mod(tab->step_x) > mod(tab->step_y))
		max = mod(tab->step_x);
	else
		max = mod(tab->step_y);
	tab->step_x /= max;
	tab->step_y /= max;
	if (b.z || a.z)
		color = 0xe80c0c;
	else
		color = 0xffffff;
	while ((int)(a.x - b.x) || (int)(a.y - b.y))
	{
		mlx_pixel_put(tab->mlx_ptr, tab->win_ptr, a.x, a.y, color);
		a.x += tab->step_x;
		a.y += tab->step_y;
		if (a.x > 2000 || a.y > 1000 || a.y < 0 || a.x < 0)
			break ;
	}
}

void	draw(t_dot **tab)
{
	int		y;
	int		x;

	y = 0;
	while (tab[y])
	{
		x = 0;
		while (1)
		{
			if (tab[y + 1])
				line(tab[y][x], tab[y + 1][x], &TAB);
			if (!tab[y][x].is_last)
				line(tab[y][x], tab[y][x + 1], &TAB);
			if (tab[y][x].is_last)
				break ;
			x++;
		}
		y++;
	}
}
