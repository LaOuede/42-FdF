/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gle-roux <gle-roux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 12:46:56 by gle-roux          #+#    #+#             */
/*   Updated: 2023/04/13 16:53:39 by gle-roux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_translation(t_fdf *ms, keys_t key)
{
	//ft_map_erase(ms);
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
	if (mlx_is_key_down(ms->mlx, MLX_KEY_RIGHT)
		|| mlx_is_key_down(ms->mlx, MLX_KEY_LEFT)
		|| mlx_is_key_down(ms->mlx, MLX_KEY_UP)
		|| mlx_is_key_down(ms->mlx, MLX_KEY_DOWN))
		ft_translation(ms, keydata.key);
}
