/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gle-roux <gle-roux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 09:53:41 by gle-roux          #+#    #+#             */
/*   Updated: 2023/04/13 11:30:20 by gle-roux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

/* Initialize and set the graphic library and the window */
bool	ft_init_mlx(t_fdf *ms, char *file)
{
	ms->mlx = mlx_init(WIDTH, HEIGHT, file, false);
	ms->image = mlx_new_image(ms->mlx, WIDTH, HEIGHT);
	mlx_image_to_window(ms->mlx, ms->image, 0, 0);
	if (!ms->mlx || !ms->image
		|| (mlx_image_to_window(ms->mlx, ms->image, WIDTH, HEIGHT) == 0))
		ft_clean_up(ms, KRED"MLX initialization failed\n"KNRM);
	return (T);
}

/* Initialize the two-dimensioonnal array. */
void	ft_init_matrix(t_fdf *ms)
{
	int	i;

	ms->map->matrix = ft_calloc(ms->map->height, sizeof(int *));
	if (!ms->map->matrix)
		exit(EXIT_FAILURE);
	i = -1;
	while (++i < ms->map->height)
	{
		ms->map->matrix[i] = ft_calloc(ms->map->width, sizeof(int));
		if (!ms->map->matrix[i])
		{
			ft_free_tab_int(ms->map->matrix, ms->map->height);
			exit(EXIT_FAILURE);
		}
	}
}

/* Initialize the structure containing the informations from the <.fdf> file. */
t_infos	*ft_init_infos(void)
{
	static t_infos	*map;

	if (!map)
	{
		map = ft_calloc(sizeof(t_infos), 1);
		map->height = 0;
		map->width = 0;
		map->z_max = INT_MIN;
		map->z_min = INT_MAX;
		map->color = F;
		map->matrix = 0;
		map->x_start = 0;
		map->y_start = 0;
	}
	return (map);
}

t_camera	*ft_init_camera(void)
{
	static t_camera	*cam;

	if (!cam)
	{
		cam = ft_calloc(sizeof(t_camera), 1);
		cam->x_offset = 0;
		cam->y_offset = 0;
		cam->scale = 0;
	}
	return (cam);
}

t_bresenham	*ft_init_bresenham(void)
{
	static t_bresenham	*algo;

	if (!algo)
	{
		algo = ft_calloc(sizeof(t_bresenham), 1);
		algo->x = 0;
		algo->y = 0;
		algo->delta_x = 0;
		algo->delta_y = 0;
		algo->ptp = 0;
		algo->delta_max = 0;
	}
	return (algo);
}

t_line	*ft_init_line(void)
{
	static t_line	*coord;

	if (!coord)
	{
		coord = ft_calloc(sizeof(t_line), 1);
		coord->start_x = 0;
		coord->start_y = 0;
		coord->start_z = 0;
		coord->end_x = 0;
		coord->end_y = 0;
		coord->end_z = 0;
	}
	return (coord);
}

t_iso	*ft_init_iso(void)
{
	static t_iso	*iso;

	if (!iso)
	{
		iso = ft_calloc(sizeof(t_iso), 1);
		iso->start_x = 0;
		iso->start_y = 0;
		iso->start_z = 0;
		iso->end_x = 0;
		iso->end_y = 0;
		iso->end_z = 0;
	}
	return (iso);
}

/* Initialize the meta structure (if it doesn't exist) and returns it. */
t_fdf	*ft_init_ms(void)
{
	static t_fdf	*ms;

	if (!ms)
	{
		ms = ft_calloc(sizeof(t_fdf), 1);
		ms->map = ft_init_infos();
		ms->cam = ft_init_camera();
		ms->algo = ft_init_bresenham();
		ms->coord = ft_init_line();
		ms->iso = ft_init_iso();
	}
	return (ms);
}
