/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwenolaleroux <gwenolaleroux@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 09:11:47 by gle-roux          #+#    #+#             */
/*   Updated: 2023/04/10 15:56:01 by gwenolalero      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

/* Get the starting points on the screen */
/* void	get_x_y_start(t_fdf *ms)
{
	ms->map->x_start = (WIDTH / 2) - (ms->map->width / 2);
	ms->map->y_start = (HEIGHT / 2) + (ms->map->height / 2);
} */

/* Draw the points of the map */
void	ft_draw_map_square(t_fdf *ms)
{
	double	x;
	double	y;

	x = 0;
	while (x < (ms->map->width * 10))
	{
		y = 0;
		while (y < (ms->map->height * 10))
		{
			if (x < 0 || x > WIDTH || y < 0 || y > HEIGHT)
				ft_clean_up(ms, KRED"Coordinates error\n"KNRM);
			mlx_put_pixel(ms->image, x, y, 0xFF0000FF);
			y += 10;
		}
		x += 10;
	}
}

/* Draw a cross passing by the center of the window*/
void	ft_draw_cross(t_fdf *ms)
{
	int	x = 0;
	int	y = 0;

	while (x < WIDTH)
	{
		y = HEIGHT / 2;
		mlx_put_pixel(ms->image, x, y, 0xFFFF33);
		++x;
	}
	y = 0;
	while (y < HEIGHT)
	{
		x = WIDTH / 2;
		mlx_put_pixel(ms->image, x, y, 0xFFFF33);
		++y;
	}
}

/* Print map infos*/
void	ft_print_infos(t_fdf *ms)
{
	ft_printf("\n******* MAP infos : ******\n");
	ft_printf("   -> width  ="KYEL"  %d\n"KNRM, ms->map->width);
	ft_printf("   -> height ="KYEL"  %d\n"KNRM, ms->map->height);
	ft_printf("   -> color  ="KYEL"  %d\n"KNRM, ms->map->color);
	ft_printf("   -> z_max  ="KYEL"  %d\n"KNRM, ms->map->z_max);
	ft_printf("   -> z_min  ="KYEL"  %d\n"KNRM, ms->map->z_min);
	ft_printf("\n>>>>>> MAP / ms->map.matrix : <<<<<<\n");
	for(int rows = 0; rows < ms->map->height; rows++)
	{
		for(int columns = 0; columns < ms->map->width; columns++)
		{
			printf("%d ", ms->map->matrix[rows][columns]);
		}
		printf("\n");
	}
}

/* int	ft_valid_char(char c)
{
	if (c == '-' || c == 'x' || c == 'F' || c == 'f' || c == ',')
		return (1);
	if ('0' <= c && c <= '9')
		return (1);
	return (0);
} */
