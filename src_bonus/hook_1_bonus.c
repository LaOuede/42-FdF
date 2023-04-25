/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_1_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gle-roux <gle-roux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 12:46:56 by gle-roux          #+#    #+#             */
/*   Updated: 2023/04/25 15:14:40 by gle-roux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf_bonus.h"

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
	if (key == MLX_KEY_I || key == MLX_KEY_SPACE)
		ms->cam->projection = isometric_view;
	else if (key == MLX_KEY_T)
		ms->cam->projection = top_view;
	else if (key == MLX_KEY_Y)
		ms->cam->projection = oblique_view;
	else if (key == MLX_KEY_U)
		ms->cam->projection = height_side_view;
	else if (key == MLX_KEY_O)
		ms->cam->projection = width_side_view;
	ft_draw(ms);
}

void	ft_keys_1(mlx_key_data_t keydata, void *param)
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
		|| mlx_is_key_down(ms->mlx, MLX_KEY_Y)
		|| mlx_is_key_down(ms->mlx, MLX_KEY_U)
		|| mlx_is_key_down(ms->mlx, MLX_KEY_O)
		|| mlx_is_key_down(ms->mlx, MLX_KEY_P))
		ft_projection_hook(ms, keydata.key);
	if (mlx_is_key_down(ms->mlx, MLX_KEY_D)
		|| mlx_is_key_down(ms->mlx, MLX_KEY_A)
		|| mlx_is_key_down(ms->mlx, MLX_KEY_W)
		|| mlx_is_key_down(ms->mlx, MLX_KEY_S))
		ft_translation_hook(ms, keydata.key);
	if (mlx_is_key_down(ms->mlx, MLX_KEY_UP)
		|| mlx_is_key_down(ms->mlx, MLX_KEY_DOWN))
		ft_z_hook(ms, keydata.key);
}

void	ft_fdf_keys(mlx_key_data_t keydata, void *param)
{
	t_fdf	*ms;

	ms = (t_fdf *)param;
	ft_keys_1(keydata, param);
	ft_keys_2(keydata, param);
}
