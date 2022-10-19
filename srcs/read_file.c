#include "../includes/fdf.h"


int     ft_sep2(char const *s, char c)
{
	int	t;
	int	n;

	t = 0;
	n = 0;
	while (s[t] != '\0')
	{
		if (s[t] == c && s[t + 1] != '\0' && s[t + 1] != c)
			++n;
		++t;
	}
	++n;
	return (n);
}

int     get_height(char *name)
{
    char    *line;
    int     fd;
    int     height;

    fd = 0;
    height = 0;
    fd = open(name, O_RDONLY);
    if (fd == -1)
        return (write(1, "Error", 5));
    line = get_next_line(fd);
    while (line)
    {
        height++;
        free(line);
        line = get_next_line(fd);
        if(line == NULL || fd == -1)
            break;
    }
    close(fd);
    return (height);
}

int     get_width(char *name)
{
    int     width;
    char    *line;
    int     fd;

    fd = open(name, O_RDONLY);
    if (fd == -1)
        return (write(1, "Error", 5));
    line = get_next_line(fd);
    width = ft_sep2(line, ' ');
    close(fd);
    return(width);
}

void    remplisage(int *map, char *line)
{
    char    **num;
    int     i;

    num = NULL;
    i = 0;
    num = ft_strsplit(line, ' ');
    while (num[i])
    {
        map[i] = ft_atoi(num[i]);
        free(num[i]);
        i++; 
    }
    free(num);
}


int    ft_read_file(char *name, t_fdf *data)
{
    int     fd;
    char    *line;
    int     i;

    fd = 0;
    i = 0;
    line = NULL;
    data->height = get_height(name);
    data->width = get_width(name);

    data->map = (int **)malloc(sizeof(int*) * (data->height + 1));
    while (i <= data->height)
    {
        data->map[i] = (int*)malloc(sizeof(int) * (data->width + 1));
        i++;
    }
    if ((fd = open(name, O_RDONLY)) == -1)
        return (write(1, "Error", 5));
    i = 0;
    line = get_next_line(fd);
    while (line)
    {
        remplisage(data->map[i], line);
        free(line);
        line = get_next_line(fd);
        if(line == NULL || fd == -1)
            break;
        i++;
    }
    data->map[i] = NULL;
    close(fd);
    return (0);
}
