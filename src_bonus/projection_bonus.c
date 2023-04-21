/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwenolaleroux <gwenolaleroux@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 10:54:19 by gle-roux          #+#    #+#             */
/*   Updated: 2023/04/21 11:57:37 by gwenolalero      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf_bonus.h"

void	ft_dontknow(t_fdf *ms)
{
	ms->coord->proj_sx = (ms->coord->sy + cos(2)) * ms->coord->sx;
	ms->coord->proj_sy = (ms->coord->sx + ms->coord->sy) \
		* sin(2) - ms->coord->sz;
	ms->coord->proj_ex = (ms->coord->ex - ms->coord->ey) * cos(1);
	ms->coord->proj_ey = (ms->coord->ex + ms->coord->ey) \
		* sin(1) - ms->coord->ez;
}

void	ft_isometric(t_fdf *ms)
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
/* void	ft_side_view(t_fdf *ms)
{
	ms->coord->proj_sx = ms->coord->sx;
	ms->coord->proj_sy = -ms->coord->sz;
	ms->coord->proj_ex = ms->coord->ex;
	ms->coord->proj_ey = -ms->coord->ez;
} */

void	ft_side_view(t_fdf *ms)
{
	ms->coord->proj_sx = ms->coord->sz;
	ms->coord->proj_sy = ms->coord->sy;
	ms->coord->proj_ex = ms->coord->ez;
	ms->coord->proj_ey = ms->coord->ey;
}

void	ft_projection(t_fdf *ms)
{
	if (ms->cam->projection == isometric)
		ft_isometric(ms);
	else if (ms->cam->projection == top_view)
		ft_top_view(ms);
	else if (ms->cam->projection == dontknow)
		ft_dontknow(ms);
	else if (ms->cam->projection == side_view)
		ft_side_view(ms);
}
