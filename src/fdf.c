/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwenolaleroux <gwenolaleroux@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 08:15:28 by gwenolalero       #+#    #+#             */
/*   Updated: 2023/04/10 16:12:35 by gwenolalero      ###   ########.fr       */
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
		ft_draw_map_square(ms);
		mlx_loop(ms->mlx);
	}
	ft_clean_up(ms, 0);
	exit(EXIT_SUCCESS);
}
