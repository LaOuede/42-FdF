/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gle-roux <gle-roux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 10:54:19 by gle-roux          #+#    #+#             */
/*   Updated: 2023/04/25 15:00:31 by gle-roux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf_bonus.h"

void	ft_isometric_view(t_fdf *ms)
{
	ms->coord->proj_sx = (ms->coord->sx - ms->coord->sy) * cos(0.523599);
	ms->coord->proj_sy = (ms->coord->sx + ms->coord->sy) \
		* sin(0.523599) - ms->coord->sz;
	ms->coord->proj_ex = (ms->coord->ex - ms->coord->ey) * cos(0.523599);
	ms->coord->proj_ey = (ms->coord->ex + ms->coord->ey) \
		* sin(0.523599) - ms->coord->ez;
}

// Ignore the z-coordinate to generate a top view
void	ft_top_view(t_fdf *ms)
{
	ms->coord->proj_sx = ms->coord->sx;
	ms->coord->proj_sy = ms->coord->sy;
	ms->coord->proj_ex = ms->coord->ex;
	ms->coord->proj_ey = ms->coord->ey;
}

// Ignore the y-coordinate to generate a side view
void	ft_width_side_view(t_fdf *ms)
{
	ms->coord->proj_sx = ms->coord->sx;
	ms->coord->proj_sy = -ms->coord->sz;
	ms->coord->proj_ex = ms->coord->ex;
	ms->coord->proj_ey = -ms->coord->ez;
}

// Ignore the x-coordinate to generate a side view
void	ft_height_side_view(t_fdf *ms)
{
	ms->coord->proj_sx = ms->coord->sz;
	ms->coord->proj_sy = ms->coord->sy;
	ms->coord->proj_ex = ms->coord->ez;
	ms->coord->proj_ey = ms->coord->ey;
}

//void ft_alternate_side_view(t_fdf *ms)
// Project the x and y coordinates onto a new axis defined by the angle
void	ft_oblique_view(t_fdf *ms)
{
	double	angle;

	angle = -160.0 * (M_PI / 180.0);
	ms->coord->proj_sx = ms->coord->sx + cos(angle) * ms->coord->sz;
	ms->coord->proj_sy = ms->coord->sy + sin(angle) * ms->coord->sz;
	ms->coord->proj_ex = ms->coord->ex + cos(angle) * ms->coord->ez;
	ms->coord->proj_ey = ms->coord->ey + sin(angle) * ms->coord->ez;
}
