/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gle-roux <gle-roux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 10:54:19 by gle-roux          #+#    #+#             */
/*   Updated: 2023/04/26 11:01:08 by gle-roux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf_bonus.h"

/*
The isometric projection is a way of representing a three-dimensional object
on a two-dimensional plane. It is defined by a specific angle of 30 degrees
(0.523599 radians).

Formulas:
proj_sx = (sx - sy) * cos(0.523599)
proj_sy = (sx + sy) * sin(0.523599) - sz
proj_ex = (ex - ey) * cos(0.523599)
proj_ey = (ex + ey) * sin(0.523599) - ez

Resulting values are the coordinates of the projected points on the
two-dimensional plane.

This function converts the coordinates of a line
in three-dimensional space to their corresponding isometric projection
in two-dimensional space, which can then be rendered on a computer screen.
*/
void	ft_isometric_view(t_fdf *ms)
{
	ms->coord->proj_sx = (ms->coord->sx - ms->coord->sy) * cos(0.523599);
	ms->coord->proj_sy = (ms->coord->sx + ms->coord->sy) \
		* sin(0.523599) - ms->coord->sz;
	ms->coord->proj_ex = (ms->coord->ex - ms->coord->ey) * cos(0.523599);
	ms->coord->proj_ey = (ms->coord->ex + ms->coord->ey) \
		* sin(0.523599) - ms->coord->ez;
}

/* Ignores the z-coordinate to generate a top view */
void	ft_top_view(t_fdf *ms)
{
	ms->coord->proj_sx = ms->coord->sx;
	ms->coord->proj_sy = ms->coord->sy;
	ms->coord->proj_ex = ms->coord->ex;
	ms->coord->proj_ey = ms->coord->ey;
}

/* Ignores the y-coordinate to generate a side view */
void	ft_width_side_view(t_fdf *ms)
{
	ms->coord->proj_sx = ms->coord->sx;
	ms->coord->proj_sy = -ms->coord->sz;
	ms->coord->proj_ex = ms->coord->ex;
	ms->coord->proj_ey = -ms->coord->ez;
}

/* Ignores the x-coordinate to generate a side view */
void	ft_height_side_view(t_fdf *ms)
{
	ms->coord->proj_sx = ms->coord->sz;
	ms->coord->proj_sy = ms->coord->sy;
	ms->coord->proj_ex = ms->coord->ez;
	ms->coord->proj_ey = ms->coord->ey;
}

/*
Calculates the coordinates of the endpoint in an oblique 2D projection, given
the 3D coordinates of the endpoints. The function first sets a variable angle
converted to radians. This angle is used to specify the direction of 
the oblique projection.

Formulas:
proj_sx = sx + cos(angle) * sz
proj_sy = sy + sin(angle) * sz
Formulas use the cos and sin functions to calculate the x and y components 
of the projection, based on the angle of projection and the z component of
the start point.
*/
void	ft_oblique_view(t_fdf *ms)
{
	double	angle;

	angle = 180.0 * (PI / 180.0);
	ms->coord->proj_sx = ms->coord->sx + cos(angle) * ms->coord->sz;
	ms->coord->proj_sy = ms->coord->sy + sin(angle) * ms->coord->sz;
	ms->coord->proj_ex = ms->coord->ex + cos(angle) * ms->coord->ez;
	ms->coord->proj_ey = ms->coord->ey + sin(angle) * ms->coord->ez;
}
