/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwenolaleroux <gwenolaleroux@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 09:53:41 by gle-roux          #+#    #+#             */
/*   Updated: 2023/04/06 17:27:51 by gwenolalero      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_init_mlx(t_fdf *ms)
{
	ms->mlx = mlx_init(WIDTH, HEIGHT, "FDF  ~gle-roux🐭~", false);
	ms->image = mlx_new_image(ms->mlx, WIDTH, HEIGHT);
	mlx_image_to_window(ms->mlx, ms->image, 77, 77);
	mlx_loop(ms->mlx);
	mlx_terminate(ms->mlx);
}

void	ft_init_matrix(t_fdf *ms)
{
	int	i;

	ms->infos.matrix = ft_calloc(ms->infos.height, sizeof (int *));
	if (!ms->infos.matrix)
		exit(EXIT_FAILURE);
	i = -1;
	while (++i < ms->infos.height)
	{
		ms->infos.matrix[i] = ft_calloc(ms->infos.width, sizeof (int));
		if (!ms->infos.matrix[i])
		{
			ft_free_tab_int(ms->infos.matrix, ms->infos.height);
			exit(EXIT_FAILURE);
		}
	}
}

t_map	*ft_init_infos(void)
{
	static t_map	*infos;

	if (!infos)
	{
		infos = ft_calloc(sizeof(*infos), 1);
		if (!infos)
			return (NULL);
		infos->height = 0;
		infos->width = 0;
		infos->z_max = 0;
		infos->z_min = 0;
		infos->color = F;
		infos->matrix = 0;
	}
	return (infos);
}

t_fdf	*ft_init_ms(void)
{
	static t_fdf	*ms;

	if (!ms)
	{
		ms = ft_calloc(sizeof(*ms), 1);
		if (!ms)
			return (NULL);
	}
	return (ms);
}

