/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modifications_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gle-roux <gle-roux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 12:24:53 by gle-roux          #+#    #+#             */
/*   Updated: 2023/04/19 13:41:30 by gle-roux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf_bonus.h"

void	ft_altitude(t_fdf *ms)
{
	if (ms->coord->sz != 0)
	{
		ms->coord->sz += ms->cam->z_offset;
		ms->coord->ez += ms->cam->z_offset;
	}
}

void	ft_translation(t_fdf *ms)
{
	ms->coord->proj_sx += ms->cam->x_offset;
	ms->coord->proj_sy += ms->cam->y_offset;
	ms->coord->proj_ex += ms->cam->x_offset;
	ms->coord->proj_ey += ms->cam->y_offset;
}
