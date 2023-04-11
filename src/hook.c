/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gle-roux <gle-roux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 12:46:56 by gle-roux          #+#    #+#             */
/*   Updated: 2023/04/11 15:24:59 by gle-roux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_translation(t_fdf *ms, keys_t key)
{
	ft_draw_map_erase(ms);
	if (key == MLX_KEY_RIGHT)
		ms->map->test += 10;
	if (key == MLX_KEY_LEFT)
		ms->map->test -= 10;
	ft_draw_map_square(ms);
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
		|| mlx_is_key_down(ms->mlx, MLX_KEY_LEFT))
		ft_translation(ms, keydata.key);
}
