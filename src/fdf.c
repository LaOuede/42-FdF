/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gle-roux <gle-roux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 08:15:28 by gwenolalero       #+#    #+#             */
/*   Updated: 2023/04/06 09:04:42 by gle-roux         ###   ########.fr       */
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
	printf("\nms->infos.matrix : \n");
	for(int rows = 0; rows < ms->infos.height; rows++)
		{
		for(int columns = 0; columns < ms->infos.width; columns++)
		{
			printf("%d ", ms->infos.matrix[rows][columns]);
		}
		printf("\n");
	}
	ft_free_tab_int(ms->infos.matrix, (size_t)ms->infos.height);
	free(ms);
	return (0);
}
