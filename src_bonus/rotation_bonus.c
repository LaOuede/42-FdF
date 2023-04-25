/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwenolaleroux <gwenolaleroux@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 10:50:41 by gle-roux          #+#    #+#             */
/*   Updated: 2023/04/25 18:06:27 by gwenolalero      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf_bonus.h"

/* This function appears to perform a rotation around the x-axis in 3D space.
Here's a breakdown of what each line does:

ms->coord->sy = (ms->coord->sy * cos(ms->cam->angle_x)) -
(ms->coord->sz * sin(ms->cam->angle_x)) / (ms->cam->z_offset * 3);
This line rotates the y-coordinate of the start point (sx, sy, sz) 
round the x-axis by an angle specified by ms->cam->angle_x.
The result is stored in ms->coord->sy.
The term (ms->coord->sz * sin(ms->cam->angle_x)) / (ms->cam->z_offset * 3)
is a correction factor that takes into account the distance of the camera
from the projection plane. */
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

void	ft_rotation(t_fdf *ms)
{
	ft_rotation_x(ms);
	ft_rotation_y(ms);
	ft_rotation_z(ms);
}
