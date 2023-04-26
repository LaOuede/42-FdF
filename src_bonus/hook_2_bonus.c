/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_2_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwenolaleroux <gwenolaleroux@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 15:03:39 by gle-roux          #+#    #+#             */
/*   Updated: 2023/04/26 16:29:40 by gwenolalero      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf_bonus.h"

void	ft_reset_hook(t_fdf *ms, keys_t key)
{
	if (key == MLX_KEY_SPACE)
	{
		ms->cam->projection = isometric_view;
		ms->cam->colors = standard;
		ms->cam->x_offset = 1;
		ms->cam->y_offset = 1;
		ms->cam->z_offset = 0.5;
		ms->cam->angle_x = 0;
		ms->cam->angle_y = 0;
		ms->cam->angle_z = 0;
		ms->cam->zoom = 0;
		ms->cam->scale = 0;
	}
	ft_draw(ms);
}

void	ft_colors_hook(t_fdf *ms, keys_t key)
{
	if (key == MLX_KEY_1)
		ms->cam->colors = icewindale;
	else if (key == MLX_KEY_2)
		ms->cam->colors = phandelver;
	else if (key == MLX_KEY_3)
		ms->cam->colors = strahd;
	else if (key == MLX_KEY_4)
		ms->cam->colors = avernus;
	else if (key == MLX_KEY_R)
		ms->cam->colors = rainbow;
	ft_draw(ms);
}

void	ft_rotation_hook(t_fdf *ms, keys_t key)
{
	if (key == MLX_KEY_Z)
		ms->cam->angle_x += 0.1;
	else if (key == MLX_KEY_X)
		ms->cam->angle_x -= 0.1;
	else if (key == MLX_KEY_C)
		ms->cam->angle_y += 0.1;
	else if (key == MLX_KEY_V)
		ms->cam->angle_y -= 0.1;
	else if (key == MLX_KEY_B)
		ms->cam->angle_z += 0.1;
	else if (key == MLX_KEY_N)
		ms->cam->angle_z -= 0.1;
	ft_draw(ms);
}

void	ft_zoom_hook(t_fdf *ms, keys_t key)
{
	if (key == MLX_KEY_MINUS)
		ms->cam->zoom -= 1;
	else if (key == MLX_KEY_EQUAL)
		ms->cam->zoom += 1;
	ft_draw(ms);
}

/*
Handles hooks :
	- Zoom;
	- Rotation;
	- Color;
	- Reset;
*/
void	ft_keys_2(mlx_key_data_t keydata, void *param)
{
	t_fdf	*ms;

	ms = (t_fdf *)param;
	if (mlx_is_key_down(ms->mlx, MLX_KEY_MINUS)
		|| mlx_is_key_down(ms->mlx, MLX_KEY_EQUAL))
		ft_zoom_hook(ms, keydata.key);
	if (mlx_is_key_down(ms->mlx, MLX_KEY_Z)
		|| mlx_is_key_down(ms->mlx, MLX_KEY_X)
		|| mlx_is_key_down(ms->mlx, MLX_KEY_C)
		|| mlx_is_key_down(ms->mlx, MLX_KEY_V)
		|| mlx_is_key_down(ms->mlx, MLX_KEY_B)
		|| mlx_is_key_down(ms->mlx, MLX_KEY_N))
		ft_rotation_hook(ms, keydata.key);
	if (mlx_is_key_down(ms->mlx, MLX_KEY_1)
		|| mlx_is_key_down(ms->mlx, MLX_KEY_2)
		|| mlx_is_key_down(ms->mlx, MLX_KEY_3)
		|| mlx_is_key_down(ms->mlx, MLX_KEY_4)
		|| mlx_is_key_down(ms->mlx, MLX_KEY_R))
		ft_colors_hook(ms, keydata.key);
	if (mlx_is_key_down(ms->mlx, MLX_KEY_SPACE))
		ft_reset_hook(ms, keydata.key);
}
