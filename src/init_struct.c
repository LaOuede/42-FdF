/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwenolaleroux <gwenolaleroux@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 09:53:41 by gle-roux          #+#    #+#             */
/*   Updated: 2023/04/07 17:19:53 by gwenolalero      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

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

void	ft_init_matrix(t_fdf *ms)
{
	int	i;

	ms->map->matrix = ft_calloc(ms->map->height, sizeof (int *));
	if (!ms->map->matrix)
		exit(EXIT_FAILURE);
	i = -1;
	while (++i < ms->map->height)
	{
		ms->map->matrix[i] = ft_calloc(ms->map->width, sizeof (int));
		if (!ms->map->matrix[i])
		{
			ft_free_tab_int(ms->map->matrix, ms->map->height);
			exit(EXIT_FAILURE);
		}
	}
}

t_infos	*ft_init_infos(void)
{
	static t_infos	*map;

	if (!map)
	{
		map = malloc(sizeof(*map) * 1);
		if (!map)
			return (NULL);
		map->height = 0;
		map->width = 0;
		map->z_max = INT_MIN;
		map->z_min = INT_MAX;
		map->color = F;
		map->matrix = 0;
	}
	return (map);
}

t_fdf	*ft_init_ms(void)
{
	static t_fdf	*ms;

	if (!ms)
	{
		ms = ft_calloc(sizeof(*ms), 1);
		if (!ms)
			return (NULL);
		ms->map = ft_init_infos();
	}
	return (ms);
}
