/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gle-roux <gle-roux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 16:34:37 by gwenolalero       #+#    #+#             */
/*   Updated: 2023/04/18 11:07:16 by gle-roux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

/* Draw the points of the map */
/* void	ft_draw_map_square(t_fdf *ms)
{
	double	x;
	double	y;

	x = ms->map->x_start;
	while (x < (ms->map->x_start + ms->map->width * ms->cam->scale))
	{
		y = ms->map->y_start;
		while (y < (ms->map->y_start + ms->map->height * ms->cam->scale))
		{
			mlx_put_pixel(ms->image, (x + ms->cam->x_offset), (y + ms->cam->y_offset), 0xffffff);
			y += ms->cam->scale;
		}
		x += ms->cam->scale;
	}
} */

/*avant de déplacer ft_scale*/
void	ft_draw(t_fdf *ms)
{
	int	x;
	int	y;
	int	a;
	int	o;

	y = ms->y_start;
	o = 0;
	ft_map_erase(ms);
	while (y < (ms->y_start + ms->height * ms->cam->scale))
	{
		x = ms->x_start;
		a = 0;
		while (x < (ms->x_start + ms->width * ms->cam->scale))
		{
			if (x < (ms->x_start + ms->width * ms->cam->scale) - ms->cam->scale)
			{
				ms->coord->sx = x;
				ms->coord->sy = y;
				ms->coord->sz = ms->matrix[o][a];
				ms->coord->ex = x + ms->cam->scale;
				ms->coord->ey = y;
				ms->coord->ez = ms->matrix[o][a + 1];
				ft_projection(ms);
				ft_get_starting_points(ms);
				ft_dda_algo(ms);
			}
			if (y < (ms->y_start + ms->height * ms->cam->scale) - ms->cam->scale)
			{
				ms->coord->sx = x;
				ms->coord->sy = y;
				ms->coord->sz = ms->matrix[o][a];
				ms->coord->ex = x;
				ms->coord->ey = y + ms->cam->scale;
				ms->coord->ez = ms->matrix[o + 1][a];
				ft_projection(ms);

				ft_get_starting_points(ms);
				ft_dda_algo(ms);
			}
			x += ms->cam->scale;
			a++;
		}
		y += ms->cam->scale;
		o++;
	}
}

/* void	ft_draw_line(t_fdf *ms, t_point start, t_point end)
{
	int	x;
	int	y;

	ms->algo->delta_x = fabs(end.x - start.x);
	ms->algo->delta_y = fabs(end.y - start.y);
	ms->algo->ptp = (2 * ms->algo->delta_y) - ms->algo->delta_x;
	x = start.x;
	y = start.y;
	while(x < end.x)
	{
		if (ms->algo->ptp >= 0)
		{
			mlx_put_pixel(ms->image, (x + ms->cam->x_offset), (y + ms->cam->y_offset), 0xffffff);
			y += 1;
			ms->algo->ptp = ms->algo->ptp + 2 * ms->algo->delta_y - 2 * ms->algo->delta_x;
		}
		else
		{
			mlx_put_pixel(ms->image, (x + ms->cam->x_offset), (y + ms->cam->y_offset), 0xffffff);
			ms->algo->ptp = ms->algo->ptp + 2 * ms->algo->delta_y;
		}
		x += 1;
	}
} */

/*PAS ISO*/
/* int get_rgba(int r, int g, int b, int a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

void	ft_color(t_fdf *ms)
{
	if ((int)ms->coord->sz < 0)
		mlx_put_pixel(ms->image, (ms->algo->x + ms->cam->x_offset), \
				(ms->algo->y + ms->cam->y_offset), get_rgba(51, 51, 255, 255));
	else if ((int)ms->coord->start_z == 0)
		mlx_put_pixel(ms->image, (ms->algo->x + ms->cam->x_offset), \
				(ms->algo->y + ms->cam->y_offset), get_rgba(0, 0, 0, 255));
	else if ((int)ms->coord->start_z > 0)
		mlx_put_pixel(ms->image, (ms->algo->x + ms->cam->x_offset), \
				(ms->algo->y + ms->cam->y_offset), get_rgba(0, 204, 0, 255));
}

void	ft_draw_line(t_fdf *ms)
{
	ms->algo->delta_x = fabs(ms->coord->end_x - ms->coord->start_x);
	ms->algo->delta_y = fabs(ms->coord->end_y - ms->coord->start_y);
	ms->algo->ptp = (2 * ms->algo->delta_y) - ms->algo->delta_x;
	ms->algo->x = ms->coord->start_x;
	ms->algo->y = ms->coord->start_y;
	while(ms->algo->x < ms->coord->end_x)
	{
		if (ms->algo->ptp >= 0)
		{
			ft_color(ms);
			ms->algo->y += 1;
			ms->algo->ptp = ms->algo->ptp + 2 * ms->algo->delta_y - 2 * ms->algo->delta_x;
		}
		else
		{
			ft_color(ms);
			ms->algo->ptp = ms->algo->ptp + 2 * ms->algo->delta_y;
		}
		ms->algo->x += 1;
	}
	while(ms->algo->y <= ms->coord->end_y)
	{
		if (ms->algo->ptp >= 0)
		{
			ft_color(ms);
			ms->algo->ptp = ms->algo->ptp + 2 * ms->algo->delta_y - 2 * ms->algo->delta_x;
		}
		else
		{
			ft_color(ms);
			ms->algo->x += 1;
			ms->algo->ptp = ms->algo->ptp + 2 * ms->algo->delta_y;
		}
		ms->algo->y += 1;
	}
} */

/* ISO */
/* int get_rgba(int r, int g, int b, int a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

void	ft_color(t_fdf *ms)
{
	if ((int)ms->coord->start_z < 0)
		mlx_put_pixel(ms->image, (ms->algo->x + ms->cam->x_offset), \
				(ms->algo->y + ms->cam->y_offset), get_rgba(51, 51, 255, 255));
	else if ((int)ms->coord->start_z == 0)
		mlx_put_pixel(ms->image, (ms->algo->x + ms->cam->x_offset), \
				(ms->algo->y + ms->cam->y_offset), get_rgba(0, 0, 0, 255));
	else if ((int)ms->coord->start_z > 0)
		mlx_put_pixel(ms->image, (ms->algo->x + ms->cam->x_offset), \
				(ms->algo->y + ms->cam->y_offset), get_rgba(0, 204, 0, 255));
}

void	ft_bresenham(t_fdf *ms)
{
	ms->algo->delta_x = fabs(ms->iso->end_x - ms->iso->start_x);
	ms->algo->delta_y = fabs(ms->iso->end_y - ms->iso->start_y);
	ms->algo->ptp = (2 * ms->algo->delta_y) - ms->algo->delta_x;
	ms->algo->x = ms->iso->start_x;
	ms->algo->y = ms->iso->start_y;
	while(ms->algo->x < ms->iso->end_x)
	{
		if (ms->algo->ptp >= 0)
		{
			ft_color(ms);
			ms->algo->y += 1;
			ms->algo->ptp = ms->algo->ptp + 2 * ms->algo->delta_y - 2 * ms->algo->delta_x;
		}
		else
		{
			ft_color(ms);
			ms->algo->ptp = ms->algo->ptp + 2 * ms->algo->delta_y;
		}
		ms->algo->x += 1;
	}
	while(ms->algo->y <= ms->iso->end_y)
	{
		if (ms->algo->ptp >= 0)
		{
			ft_color(ms);
			ms->algo->ptp = ms->algo->ptp + 2 * ms->algo->delta_y - 2 * ms->algo->delta_x;
		}
		else
		{
			ft_color(ms);
			ms->algo->x += 1;
			ms->algo->ptp = ms->algo->ptp + 2 * ms->algo->delta_y;
		}
		ms->algo->y += 1;
	}
} */

/* PAS ISO*/
/* int get_rgba(int r, int g, int b, int a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

void	ft_color(t_fdf *ms)
{
	if ((int)ms->coord->start_z < 0)
		mlx_put_pixel(ms->image, (ms->coord->start_x + \
						ms->cam->x_offset), (ms->coord->start_y + \
						ms->cam->y_offset), get_rgba(51, 51, 255, 255));
	else if ((int)ms->coord->start_z == 0)
		mlx_put_pixel(ms->image, (ms->coord->start_x + \
						ms->cam->x_offset), (ms->coord->start_y + \
						ms->cam->y_offset), get_rgba(0, 0, 0, 255));
	else if ((int)ms->coord->start_z > 0)
		mlx_put_pixel(ms->image, (ms->coord->start_x + \
						ms->cam->x_offset), (ms->coord->start_y + \
						ms->cam->y_offset), get_rgba(0, 204, 0, 255));
}

void	ft_dda_algo(t_fdf *ms)
{
	int	pixel;

	ms->algo->delta_x = ms->coord->end_x - ms->coord->start_x;
	ms->algo->delta_y = ms->coord->end_y - ms->coord->start_y;
	ms->algo->delta_max = (int)fmax(fabs(ms->algo->delta_x), fabs(ms->algo->delta_y));
	ms->algo->delta_x /= ms->algo->delta_max;
	ms->algo->delta_y /= ms->algo->delta_max;
	pixel = -1;
	while (++pixel <= ms->algo->delta_max)
	{
		if (ms->coord->start_x > 0 && ms->coord->start_y > 0
			&& ms->coord->start_x < WIDTH && ms->coord->start_y < HEIGHT)
			ft_color(ms);
		ms->coord->start_x += ms->algo->delta_x;
		ms->coord->start_y += ms->algo->delta_y;
	}
} */

/* ISO */


void	ft_colorscheme(t_fdf *ms)
{
	if (ms->cam->colors == icewindale)
		ft_icewindale(ms);
	else if (ms->cam->colors == phandelver)
		ft_phandelver(ms);
	else if (ms->cam->colors == strahd)
		ft_strahd(ms);
	else if (ms->cam->colors == avernus)
		ft_avernus(ms);
}

void	ft_dda_algo(t_fdf *ms)
{
	int	pixel;

	ms->algo->delta_x = ms->coord->proj_ex - ms->coord->proj_sx;
	ms->algo->delta_y = ms->coord->proj_ey - ms->coord->proj_sy;
	if (fabs(ms->algo->delta_x) >= fabs(ms->algo->delta_y))
		ms->algo->delta_max = fabs(ms->algo->delta_x);
	else
		ms->algo->delta_max = fabs(ms->algo->delta_y);
	ms->algo->delta_x /= ms->algo->delta_max;
	ms->algo->delta_y /= ms->algo->delta_max;
	pixel = -1;
	while (++pixel <= ms->algo->delta_max)
	{
		if (ms->coord->proj_sx > 0 && ms->coord->proj_sy > 0
			&& ms->coord->proj_sx < WIDTH && ms->coord->proj_sy < HEIGHT)
			ft_colorscheme(ms);
		ms->coord->proj_sx += ms->algo->delta_x;
		ms->coord->proj_sy += ms->algo->delta_y;
	}
}
