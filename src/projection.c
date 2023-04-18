/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gle-roux <gle-roux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 10:54:19 by gle-roux          #+#    #+#             */
/*   Updated: 2023/04/18 10:55:26 by gle-roux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_isometric(t_fdf *ms)
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

void	ft_projection_hook(t_fdf *ms, keys_t key)
{
	if (key == MLX_KEY_I)
		ms->cam->projection = isometric;
	else if (key == MLX_KEY_T)
		ms->cam->projection = top_view;
	ft_draw(ms);
}

void	ft_projection(t_fdf *ms)
{
	if (ms->cam->projection == isometric)
		ft_isometric(ms);
	else if (ms->cam->projection == top_view)
		ft_top_view(ms);
}
