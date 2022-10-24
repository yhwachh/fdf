/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_key.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibalbako <ibalbako@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 12:12:47 by ibalbako          #+#    #+#             */
/*   Updated: 2022/10/24 12:12:49 by ibalbako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "fdf.h"

void	do_key(int key, t_dot **tab)
{
	if (key == 24 || key == 69)
		TAB.scale += 3;
	if (key == 27 || key == 78)
		TAB.scale -= 3;
	if (key == 126)
		TAB.shift_y -= 10;
	if (key == 125)
		TAB.shift_y += 10;
	if (key == 123)
		TAB.shift_x -= 10;
	if (key == 124)
		TAB.shift_x += 10;

}

int		deal_key(int key, t_dot **tab)
{
	if (key == 24 || key == 69 || key == 27 || key == 78 ) 
	{
		mlx_clear_window(TAB.mlx_ptr, TAB.win_ptr);
		do_key(key, tab);
		draw(tab);
	}
	if (key == 126 || key == 125 || key == 123 || key == 124)
	{
		mlx_clear_window(TAB.mlx_ptr, TAB.win_ptr);
		do_key(key, tab);
		draw(tab);
	}
	if (key == '5')
	{
		mlx_destroy_window(TAB.mlx_ptr, TAB.win_ptr);
		free(tab);
		exit(0);
	}
	return (0);
}
