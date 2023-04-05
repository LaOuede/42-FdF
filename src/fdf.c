/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwenolaleroux <gwenolaleroux@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 08:15:28 by gwenolalero       #+#    #+#             */
/*   Updated: 2023/04/05 17:37:12 by gwenolalero      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_fdf	*ft_init_ms(void)
{
	t_fdf	*ms;

	ms = ft_calloc(sizeof(*ms), 1);
	if (!ms)
		return (NULL);
	ms->infos.height = 0;
	ms->infos.width = 0;
	ms->infos.z_max = 0;
	ms->infos.z_min = 0;
	ms->infos.color = F;
	ms->infos.matrix = 0;
	ms->point.x = 0;
	ms->point.y = 0;
	ms->point.z = 0;
	ms->point.color = 0;
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
	ft_get_map(ms, argv[1]);
	free(ms);
	return (0);
}
