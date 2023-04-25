/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gle-roux <gle-roux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 16:34:37 by gwenolalero       #+#    #+#             */
/*   Updated: 2023/04/25 14:58:49 by gle-roux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf_bonus.h"

void	ft_dda_algo(t_fdf *ms)
{
	ms->algo->delta_x = ms->coord->proj_ex - ms->coord->proj_sx;
	ms->algo->delta_y = ms->coord->proj_ey - ms->coord->proj_sy;
	if (fabs(ms->algo->delta_x) >= fabs(ms->algo->delta_y))
		ms->algo->delta_max = fabs(ms->algo->delta_x);
	else
		ms->algo->delta_max = fabs(ms->algo->delta_y);
	ms->algo->delta_x /= ms->algo->delta_max;
	ms->algo->delta_y /= ms->algo->delta_max;
	ms->algo->pixel = -1;
	while (++(ms->algo->pixel) <= ms->algo->delta_max)
	{
		if (ms->coord->proj_sx > MARGE && ms->coord->proj_sy > MARGE
			&& ms->coord->proj_sx < WIDTH - MENU_WIDTH - MARGE
			&& ms->coord->proj_sy < HEIGHT - MARGE)
			ft_colorscheme(ms);
		ms->coord->proj_sx += ms->algo->delta_x;
		ms->coord->proj_sy += ms->algo->delta_y;
	}
}

void	ft_draw_x(t_fdf *ms)
{
	ft_init_line_x(ms);
	if (ms->cam->angle_x != 0 || ms->cam->angle_y != 0 || ms->cam->angle_z != 0)
		ft_rotation(ms);
	ft_map_scale(ms);
	ft_projection(ms);
	ft_get_starting_points(ms);
	ft_translation(ms);
	if (ms->cam->zoom >= -19)
		ft_dda_algo(ms);
}

void	ft_draw_y(t_fdf *ms)
{
	ft_init_line_y(ms);
	if (ms->cam->angle_x != 0 || ms->cam->angle_y != 0 || ms->cam->angle_z != 0)
		ft_rotation(ms);
	ft_map_scale(ms);
	ft_projection(ms);
	ft_get_starting_points(ms);
	ft_translation(ms);
	if (ms->cam->zoom >= -19)
		ft_dda_algo(ms);
}

/* Draw the points of the previous image with the background color */
void	ft_map_erase(t_fdf *ms)
{
	double	x;
	double	y;

	x = 0;
	while (x < WIDTH)
	{
		y = 0;
		while (y < HEIGHT)
		{
			mlx_put_pixel(ms->image, x, y, ft_get_rgba(102, 102, 102, 115));
			y++;
		}
		x++;
	}
}

/* Draw the points of the map */
void	ft_draw(t_fdf *ms)
{
	ft_map_erase(ms);
	ms->y = -1;
	while (++ms->y < ms->height)
	{
		ms->x = -1;
		while (++ms->x < ms->width)
		{
			if (ms->x < ms->width - 1)
				ft_draw_x(ms);
			if (ms->y < ms->height - 1)
				ft_draw_y(ms);
		}
	}
}
