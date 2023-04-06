/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gle-roux <gle-roux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 08:15:28 by gwenolalero       #+#    #+#             */
/*   Updated: 2023/04/06 11:40:48 by gle-roux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	main(int argc, char **argv)
{
	static t_fdf	*ms;
	static t_map	*infos;

	if (argc != 2)
		ft_error("Usage : ./fdf <map.fdf>\n"
			KYEL"	-> An argument is needed <-\n"KNRM);
	ms = ft_init_ms();
	infos = ft_init_infos();
	ft_parse_file(argv[1]);
	ft_read_map(ms, argv[1]);
	ft_init_mlx(ms);
	ft_free_tab_int(ms->infos.matrix, (size_t)ms->infos.height);
	free(infos);
	free(ms);
	return (0);
}
