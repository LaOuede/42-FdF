/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gle-roux <gle-roux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 16:34:37 by gwenolalero       #+#    #+#             */
/*   Updated: 2023/04/11 15:36:41 by gle-roux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

/* void	ft_find_scale(t_fdf *ms)
{
	while (42)
	{
		if (ft_limits(ms) == T)
			ms->map->scale += 5;
	}
	ft_printf("   -> scale  ="KYEL"  %d\n"KNRM, ms->map->scale);
}
 */

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
			mlx_put_pixel(ms->image, (x + ms->map->x_offset), (y + ms->map->y_offset), 0xFFFFFF);
			y += ms->map->scale;
		}
		x += ms->map->scale;
	}
}

/* Draw the points of the previous image with the background color */
void	ft_draw_map_erase(t_fdf *ms)
{
	double	x;
	double	y;

	x = 0;
	while (x < (ms->map->width * ms->map->scale))
	{
		y = 0;
		while (y < (ms->map->height * ms->map->scale))
		{
			mlx_put_pixel(ms->image, (x + ms->map->x_offset), (y + ms->map->y_offset), 0x151515);
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
