/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwenolaleroux <gwenolaleroux@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 16:34:37 by gwenolalero       #+#    #+#             */
/*   Updated: 2023/04/10 16:34:45 by gwenolalero      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

/* Get the starting points on the screen */
void	ft_get_starting_points(t_fdf *ms)
{
	ms->map->x_start = (WIDTH / 2) - (ms->map->width * ms->map->scale / 2);
	ms->map->y_start = (HEIGHT / 2) - (ms->map->height * ms->map->scale / 2);
}

/* Draw the points of the map */
void	ft_draw_map_square(t_fdf *ms)
{
	double	x;
	double	y;

	x = 0;
	while (x < (ms->map->width * ms->map->scale))
	{
		y = 0;
		while (y < (ms->map->height * ms->map->scale))
		{
			if (x < 0 || x > WIDTH || y < 0 || y > HEIGHT)
				ft_clean_up(ms, KRED"Coordinates error\n"KNRM);
			mlx_put_pixel(ms->image, x, y, 0xFFFFFF);
			y += ms->map->scale;
		}
		x += ms->map->scale;
	}
}

/* Draw a cross passing by the center of the window*/
void	ft_draw_cross(t_fdf *ms)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
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
