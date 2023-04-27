/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gle-roux <gle-roux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 10:54:19 by gle-roux          #+#    #+#             */
/*   Updated: 2023/04/27 08:13:44 by gle-roux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

/*
Isometric projection is a way of representing a 3D object on a 2D plane.
It is defined by a specific angle of 30 degrees (0.523599 radians).

Formulas:
proj_sx = (sx - sy) * cos(0.523599)
proj_sy = (sx + sy) * sin(0.523599) - sz
proj_ex = (ex - ey) * cos(0.523599)
proj_ey = (ex + ey) * sin(0.523599) - ez

Resulting values are the coordinates of the projected points on the 2D plane.

This function converts the coordinates of a line
in three-dimensional space to their corresponding isometric projection
in two-dimensional space, which can then be rendered on a computer screen.
*/
void	ft_isometric_view(t_fdf *ms)
{
	ms->coord->proj_sx = (ms->coord->sx - ms->coord->sy) \
		* cos(0.523599);
	ms->coord->proj_sy = (ms->coord->sx + ms->coord->sy) \
		* sin(0.523599) - ms->coord->sz;
	ms->coord->proj_ex = (ms->coord->ex - ms->coord->ey) * cos(0.523599);
	ms->coord->proj_ey = (ms->coord->ex + ms->coord->ey) \
		* sin(0.523599) - ms->coord->ez;
}

void	ft_top_view(t_fdf *ms)
{
	ms->coord->proj_sx = ms->coord->sx;
	ms->coord->proj_sy = ms->coord->sy;
	ms->coord->proj_ex = ms->coord->ex;
	ms->coord->proj_ey = ms->coord->ey;
}

void	ft_projection(t_fdf *ms)
{
	if (ms->cam->projection == isometric)
		ft_isometric_view(ms);
	else if (ms->cam->projection == top_view)
		ft_top_view(ms);
}
