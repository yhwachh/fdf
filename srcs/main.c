#include "../includes/fdf.h"
#include <stdio.h>


int     main(int argc, char **argv)
{
    t_fdf *data;

    if(argc != 2)
    {
        return(write(1, "Error", 5));
    }
    data = (t_fdf*)malloc(sizeof(t_fdf));
    ft_read_file(argv[1], data);

    int i = 0;
    int j = 0;

    while (i < data->height - 1)
    {
        j = 0;
        while (j < data->width)
        {
            printf("%3d", data->map[i][j]);
            j++;
        }
        printf("\n");
        i++;

    }
    return (0);
    
}