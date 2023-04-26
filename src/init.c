/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gle-roux <gle-roux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 09:53:41 by gle-roux          #+#    #+#             */
/*   Updated: 2023/04/26 10:24:40 by gle-roux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_init_line_x(t_fdf *ms)
{
	ms->coord->sx = ms->x;
	ms->coord->sy = ms->y;
	ms->coord->sz = ms->matrix[ms->y][ms->x];
	ms->coord->ex = ms->x + 1;
	ms->coord->ey = ms->y;
	ms->coord->ez = ms->matrix[ms->y][ms->x + 1];
}

void	ft_init_line_y(t_fdf *ms)
{
	ms->coord->sx = ms->x;
	ms->coord->sy = ms->y;
	ms->coord->sz = ms->matrix[ms->y][ms->x];
	ms->coord->ex = ms->x;
	ms->coord->ey = ms->y + 1;
	ms->coord->ez = ms->matrix[ms->y + 1][ms->x];
}

t_dda	*ft_init_dda(void)
{
	static t_dda	*algo;

	if (!algo)
	{
		algo = ft_calloc(sizeof(t_dda), 1);
		algo->x = 0;
		algo->y = 0;
		algo->delta_x = 0;
		algo->delta_y = 0;
		algo->ptp = 0;
		algo->delta_max = 0;
		algo->pixel = 0;
	}
	return (algo);
}

t_camera	*ft_init_camera(void)
{
	static t_camera	*cam;

	if (!cam)
	{
		cam = ft_calloc(sizeof(t_camera), 1);
		cam->colors = standard;
		cam->projection = isometric;
		cam->x_offset = 0;
		cam->y_offset = 0;
		cam->scale = 0;
	}
	return (cam);
}

/*
Initializes the meta structure (if it doesn't exist) and returns it.
Triggers camera and algo initializations.
*/
t_fdf	*ft_init_ms(void)
{
	static t_fdf	*ms;

	if (!ms)
	{
		ms = ft_calloc(sizeof(t_fdf), 1);
		ms->x = 0;
		ms->y = 0;
		ms->height = 0;
		ms->width = 0;
		ms->matrix = 0;
		ms->cam = ft_init_camera();
		ms->algo = ft_init_dda();
		ms->coord = ft_calloc(sizeof(t_line), 1);
		ms->menu = ft_calloc(sizeof(t_menu), 1);
	}
	return (ms);
}
