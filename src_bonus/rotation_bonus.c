/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gle-roux <gle-roux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 10:50:41 by gle-roux          #+#    #+#             */
/*   Updated: 2023/04/20 13:40:06 by gle-roux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf_bonus.h"

void	ft_rotation_x(t_fdf *ms)
{
	ms->coord->sy = (ms->coord->sy * cos(ms->cam->theta_x)) - (ms->coord->sz * sin(ms->cam->theta_x));
	ms->coord->proj_sz = (ms->coord->sy * sin(ms->cam->theta_x)) + (ms->coord->sz * cos(ms->cam->theta_x));
	ms->coord->ey = (ms->coord->ey * cos(ms->cam->theta_x)) - (ms->coord->ez * sin(ms->cam->theta_x));
	ms->coord->proj_ez = (ms->coord->ey * sin(ms->cam->theta_x)) + (ms->coord->ez * cos(ms->cam->theta_x));
}

void	ft_rotation_y(t_fdf *ms)
{
	ms->coord->sx = (ms->coord->sx * cos(ms->cam->theta_y)) - (ms->coord->sz * sin(ms->cam->theta_y));
	ms->coord->proj_sz = (ms->coord->sx * sin(ms->cam->theta_y)) + (ms->coord->sz * cos(ms->cam->theta_y));
	ms->coord->ex = (ms->coord->ex * cos(ms->cam->theta_y)) - (ms->coord->ez * sin(ms->cam->theta_y));
	ms->coord->proj_ez = (ms->coord->ex * sin(ms->cam->theta_y)) + (ms->coord->ez * cos(ms->cam->theta_y));
}

void	ft_rotation_z(t_fdf *ms)
{
	ms->coord->sx = (ms->coord->sx * cos(ms->cam->theta_z)) - (ms->coord->sy * sin(ms->cam->theta_z));
	ms->coord->sy = (ms->coord->sx * sin(ms->cam->theta_z)) + (ms->coord->sy * cos(ms->cam->theta_z));
	ms->coord->ex = (ms->coord->ex * cos(ms->cam->theta_z)) - (ms->coord->ey * sin(ms->cam->theta_z));
	ms->coord->ey = (ms->coord->ex * sin(ms->cam->theta_z)) + (ms->coord->ey * cos(ms->cam->theta_z));
}

void	ft_rotation(t_fdf *ms)
{
	ft_rotation_x(ms);
	ft_rotation_y(ms);
	ft_rotation_z(ms);
}
