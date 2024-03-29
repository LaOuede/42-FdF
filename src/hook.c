/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gle-roux <gle-roux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 12:46:56 by gle-roux          #+#    #+#             */
/*   Updated: 2023/04/26 09:54:47 by gle-roux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_colors_hook(t_fdf *ms, keys_t key)
{
	if (key == MLX_KEY_SPACE)
		ms->cam->colors = standard;
	else if (key == MLX_KEY_1)
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
	if (key == MLX_KEY_I || key == MLX_KEY_SPACE)
		ms->cam->projection = isometric;
	else if (key == MLX_KEY_T)
		ms->cam->projection = top_view;
	ft_draw(ms);
}

/*
Handles hooks :
	- Program closure;
	- Projection;
	- Color;
*/
void	ft_fdf_keys(mlx_key_data_t keydata, void *param)
{
	t_fdf	*ms;

	ms = (t_fdf *)param;
	if (mlx_is_key_down(ms->mlx, MLX_KEY_ESCAPE)
		|| mlx_is_key_down(ms->mlx, MLX_KEY_Q))
		ft_clean_up(ms, NULL);
	if (mlx_is_key_down(ms->mlx, MLX_KEY_I)
		|| mlx_is_key_down(ms->mlx, MLX_KEY_SPACE)
		|| mlx_is_key_down(ms->mlx, MLX_KEY_T))
		ft_projection_hook(ms, keydata.key);
	if (mlx_is_key_down(ms->mlx, MLX_KEY_1)
		|| mlx_is_key_down(ms->mlx, MLX_KEY_2)
		|| mlx_is_key_down(ms->mlx, MLX_KEY_3)
		|| mlx_is_key_down(ms->mlx, MLX_KEY_4)
		|| mlx_is_key_down(ms->mlx, MLX_KEY_SPACE))
		ft_colors_hook(ms, keydata.key);
}
