/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibalbako <ibalbako@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 12:13:00 by ibalbako          #+#    #+#             */
/*   Updated: 2022/10/24 12:13:03 by ibalbako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_close(t_dot **tab)
{
	mlx_destroy_window(TAB.mlx_ptr, TAB.win_ptr);
	free(tab);
	exit(0);
	return (0);
}
void	set_default(t_dot *param)
{
	param->scale = 20;
	param->z_scale = 1;
	param->is_isometric = 1;
	param->angle = 0.8;
	param->shift_x = 2000 / 3;
	param->shift_y = 1000 / 3;
	param->mlx_ptr = mlx_init();
	param->win_ptr = mlx_new_window(param->mlx_ptr, 2000, 1000, "FDF");
}

int		main(int argc, char **argv)
{
	t_dot	**tab;

	if (argc != 2)
		ft_error();
	tab = read_map(argv[1]);
	set_default(&TAB);
	draw(tab);
	mlx_key_hook(TAB.win_ptr, deal_key, tab);
	mlx_hook(TAB.win_ptr,17,0,ft_close,tab);
	mlx_loop(TAB.mlx_ptr);
}
