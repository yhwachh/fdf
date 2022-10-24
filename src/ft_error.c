/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibalbako <ibalbako@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 12:13:20 by ibalbako          #+#    #+#             */
/*   Updated: 2022/10/24 12:13:23 by ibalbako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "fdf.h"

void	ft_error(void)
{
	write(1, "Error\n", 6);
	exit(1);
}

/*	------------------------------------------- How to do -------------------------------------------
**	1. read file
**		- get height(how many lines) of text
**		- get width(how many numbers in line)
**		- allocate memory for **int by using width and height (look your ft_strsplit() )
**		- read file and write number into **int matrix
**				by using ft_strsplit() and atoi()
**	--------------
**	2. drawing line function (google Bresenham algorithm)
**		- find by how much we need to increase x and by how much we need to increase y
**			by using float. Example:
**				x = 2; x1 = 4;
**				y = 2; y1 = 6;
**				steps for x: 2
**				steps for y: 4
**				that means that y should grow 2 times faster than x
**				ewery loop step: y += 1 and x += 0.5
**				after 4 steps x and y will be equal with x1, y1
**
**					real x:y		x:y     pixels				
**			start:		2.0 : 2.0		2:2        .
**			step1:		2.5 : 3.0		2:3        .
**			step2:		3.0 : 4.0		3:4         .
**			step3:		3.5 : 5.0		3:5         .
**			step4:		4.0 : 6.0		4:6          .
**
**				that works because (float)2.5 turns to (int)2 in func. mlx_pixel_put()
**	--------------
**	3. function which draws lines beetwen every dot
**		- examle:
**				0->		0->		0->		0
**				|		|		|		|
**				
**				0->		10->            10->            0
**				|		|		|		|
**				
**				0->		10->            10->            0
**				|		|		|		|
**				
**				0->		0->		0->		0
**			'->' and '|'are lines between dots 
**			every dot has two lines (right and down):	0->
**                                                                      |
**	----------------
**	4. adding 3D
**		- change coordinates by using isometric formulas:
**			x` = (x - y) * cos(angle)
**			y` = (x + y) * sin(angle) - z
**		- x` and y` are coordintes in 3D format (default angle 0.8)
**	----------------
**	5. adding donuses (move, rotation, zoom)
**		- when you press button on keyboard the func. mlx_key_hook(win_ptr, deal_key, NULL);
**			call the func. deal_key.
**		- In the deal key func. you have to change some parametrs, clear the window with
**			mlx_clear_window(mlx_ptr, win_ptr); and redraw the picture
**	----------------
**	6. error handling
**		- check if argc == 2
**		- check if file exists: if ((fd = open(file_name, O_RDONLY) > 0))
**	----------------
**	7. fix leaks
**		- type leaks a.out or leaks fdf in your shell

**  ------------------------------- resourses --------------------------------
**	--------------- 3D ------------------------------------------
**		x` = (x - y) * cos(angle);
**		y` = (x + y) * sin(angle) - z;
**	-------------------------------------------------------------
** 	------- mlx_function ----------------------------------------
**		void *mlx_ptr;
**		void *win_prt;
**
**		mlx_ptr = mlx_init();
**		win_prt = mlx_new_window(mlx_ptr, 1000, 1000, "FDF");
**
**		mlx_pixel_put(mlx_ptr, win_ptr, (int)x, (int)y, #color);
**
**		mlx_key_hook(win_ptr, deal_key, NULL);
**		mlx_loop(mlx_ptr);
**	--------------------------------------------------------------
**	------- deal_key prototype -----------------------------------
**		int		deal_key(int key, void *data);
**	--------------------------------------------------------------
**	colors:
**		white = 0xffffff
**		red = 0xe80c0c
**	----------------------------
**	frameworks:
**		-framework OpenGL -framework AppKit


float   mod(float i)
{
    return(i < 0) ? -i : i;
}

void    isometric(float *x, float *y, int z)
{
    *x = (*x - *y) * cos(0.8);
    *y = (*x + *y) * sin(0.8) - z;
}*/

/*
void    bresenham(float x, float y, float x1, float y1, t_fdf *data)
{
    float   x_step;
    float   y_step;
    int     max;
    int     z;
    int     z1;

    z = data->map[(int)y][(int)x];
    z1 = data->map[(int)y1][(int)x1];  
    //zoom
    x  = x * data->zoom;
    y  = y * data->zoom;
    x1  = x1 * data->zoom;
    y1  = y1 * data->zoom;

    //color
    data->color = (z || z1) ? 0xe80c0c : 0xffffff;
    //3D format
    //isometric(&x, &y, z);
    //isometric(&x1, &y1, z1); 
    // shift
    x = x + data->zoom;
    y = y + data->zoom;
    x1 = x1 + data->zoom;
    y1 = y1 + data->zoom;
    // combien doit'on faire de pa pour chaque coordonné [1,1] [3,12]
    x_step = x1 - x; // 2
    y_step = y1 - y; // 11
    // pour chaque sycle il faut print un pixel san pour auton faire plus que un pa
    // pour pas avoir de gros interval, donc y(11)  doit avoncer 5 pixel plus vite que x(2)
    // mais cela fait trop grand donc , donc on fais l'inverse; y avonce de 1 et x , 11 fois moi que y 
    // pour ce calcul on fais une division du chiffre max mais max en terme de modul(E : -11 > -2);
    max = (mod(x_step) > mod(y_step)) ? mod(x_step) : mod(y_step);
    x_step = x_step / max;
    y_step = y_step / max; 
    // print les pixels
    // convertire en int car qaund il vas se rapocher d'un chiffre arondi a 0 il vas s'arreter
    while ((int)(x - x1 || (int)(y - y1)))
    {
        mlx_pixel_put(data->mlx_ptr, data->win_ptr, x, y, data->color);
        x = x + x_step;
        y = y + y_step;
    }
    
}
*/
