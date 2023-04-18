/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gle-roux <gle-roux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 16:34:37 by gwenolalero       #+#    #+#             */
/*   Updated: 2023/04/18 12:15:42 by gle-roux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

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
			{
				ft_init_line_x(ms);
				ft_map_scale(ms);
				ft_projection(ms);
				ft_get_starting_points(ms);
				ft_dda_algo(ms);
			}
			if (ms->y < ms->height - 1)
			{
				ft_init_line_y(ms);
				ft_map_scale(ms);
				ft_projection(ms);
				ft_get_starting_points(ms);
				ft_dda_algo(ms);
			}
		}
	}
}
