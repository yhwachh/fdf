#ifndef     FDF_H
# define    FDF_H

# include "../libft/libft.h"
# include "../mlx/mlx.h"

typedef struct  s_fdf
{
    int width;
    int height;
    int **map;

    void    *mlx_ptr;
    void    *win_ptr;
}           t_fdf;


int    ft_read_file(char *name, t_fdf *data);
void    remplisage(int *map, char *line);
int     get_width(char *name);
int     get_height(char *name);
int     ft_sep2(char const *s, char c);


#endif