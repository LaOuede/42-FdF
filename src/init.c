/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gle-roux <gle-roux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 09:53:41 by gle-roux          #+#    #+#             */
/*   Updated: 2023/04/18 11:01:05 by gle-roux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

/* Initialize the structure containing the informations from the <.fdf> file. */
t_line	*ft_init_line(void)
{
	static t_line	*coord;

	if (!coord)
	{
		coord = ft_calloc(sizeof(t_line), 1);
		coord->sx = 0;
		coord->sy = 0;
		coord->sz = 0;
		coord->ex = 0;
		coord->ey = 0;
		coord->ez = 0;
		coord->proj_sx = 0;
		coord->proj_sy = 0;
		coord->proj_sz = 0;
		coord->proj_ex = 0;
		coord->proj_ey = 0;
		coord->proj_ez = 0;
	}
	return (coord);
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
	}
	return (algo);
}

t_camera	*ft_init_camera(void)
{
	static t_camera	*cam;

	if (!cam)
	{
		cam = ft_calloc(sizeof(t_camera), 1);
		cam->colors = icewindale;
		cam->projection = isometric;
		cam->x_offset = 0;
		cam->y_offset = 0;
		cam->scale = 0;
	}
	return (cam);
}

/* Initialize the meta structure (if it doesn't exist) and returns it. */
t_fdf	*ft_init_ms(void)
{
	static t_fdf	*ms;

	if (!ms)
	{
		ms = ft_calloc(sizeof(t_fdf), 1);
		ms->height = 0;
		ms->width = 0;
		ms->z_max = INT_MIN;
		ms->z_min = INT_MAX;
		ms->color = F;
		ms->matrix = 0;
		ms->x_start = 0;
		ms->y_start = 0;
		ms->cam = ft_init_camera();
		ms->algo = ft_init_dda();
		ms->coord = ft_init_line();
		ms->menu = ft_calloc(sizeof(t_menu), 1);
	}
	return (ms);
}
