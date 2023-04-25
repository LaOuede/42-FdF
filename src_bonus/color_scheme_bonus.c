/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_scheme_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwenolaleroux <gwenolaleroux@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 11:01:56 by gle-roux          #+#    #+#             */
/*   Updated: 2023/04/25 17:58:33 by gwenolalero      ###   ########.fr       */
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

/* When (1 - p) * 0 + p * 255 is used to set the color 
 component value of a pixel, it is taking into account two factors:
 p and (1 - p).

p is a value between 0 and 1 that is calculated based on the position of the
pixel and other factors. p is a measure of the distance between neighboring
points in a 3D model, where a larger value of p means a larger difference
in height between two neighboring points.

(1 - p) is just the opposite of p. So when p is close to 0, (1 - p) is close
to 1, and when p is close to 1, (1 - p) is close to 0.

By using both p and (1 - p) in the color calculation, we create a smooth
transition in the color component value based on the distance from
the maximum value of p.

This smooth transition helps to visualize the height and depth of the 3D
model in a more intuitive way. If we used only p to set the color component 
alue, we would not be taking into account the distance from the maximum
value of p. The result would be a less intuitive representation
of the 3D model. */
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
