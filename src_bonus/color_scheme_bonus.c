/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_scheme_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gle-roux <gle-roux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 11:01:56 by gle-roux          #+#    #+#             */
/*   Updated: 2023/04/19 11:56:05 by gle-roux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf_bonus.h"

int	ft_get_rgba(int r, int g, int b, int a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

void	ft_avernus(t_fdf *ms)
{
	if ((int)ms->coord->sz < 0 && (int)ms->coord->ez < 0)
		mlx_put_pixel(ms->image, ms->coord->proj_sx, ms->coord->proj_sy,
			ft_get_rgba(77, 0, 0, 255));
	else if (((int)ms->coord->sz == 0 && (int)ms->coord->ez < 0)
		|| ((int)ms->coord->sz < 0 && (int)ms->coord->ez == 0)
		|| ((int)ms->coord->sz > 0 && (int)ms->coord->ez < 0)
		|| ((int)ms->coord->sz < 0 && (int)ms->coord->ez > 0))
		mlx_put_pixel(ms->image, ms->coord->proj_sx, ms->coord->proj_sy,
			ft_get_rgba(153, 0, 0, 255));
	else if ((int)ms->coord->sz == 0 && (int)ms->coord->ez == 0)
		mlx_put_pixel(ms->image, ms->coord->proj_sx, ms->coord->proj_sy,
			ft_get_rgba(230, 0, 0, 255));
	else if (((int)ms->coord->sz == 0 && (int)ms->coord->ez > 0)
		|| ((int)ms->coord->sz > 0 && (int)ms->coord->ez == 0))
		mlx_put_pixel(ms->image, ms->coord->proj_sx, ms->coord->proj_sy,
			ft_get_rgba(255, 153, 0, 255));
	if ((int)ms->coord->sz > 0 && (int)ms->coord->ez > 0)
		mlx_put_pixel(ms->image, ms->coord->proj_sx, ms->coord->proj_sy,
			ft_get_rgba(255, 255, 0, 255));
}

void	ft_strahd(t_fdf *ms)
{
	if ((int)ms->coord->sz < 0 && (int)ms->coord->ez < 0)
		mlx_put_pixel(ms->image, ms->coord->proj_sx, ms->coord->proj_sy,
			ft_get_rgba(102, 0, 102, 255));
	else if (((int)ms->coord->sz == 0 && (int)ms->coord->ez < 0)
		|| ((int)ms->coord->sz < 0 && (int)ms->coord->ez == 0)
		|| ((int)ms->coord->sz > 0 && (int)ms->coord->ez < 0)
		|| ((int)ms->coord->sz < 0 && (int)ms->coord->ez > 0))
		mlx_put_pixel(ms->image, ms->coord->proj_sx, ms->coord->proj_sy,
			ft_get_rgba(153, 0, 153, 255));
	else if ((int)ms->coord->sz == 0 && (int)ms->coord->ez == 0)
		mlx_put_pixel(ms->image, ms->coord->proj_sx, ms->coord->proj_sy,
			ft_get_rgba(204, 0, 255, 255));
	else if (((int)ms->coord->sz == 0 && (int)ms->coord->ez > 0)
		|| ((int)ms->coord->sz > 0 && (int)ms->coord->ez == 0))
		mlx_put_pixel(ms->image, ms->coord->proj_sx, ms->coord->proj_sy,
			ft_get_rgba(153, 0, 255, 255));
	if ((int)ms->coord->sz > 0 && (int)ms->coord->ez > 0)
		mlx_put_pixel(ms->image, ms->coord->proj_sx, ms->coord->proj_sy,
			ft_get_rgba(0, 0, 255, 255));
}

void	ft_phandelver(t_fdf *ms)
{
	if ((int)ms->coord->sz < 0 && (int)ms->coord->ez < 0)
		mlx_put_pixel(ms->image, ms->coord->proj_sx, ms->coord->proj_sy,
			ft_get_rgba(102, 34, 0, 255));
	else if (((int)ms->coord->sz == 0 && (int)ms->coord->ez < 0)
		|| ((int)ms->coord->sz < 0 && (int)ms->coord->ez == 0)
		|| ((int)ms->coord->sz > 0 && (int)ms->coord->ez < 0)
		|| ((int)ms->coord->sz < 0 && (int)ms->coord->ez > 0))
		mlx_put_pixel(ms->image, ms->coord->proj_sx, ms->coord->proj_sy,
			ft_get_rgba(153, 51, 0, 255));
	else if ((int)ms->coord->sz == 0 && (int)ms->coord->ez == 0)
		mlx_put_pixel(ms->image, ms->coord->proj_sx, ms->coord->proj_sy,
			ft_get_rgba(153, 102, 0, 255));
	else if (((int)ms->coord->sz == 0 && (int)ms->coord->ez > 0)
		|| ((int)ms->coord->sz > 0 && (int)ms->coord->ez == 0))
		mlx_put_pixel(ms->image, ms->coord->proj_sx, ms->coord->proj_sy,
			ft_get_rgba(38, 115, 38, 255));
	if ((int)ms->coord->sz > 0 && (int)ms->coord->ez > 0)
		mlx_put_pixel(ms->image, ms->coord->proj_sx, ms->coord->proj_sy,
			ft_get_rgba(0, 255, 0, 255));
}

void	ft_icewindale(t_fdf *ms)
{
	if ((int)ms->coord->sz < 0 && (int)ms->coord->ez < 0)
		mlx_put_pixel(ms->image, ms->coord->proj_sx, ms->coord->proj_sy,
			ft_get_rgba(0, 0, 128, 255));
	else if (((int)ms->coord->sz == 0 && (int)ms->coord->ez < 0)
		|| ((int)ms->coord->sz < 0 && (int)ms->coord->ez == 0)
		|| ((int)ms->coord->sz > 0 && (int)ms->coord->ez < 0)
		|| ((int)ms->coord->sz < 0 && (int)ms->coord->ez > 0))
		mlx_put_pixel(ms->image, ms->coord->proj_sx, ms->coord->proj_sy,
			ft_get_rgba(51, 51, 255, 255));
	else if ((int)ms->coord->sz == 0 && (int)ms->coord->ez == 0)
		mlx_put_pixel(ms->image, ms->coord->proj_sx, ms->coord->proj_sy,
			ft_get_rgba(0, 0, 0, 255));
	else if (((int)ms->coord->sz == 0 && (int)ms->coord->ez > 0)
		|| ((int)ms->coord->sz > 0 && (int)ms->coord->ez == 0))
		mlx_put_pixel(ms->image, ms->coord->proj_sx, ms->coord->proj_sy,
			ft_get_rgba(0, 138, 230, 255));
	if ((int)ms->coord->sz > 0 && (int)ms->coord->ez > 0)
		mlx_put_pixel(ms->image, ms->coord->proj_sx, ms->coord->proj_sy,
			ft_get_rgba(51, 204, 204, 255));
}
