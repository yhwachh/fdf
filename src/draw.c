/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibalbako <ibalbako@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 12:12:54 by ibalbako          #+#    #+#             */
/*   Updated: 2022/10/24 12:12:56 by ibalbako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "fdf.h"

float   mod(float i)
{
    return(i < 0) ? -i : i;
}

void	line(t_dot a, t_dot b, t_dot *param)
{
	float	step_x;
	float	step_y;
	float	max;
	int		color;

	set_param(&a, &b, param);
	step_x = b.x - a.x;
	step_y = b.y - a.y;
	max = (mod(step_x) > mod(step_x)) ? mod(step_x) : mod(step_x);
	step_x /= max;
	step_y /= max;
	color = (b.z || a.z) ? 0xe80c0c : 0xffffff;
	while ((int)(a.x - b.x) || (int)(a.y - b.y))
	{
		mlx_pixel_put(param->mlx_ptr, param->win_ptr, a.x, a.y, color);
		a.x += step_x;
		a.y += step_y;
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
