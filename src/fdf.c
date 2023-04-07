/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gle-roux <gle-roux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 08:15:28 by gwenolalero       #+#    #+#             */
/*   Updated: 2023/04/07 10:21:24 by gle-roux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	main(int argc, char **argv)
{
	t_fdf	*ms;
	t_map	*infos;

	if (argc != 2)
		ft_clean_up(0, 0, "Usage : ./fdf <map.fdf>\n"
			KYEL"	-> An argument is needed <-\n"KNRM);
	ms = ft_init_ms();
	infos = ft_init_infos();
	ft_parse_file(ms, argv[1]);
	ft_read_map(ms, argv[1]);
	//ft_init_mlx(ms);
	ft_clean_up(ms, infos, 0);
	exit(EXIT_SUCCESS);
}
