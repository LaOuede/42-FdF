/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gle-roux <gle-roux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 08:15:28 by gwenolalero       #+#    #+#             */
/*   Updated: 2023/04/04 15:41:55 by gle-roux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_init_ms(t_fdf *ms)
{
	ms->infos.height = 0;
	ms->infos.width = 0;
	ms->infos.z_max = 0;
	ms->infos.z_min = 0;
	ms->infos.color = F;
}

int	main(int argc, char **argv)
{
	static t_fdf	ms;

	if (argc != 2)
		ft_error_parse("Usage : ./fdf <map.fdf>\n"
			KYEL"	-> An argument is needed <-\n"KNRM);
	ft_init_ms(&ms);
	ft_parse_file(argv[1]);
	ft_parse_map(&ms, argv[1]);
	ft_extract_points(&ms, argv[1]);
	return (0);
}
