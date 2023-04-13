/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gle-roux <gle-roux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 08:15:28 by gwenolalero       #+#    #+#             */
/*   Updated: 2023/04/13 16:52:57 by gle-roux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	main(int argc, char **argv)
{
	t_fdf	*ms;

	if (argc != 2)
		ft_clean_up(0, "Usage : ./fdf <map.fdf>\n"
			KYEL"	-> An argument is needed <-\n"KNRM);
	ms = ft_init_ms();
	ft_parse_file(ms, argv[1]);
	ft_read_map(ms, argv[1]);
	if (ft_init_mlx(ms, argv[1]) == T)
	{
		//ft_draw_cross(ms);
		//ft_find_scale(ms);
		mlx_key_hook(ms->mlx, &ft_fdf_keys, ms);
		ft_map_scale(ms);
		ft_get_starting_points(ms);
		ft_print_infos(ms);
		ft_draw(ms);
		mlx_loop(ms->mlx);
	}
	ft_clean_up(ms, 0);
	exit(EXIT_SUCCESS);
}
