/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwenolaleroux <gwenolaleroux@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 10:54:19 by gle-roux          #+#    #+#             */
/*   Updated: 2023/04/21 16:29:46 by gwenolalero      ###   ########.fr       */
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
void	ft_bottom_view(t_fdf *ms)
{
	ms->coord->proj_sx = ms->coord->sx;
	ms->coord->proj_sy = (ms->coord->sy * cos(3.14159)) + (ms->coord->sz * sin(3.14159));
	ms->coord->proj_ex = ms->coord->ex;
	ms->coord->proj_ey = (ms->coord->ey * cos(3.14159)) + (ms->coord->ez * sin(3.14159));
}

void	ft_projection(t_fdf *ms)
{
	if (ms->cam->projection == isometric_view)
		ft_isometric_view(ms);
	else if (ms->cam->projection == top_view)
		ft_top_view(ms);
	else if (ms->cam->projection == bottom_view)
		ft_bottom_view(ms);
	else if (ms->cam->projection == width_side_view)
		ft_width_side_view(ms);
	else if (ms->cam->projection == height_side_view)
		ft_height_side_view(ms);
}
