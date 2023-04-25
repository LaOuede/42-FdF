/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_scheme_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gle-roux <gle-roux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 11:01:56 by gle-roux          #+#    #+#             */
/*   Updated: 2023/04/25 15:32:13 by gle-roux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf_bonus.h"

/* In this context, "t" represents the position of the current pixel along the
line between the two endpoints, as a value between 0 and 1. When t = 0,
the color of the pixel will be equal to the color of the first endpoint
 (color1), and when t = 1, the color of the pixel will be equal to the color
 of the second endpoint (color2). For values of t between 0 and 1, the color
 of the pixel will be a linear interpolation between color1 and color2,
 with the weight of the two colors determined by the value of t. */
void	ft_standard(t_fdf *ms)
{
	double	p;

	p = ms->algo->pixel / ms->algo->delta_max;
	if ((int)ms->coord->sz == 0 && (int)ms->coord->ez == 0)
		mlx_put_pixel(ms->image, ms->coord->proj_sx, ms->coord->proj_sy,
			ft_get_rgba(0, 0, 0, 255));
	else if (((int)ms->coord->sz == 0 && (int)ms->coord->ez > 0) \
		|| ((int)ms->coord->sz == 0 && (int)ms->coord->ez < 0) \
		|| ((int)ms->coord->sz > 0 && (int)ms->coord->ez < 0))
		mlx_put_pixel(ms->image, ms->coord->proj_sx, ms->coord->proj_sy, \
		ft_get_rgba((int)((1 - p) * 0 + p * 255), \
		(int)((1 - p) * 0 + p * 255), (int)((1 - p) * 0 + p * 255), 255));
	else if (((int)ms->coord->sz > 0 && (int)ms->coord->ez == 0) || \
		((int)ms->coord->sz < 0 && (int)ms->coord->ez == 0) || \
		((int)ms->coord->sz < 0 && (int)ms->coord->ez > 0))
		mlx_put_pixel(ms->image, ms->coord->proj_sx, ms->coord->proj_sy, \
		ft_get_rgba((int)((1 - p) * 255 + p * 0), ((1 - p) * 255 + p * 0), \
		(int)((1 - p) * 255 + p * 0), 255));
	else if (((int)ms->coord->sz > 0 && (int)ms->coord->ez > 0) || \
		((int)ms->coord->sz < 0 && (int)ms->coord->ez < 0))
		mlx_put_pixel(ms->image, ms->coord->proj_sx, ms->coord->proj_sy,
			ft_get_rgba(255, 255, 255, 255));
}

void	ft_avernus(t_fdf *ms)
{
	double	p;

	p = ms->algo->pixel / ms->algo->delta_max;
	if ((int)ms->coord->sz == 0 && (int)ms->coord->ez == 0)
		mlx_put_pixel(ms->image, ms->coord->proj_sx, ms->coord->proj_sy,
			ft_get_rgba(230, 0, 0, 255));
	else if (((int)ms->coord->sz == 0 && (int)ms->coord->ez > 0) \
		|| ((int)ms->coord->sz == 0 && (int)ms->coord->ez < 0) \
		|| ((int)ms->coord->sz > 0 && (int)ms->coord->ez < 0))
		mlx_put_pixel(ms->image, ms->coord->proj_sx, ms->coord->proj_sy, \
		ft_get_rgba((int)((1 - p) * 230 + p * 230), \
		(int)((1 - p) * 0 + p * 230), (int)((1 - p) * 0 + p * 0), 255));
	else if (((int)ms->coord->sz > 0 && (int)ms->coord->ez == 0) || \
		((int)ms->coord->sz < 0 && (int)ms->coord->ez == 0) || \
		((int)ms->coord->sz < 0 && (int)ms->coord->ez > 0))
		mlx_put_pixel(ms->image, ms->coord->proj_sx, ms->coord->proj_sy, \
		ft_get_rgba((int)((1 - p) * 230 + p * 230), ((1 - p) * 230 + p * 0), \
		(int)((1 - p) * 0 + p * 0), 255));
	else if (((int)ms->coord->sz > 0 && (int)ms->coord->ez > 0) || \
		((int)ms->coord->sz < 0 && (int)ms->coord->ez < 0))
		mlx_put_pixel(ms->image, ms->coord->proj_sx, ms->coord->proj_sy,
			ft_get_rgba(230, 230, 0, 255));
}

void	ft_strahd(t_fdf *ms)
{
	double	p;

	p = ms->algo->pixel / ms->algo->delta_max;
	if ((int)ms->coord->sz == 0 && (int)ms->coord->ez == 0)
		mlx_put_pixel(ms->image, ms->coord->proj_sx, ms->coord->proj_sy,
			ft_get_rgba(0, 0, 255, 255));
	else if (((int)ms->coord->sz == 0 && (int)ms->coord->ez > 0) \
		|| ((int)ms->coord->sz == 0 && (int)ms->coord->ez < 0) \
		|| ((int)ms->coord->sz > 0 && (int)ms->coord->ez < 0))
		mlx_put_pixel(ms->image, ms->coord->proj_sx, ms->coord->proj_sy, \
		ft_get_rgba((int)((1 - p) * 0 + p * 255), (int)((1 - p) * 0 + p * 0), \
		(int)((1 - p) * 255 + p * 255), 255));
	else if (((int)ms->coord->sz > 0 && (int)ms->coord->ez == 0) || \
		((int)ms->coord->sz < 0 && (int)ms->coord->ez == 0) || \
		((int)ms->coord->sz < 0 && (int)ms->coord->ez > 0))
		mlx_put_pixel(ms->image, ms->coord->proj_sx, ms->coord->proj_sy, \
		ft_get_rgba((int)((1 - p) * 255 + p * 0), ((1 - p) * 0 + p * 0), \
		(int)((1 - p) * 255 + p * 255), 255));
	else if (((int)ms->coord->sz > 0 && (int)ms->coord->ez > 0) || \
		((int)ms->coord->sz < 0 && (int)ms->coord->ez < 0))
		mlx_put_pixel(ms->image, ms->coord->proj_sx, ms->coord->proj_sy,
			ft_get_rgba(255, 0, 255, 255));
}

void	ft_phandelver(t_fdf *ms)
{
	double	p;

	p = ms->algo->pixel / ms->algo->delta_max;
	if ((int)ms->coord->sz == 0 && (int)ms->coord->ez == 0)
		mlx_put_pixel(ms->image, ms->coord->proj_sx, ms->coord->proj_sy,
			ft_get_rgba(0, 0, 0, 255));
	else if (((int)ms->coord->sz == 0 && (int)ms->coord->ez > 0) \
		|| ((int)ms->coord->sz == 0 && (int)ms->coord->ez < 0) \
		|| ((int)ms->coord->sz > 0 && (int)ms->coord->ez < 0))
		mlx_put_pixel(ms->image, ms->coord->proj_sx, ms->coord->proj_sy, \
		ft_get_rgba((int)((1 - p) * 0 + p * 0), (int)((1 - p) * 0 + p * 255), \
		(int)((1 - p) * 0 + p * 0), 255));
	else if (((int)ms->coord->sz > 0 && (int)ms->coord->ez == 0) || \
		((int)ms->coord->sz < 0 && (int)ms->coord->ez == 0) || \
		((int)ms->coord->sz < 0 && (int)ms->coord->ez > 0))
		mlx_put_pixel(ms->image, ms->coord->proj_sx, ms->coord->proj_sy, \
		ft_get_rgba((int)((1 - p) * 0 + p * 0), ((1 - p) * 255 + p * 0), \
		(int)((1 - p) * 0 + p * 0), 255));
	else if (((int)ms->coord->sz > 0 && (int)ms->coord->ez > 0) || \
		((int)ms->coord->sz < 0 && (int)ms->coord->ez < 0))
		mlx_put_pixel(ms->image, ms->coord->proj_sx, ms->coord->proj_sy,
			ft_get_rgba(0, 255, 0, 255));
}

void	ft_icewindale(t_fdf *ms)
{
	double	p;

	p = ms->algo->pixel / ms->algo->delta_max;
	if ((int)ms->coord->sz == 0 && (int)ms->coord->ez == 0)
		mlx_put_pixel(ms->image, ms->coord->proj_sx, ms->coord->proj_sy,
			ft_get_rgba(0, 0, 255, 255));
	else if (((int)ms->coord->sz == 0 && (int)ms->coord->ez > 0) \
		|| ((int)ms->coord->sz == 0 && (int)ms->coord->ez < 0) \
		|| ((int)ms->coord->sz > 0 && (int)ms->coord->ez < 0))
		mlx_put_pixel(ms->image, ms->coord->proj_sx, ms->coord->proj_sy, \
		ft_get_rgba((int)((1 - p) * 0 + p * 102), (int)((1 - p) * 0 + p * 255), \
		(int)((1 - p) * 255 + p * 255), 255));
	else if (((int)ms->coord->sz > 0 && (int)ms->coord->ez == 0) || \
		((int)ms->coord->sz < 0 && (int)ms->coord->ez == 0) || \
		((int)ms->coord->sz < 0 && (int)ms->coord->ez > 0))
		mlx_put_pixel(ms->image, ms->coord->proj_sx, ms->coord->proj_sy, \
		ft_get_rgba((int)((1 - p) * 102 + p * 0), ((1 - p) * 255 + p * 0), \
		(int)((1 - p) * 255 + p * 255), 255));
	else if (((int)ms->coord->sz > 0 && (int)ms->coord->ez > 0) || \
		((int)ms->coord->sz < 0 && (int)ms->coord->ez < 0))
		mlx_put_pixel(ms->image, ms->coord->proj_sx, ms->coord->proj_sy,
			ft_get_rgba(102, 255, 255, 255));
}
