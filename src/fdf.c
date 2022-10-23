
#include "fdf.h"

void	set_default(t_dot *param)
{
	param->scale = 20;
	param->z_scale = 1;
	param->is_isometric = 1;
	param->angle = 0.8;
	param->shift_x = 2000 / 3;
	param->shift_y = 1000 / 3;
	param->mlx_ptr = mlx_init();
	param->win_ptr =\
	mlx_new_window(param->mlx_ptr, 2000, 1000, "FDF");
}

int		main(int argc, char **argv)
{
	t_dot	**matrix;

	if (argc != 2)
		ft_error();
	matrix = read_map(argv[1]);
	set_default(&PRM);
	draw(matrix);
	mlx_key_hook(PRM.win_ptr, deal_key, matrix);
	mlx_loop(PRM.mlx_ptr);
}
