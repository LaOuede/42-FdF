/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwenolaleroux <gwenolaleroux@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 10:54:19 by gle-roux          #+#    #+#             */
/*   Updated: 2023/04/25 18:05:01 by gwenolalero      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf_bonus.h"

/* The isometric projection is a way of representing a three-dimensional object
on a two-dimensional plane. In this case, the isometric projection is defined
by a specific angle of 30 degrees or 0.523599 radians.

To calculate the isometric projection, the function uses the following formulas:

proj_sx = (sx - sy) * cos(0.523599)
proj_sy = (sx + sy) * sin(0.523599) - sz
proj_ex = (ex - ey) * cos(0.523599)
proj_ey = (ex + ey) * sin(0.523599) - ez
These formulas involve basic trigonometry functions and simple arithmetic
operations. The resulting values are the coordinates of the projected points
on the two-dimensional plane.

Overall, this function is used to convert the coordinates of a line
in three-dimensional space to their corresponding isometric projection
in two-dimensional space, which can then be rendered on a computer screen. */
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
/* This code defines a function ft_oblique_view that takes a pointer to
a t_fdf struct as an argument. The purpose of this function is to
calculate the coordinates of the endpoints of a line in an oblique
2D projection, given the 3D coordinates of the endpoints in the
t_fdf struct.

The function first sets a variable angle to -160 degrees converted
to radians. This angle is used to specify the direction of
the oblique projection.

The function then calculates the x and y coordinates of the
projected start point proj_sx and proj_sy using the following formulas:

proj_sx = sx + cos(angle) * sz
proj_sy = sy + sin(angle) * sz
These formulas use the cosine and sine functions to calculate
the x and y components of the projection, based on the angle
of projection and the z component of the start point.

The function then calculates the x and y coordinates of the
projected end point proj_ex and proj_ey using similar formulas:

proj_ex = ex + cos(angle) * ez
proj_ey = ey + sin(angle) * ez
These formulas use the cosine and sine functions to calculate
the x and y components of the projection, based on the angle
of projection and the z component of the end point.

Overall, this function implements an oblique projection by
skewing the original 3D coordinates along a specified angle
to produce 2D coordinates for rendering on a flat surface. */
void	ft_oblique_view(t_fdf *ms)
{
	double	angle;

	angle = -160.0 * (M_PI / 180.0);
	ms->coord->proj_sx = ms->coord->sx + cos(angle) * ms->coord->sz;
	ms->coord->proj_sy = ms->coord->sy + sin(angle) * ms->coord->sz;
	ms->coord->proj_ex = ms->coord->ex + cos(angle) * ms->coord->ez;
	ms->coord->proj_ey = ms->coord->ey + sin(angle) * ms->coord->ez;
}
