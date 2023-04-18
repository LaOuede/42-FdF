/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gle-roux <gle-roux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 12:46:56 by gle-roux          #+#    #+#             */
/*   Updated: 2023/04/18 15:45:20 by gle-roux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

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

void	ft_projection_hook(t_fdf *ms, keys_t key)
{
	if (key == MLX_KEY_I)
		ms->cam->projection = isometric;
	else if (key == MLX_KEY_T)
		ms->cam->projection = top_view;
	ft_draw(ms);
}

void	ft_translation(t_fdf *ms, keys_t key)
{
	if (key == MLX_KEY_RIGHT)
		ms->cam->x_offset += 25;
	else if (key == MLX_KEY_LEFT)
		ms->cam->x_offset -= 25;
	else if (key == MLX_KEY_UP)
		ms->cam->y_offset -= 25;
	else if (key == MLX_KEY_DOWN)
		ms->cam->y_offset += 25;
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
		|| mlx_is_key_down(ms->mlx, MLX_KEY_T))
		ft_projection_hook(ms, keydata.key);
	if (mlx_is_key_down(ms->mlx, MLX_KEY_RIGHT)
		|| mlx_is_key_down(ms->mlx, MLX_KEY_LEFT)
		|| mlx_is_key_down(ms->mlx, MLX_KEY_UP)
		|| mlx_is_key_down(ms->mlx, MLX_KEY_DOWN))
		ft_translation(ms, keydata.key);
	if (mlx_is_key_down(ms->mlx, MLX_KEY_1)
		|| mlx_is_key_down(ms->mlx, MLX_KEY_2)
		|| mlx_is_key_down(ms->mlx, MLX_KEY_3)
		|| mlx_is_key_down(ms->mlx, MLX_KEY_4))
		ft_colors_hook(ms, keydata.key);
}
