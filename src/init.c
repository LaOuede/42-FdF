/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwenolaleroux <gwenolaleroux@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 09:53:41 by gle-roux          #+#    #+#             */
/*   Updated: 2023/04/08 11:51:15 by gwenolalero      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

/* Initialize and set the graphic library and the window */
bool	ft_init_mlx(t_fdf *ms)
{
	ms->mlx = mlx_init(WIDTH, HEIGHT, "FDF  ~gle-roux🐭~", false);
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
	}
	return (map);
}

/* Initialize the meta structure (if it doesn't exist) and returns it. */
t_fdf	*ft_init_ms(void)
{
	static t_fdf	*ms;

	if (!ms)
	{
		ms = ft_calloc(sizeof(t_fdf), 1);
		ms->map = ft_init_infos();
	}
	return (ms);
}
