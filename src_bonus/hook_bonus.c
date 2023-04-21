/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwenolaleroux <gwenolaleroux@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 12:46:56 by gle-roux          #+#    #+#             */
/*   Updated: 2023/04/21 11:48:05 by gwenolalero      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf_bonus.h"

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

void	ft_z_hook(t_fdf *ms, keys_t key)
{
	if (key == MLX_KEY_UP)
		ms->cam->z_offset += 0.2;
	else if (key == MLX_KEY_DOWN)
		ms->cam->z_offset -= 0.2;
	ft_draw(ms);
}

void	ft_translation_hook(t_fdf *ms, keys_t key)
{
	if (key == MLX_KEY_D)
		ms->cam->x_offset += 25;
	else if (key == MLX_KEY_A)
		ms->cam->x_offset -= 25;
	else if (key == MLX_KEY_W)
		ms->cam->y_offset -= 25;
	else if (key == MLX_KEY_S)
		ms->cam->y_offset += 25;
	ft_draw(ms);
}

void	ft_projection_hook(t_fdf *ms, keys_t key)
{
	if (key == MLX_KEY_I)
		ms->cam->projection = isometric;
	else if (key == MLX_KEY_T)
		ms->cam->projection = top_view;
	else if (key == MLX_KEY_P)
		ms->cam->projection = dontknow;
	else if (key == MLX_KEY_O)
		ms->cam->projection = side_view;
	ft_draw(ms);
}

void	ft_fdf_keys(mlx_key_data_t keydata, void *param)
{
	t_fdf	*ms;

	ms = (t_fdf *)param;
	if (mlx_is_key_down(ms->mlx, MLX_KEY_ESCAPE)
		|| mlx_is_key_down(ms->mlx, MLX_KEY_Q))
	{
		ft_clean_up(ms, 0);
		exit(EXIT_SUCCESS);
	}
	if (mlx_is_key_down(ms->mlx, MLX_KEY_I)
		|| mlx_is_key_down(ms->mlx, MLX_KEY_T)
		|| mlx_is_key_down(ms->mlx, MLX_KEY_P)
		|| mlx_is_key_down(ms->mlx, MLX_KEY_O))
		ft_projection_hook(ms, keydata.key);
	if (mlx_is_key_down(ms->mlx, MLX_KEY_D)
		|| mlx_is_key_down(ms->mlx, MLX_KEY_A)
		|| mlx_is_key_down(ms->mlx, MLX_KEY_W)
		|| mlx_is_key_down(ms->mlx, MLX_KEY_S))
		ft_translation_hook(ms, keydata.key);
	if (mlx_is_key_down(ms->mlx, MLX_KEY_UP)
		|| mlx_is_key_down(ms->mlx, MLX_KEY_DOWN))
		ft_z_hook(ms, keydata.key);
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
		|| mlx_is_key_down(ms->mlx, MLX_KEY_4))
		ft_colors_hook(ms, keydata.key);
}
