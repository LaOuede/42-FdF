/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gle-roux <gle-roux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 10:54:19 by gle-roux          #+#    #+#             */
/*   Updated: 2023/04/13 11:28:55 by gle-roux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_isometric(t_fdf *ms)
{
	ms->iso->start_x = (ms->coord->start_x - ms->coord->start_y) * cos(0.523599);
	ms->iso->start_y = (ms->coord->start_x - ms->coord->start_y) * sin(0.523599) - ms->coord->start_z;
	ms->iso->end_x = (ms->coord->end_x - ms->coord->end_y) * cos(0.523599);
	ms->iso->end_y = (ms->coord->end_x - ms->coord->end_y) * sin(0.523599) - ms->coord->end_z;
}

/* x` = (x - y) * cos(angle)
**			y` = (x + y) * sin(angle) - z */