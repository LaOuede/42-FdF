/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwenolaleroux <gwenolaleroux@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 15:23:23 by gwenolalero       #+#    #+#             */
/*   Updated: 2023/04/26 16:28:55 by gwenolalero      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf_bonus.h"

void	ft_secret_color_pos(t_fdf *ms, double z_factor)
{
	if (z_factor < 0.125)
		mlx_put_pixel(ms->image, ms->coord->proj_sx, ms->coord->proj_sy,
			ft_get_rgba(145, 225, 64, 255));
	else if (z_factor < 0.250)
		mlx_put_pixel(ms->image, ms->coord->proj_sx, ms->coord->proj_sy,
			ft_get_rgba(160, 195, 0, 255));
	else if (z_factor < 0.375)
		mlx_put_pixel(ms->image, ms->coord->proj_sx, ms->coord->proj_sy,
			ft_get_rgba(175, 165, 0, 255));
	else if (z_factor < 0.50)
		mlx_put_pixel(ms->image, ms->coord->proj_sx, ms->coord->proj_sy,
			ft_get_rgba(190, 135, 0, 255));
	else if (z_factor < 0.625)
		mlx_put_pixel(ms->image, ms->coord->proj_sx, ms->coord->proj_sy,
			ft_get_rgba(205, 105, 0, 255));
	else if (z_factor < 0.750)
		mlx_put_pixel(ms->image, ms->coord->proj_sx, ms->coord->proj_sy,
			ft_get_rgba(205, 75, 0, 255));
	else if (z_factor < 0.875)
		mlx_put_pixel(ms->image, ms->coord->proj_sx, ms->coord->proj_sy,
			ft_get_rgba(235, 45, 0, 255));
	else if (z_factor >= 0.875)
		mlx_put_pixel(ms->image, ms->coord->proj_sx, ms->coord->proj_sy,
			ft_get_rgba(255, 0, 0, 255));
}

void	ft_secret_color_neg(t_fdf *ms, double z_factor)
{
	if (z_factor > -0.125)
		mlx_put_pixel(ms->image, ms->coord->proj_sx, ms->coord->proj_sy,
			ft_get_rgba(64, 225, 145, 255));
	else if (z_factor > -0.250)
		mlx_put_pixel(ms->image, ms->coord->proj_sx, ms->coord->proj_sy,
			ft_get_rgba(0, 195, 160, 255));
	else if (z_factor > -0.375)
		mlx_put_pixel(ms->image, ms->coord->proj_sx, ms->coord->proj_sy,
			ft_get_rgba(0, 165, 175, 255));
	else if (z_factor > -0.500)
		mlx_put_pixel(ms->image, ms->coord->proj_sx, ms->coord->proj_sy,
			ft_get_rgba(0, 135, 190, 255));
	else if (z_factor > -0.625)
		mlx_put_pixel(ms->image, ms->coord->proj_sx, ms->coord->proj_sy,
			ft_get_rgba(0, 105, 205, 255));
	else if (z_factor > -0.750)
		mlx_put_pixel(ms->image, ms->coord->proj_sx, ms->coord->proj_sy,
			ft_get_rgba(0, 75, 205, 255));
	else if (z_factor > -0.875)
		mlx_put_pixel(ms->image, ms->coord->proj_sx, ms->coord->proj_sy,
			ft_get_rgba(0, 45, 235, 255));
	else if (z_factor <= -0.875)
		mlx_put_pixel(ms->image, ms->coord->proj_sx, ms->coord->proj_sy,
			ft_get_rgba(0, 0, 255, 255));
}

void	ft_z_max(t_fdf *ms)
{
	int	x;
	int	y;

	x = -1;
	while (++x < ms->width)
	{
		y = -1;
		while (++y < ms->height)
		{
			if (ms->matrix[y][x] > ms->z_max)
				ms->z_max = ms->matrix[y][x];
		}
	}
}

void	ft_secret_colors(t_fdf *ms)
{
	double	z_factor;

	z_factor = ((ms->coord->sz + ms->coord->ez) / 2) / ms->z_max;
	if (z_factor > 0)
		ft_secret_color_pos(ms, z_factor);
	else if (z_factor < 0)
		ft_secret_color_neg(ms, z_factor);
	else if (z_factor == 0)
		mlx_put_pixel(ms->image, ms->coord->proj_sx, ms->coord->proj_sy,
			ft_get_rgba(164, 255, 164, 255));
}
