/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwenolaleroux <gwenolaleroux@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 10:54:19 by gle-roux          #+#    #+#             */
/*   Updated: 2023/04/21 20:26:52 by gwenolalero      ###   ########.fr       */
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
//This implementation sets the projection angle to 45 degrees, which is equivalent to pi/4 radians. The function then calculates the cosine and sine of the angle, as before. The projected coordinates are then calculated using either the formula for isometric or oblique projection, depending on the value of the projection_type parameter.
//Note that this implementation assumes that the projection is in the direction of the positive x-axis for the oblique projection. If you need to support different projection directions, you'll need to modify the calculation accordingly.

void	ft_projection(t_fdf *ms)
{
	if (ms->cam->projection == isometric_view)
		ft_isometric_view(ms);
	else if (ms->cam->projection == top_view)
		ft_top_view(ms);
	else if (ms->cam->projection == oblique_view)
		ft_oblique_view(ms);
	else if (ms->cam->projection == width_side_view)
		ft_width_side_view(ms);
	else if (ms->cam->projection == height_side_view)
		ft_height_side_view(ms);
}
