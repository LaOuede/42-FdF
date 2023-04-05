/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gle-roux <gle-roux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 08:15:28 by gwenolalero       #+#    #+#             */
/*   Updated: 2023/04/05 09:28:05 by gle-roux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_fdf	*ft_init_ms()
{
	t_fdf	*ms;

	ms = ft_calloc(sizeof(*ms), 1);
	if (!ms)
		return (NULL);
	ms->infos.height = 0;
	ms->infos.width = 0;
	ms->infos.z_max = 0;
	ms->infos.z_min = 0;
	return (ms);
}

int	main(int argc, char **argv)
{
	static t_fdf	*ms;

	if (argc != 2)
		ft_error_parse("Usage : ./fdf <map.fdf>\n"
			KYEL"	-> An argument is needed <-\n"KNRM);
	ms = ft_init_ms();
	ft_parse_file(argv[1]);
	ft_parse_map(ms, argv[1]);
	ft_extract_points(ms, argv[1]);
	free(ms);
	return (0);
}
