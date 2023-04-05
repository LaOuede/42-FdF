/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_points.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwenolaleroux <gwenolaleroux@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 10:52:07 by gle-roux          #+#    #+#             */
/*   Updated: 2023/04/05 17:38:49 by gwenolalero      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_extract_points(t_fdf *ms, char *line)
{
	int				i;
	int				x;
	static int		y = 0;
	char			**point;

	(void) ms;
	ms->infos.matrix = ft_calloc(ms->infos.height, sizeof (int *));
	if (!ms->infos.matrix)
		exit(1);
	i = -1;
	while (++i < ms->infos.height)
		ms->infos.matrix[i] = ft_calloc(ms->infos.width, sizeof (int));
	point = ft_split(line, ' ');
	x = 0;
	while (x < ms->infos.width)
	{
		ms->infos.matrix[y][x] = ft_atoi(point[x]);
		ft_printf("%d ", ms->infos.matrix[y][x]);
		x++;
	}
	y++;
	ft_printf("\n");
	ft_free_tab(point);
}

void	ft_get_map(t_fdf *ms, char *file)
{
	int		fd;
	char	*line;

	fd = open(file, O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		ft_extract_points(ms, line);
		free(line);
	}
	close (fd);
}
