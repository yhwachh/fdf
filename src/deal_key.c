
#include "fdf.h"

void	do_key(int key, t_dot **matrix)
{
	if (key == 24 || key == 69)
		PRM.scale += 3;
	if (key == 27 || key == 78)
		PRM.scale -= 3;
	if (key == 126)
		PRM.shift_y -= 10;
	if (key == 125)
		PRM.shift_y += 10;
	if (key == 123)
		PRM.shift_x -= 10;
	if (key == 124)
		PRM.shift_x += 10;
}

int		deal_key(int key, t_dot **matrix)
{
	if (key == 24 || key == 69 || key == 27 || key == 78 ) 
	{
		mlx_clear_window(PRM.mlx_ptr, PRM.win_ptr);
		do_key(key, matrix);
		draw(matrix);
	}
	if (key == 126 || key == 125 || key == 123 || key == 124)
	{
		mlx_clear_window(PRM.mlx_ptr, PRM.win_ptr);
		do_key(key, matrix);
		draw(matrix);
	}
	if (key == '5')
	{
		mlx_destroy_window(PRM.mlx_ptr, PRM.win_ptr);
		free(matrix);
		exit(0);
	}
	return (0);
}
