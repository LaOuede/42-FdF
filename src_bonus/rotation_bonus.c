/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gle-roux <gle-roux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 10:50:41 by gle-roux          #+#    #+#             */
/*   Updated: 2023/04/26 11:25:37 by gle-roux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf_bonus.h"

/*
Performs a rotation around the x-axis

sy = (sy * cos(cam->angle_x)) - (sz * sin(cam->angle_x)) rotates the 
y-coordinate of the start point (sx, sy, sz) taking into account the x-axis 
by an angle specified by cam->angle_x.

cam->z_offset * 3 is a correction factor.
*/
void	ft_rotation_x(t_fdf *ms)
{
	ms->coord->sy = (ms->coord->sy * cos(ms->cam->angle_x)) - \
	(ms->coord->sz * sin(ms->cam->angle_x)) / (ms->cam->z_offset * 3);
	ms->coord->proj_sz = (ms->coord->sy * sin(ms->cam->angle_x)) + \
	(ms->coord->sz * cos(ms->cam->angle_x)) / (ms->cam->z_offset * 3);
	ms->coord->ey = (ms->coord->ey * cos(ms->cam->angle_x)) - \
	(ms->coord->ez * sin(ms->cam->angle_x)) / (ms->cam->z_offset * 3);
	ms->coord->proj_ez = (ms->coord->ey * sin(ms->cam->angle_x)) + \
	(ms->coord->ez * cos(ms->cam->angle_x)) / (ms->cam->z_offset * 3);
}

/* Performs a rotation around the y-axis */
void	ft_rotation_y(t_fdf *ms)
{
	ms->coord->sx = (ms->coord->sx * cos(ms->cam->angle_y)) + \
	(ms->coord->sz * sin(ms->cam->angle_y)) / (ms->cam->z_offset * 3);
	ms->coord->proj_sz = (ms->coord->sx * sin(ms->cam->angle_y)) + \
	(ms->coord->sz * cos(ms->cam->angle_y)) / (ms->cam->z_offset * 3);
	ms->coord->ex = (ms->coord->ex * cos(ms->cam->angle_y)) + \
	(ms->coord->ez * sin(ms->cam->angle_y)) / (ms->cam->z_offset * 3);
	ms->coord->proj_ez = (ms->coord->ex * sin(ms->cam->angle_y)) + \
	(ms->coord->ez * cos(ms->cam->angle_y)) / (ms->cam->z_offset * 3);
}

/* Performs a rotation around the z-axis */
void	ft_rotation_z(t_fdf *ms)
{
	ms->coord->sx = (ms->coord->sx * cos(ms->cam->angle_z)) + \
	(ms->coord->sy * sin(ms->cam->angle_z));
	ms->coord->sy = (ms->coord->sx * sin(ms->cam->angle_z)) + \
	(ms->coord->sy * cos(ms->cam->angle_z));
	ms->coord->ex = (ms->coord->ex * cos(ms->cam->angle_z)) + \
	(ms->coord->ey * sin(ms->cam->angle_z));
	ms->coord->ey = (ms->coord->ex * sin(ms->cam->angle_z)) + \
	(ms->coord->ey * cos(ms->cam->angle_z));
}
