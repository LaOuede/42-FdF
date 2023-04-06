/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gle-roux <gle-roux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 10:52:07 by gle-roux          #+#    #+#             */
/*   Updated: 2023/04/06 09:02:20 by gle-roux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_extract_points(t_fdf *ms, char *line)
{
	int				column;
	static int		row = 0;
	char			**point;

	point = ft_split(line, ' ');
	column = -1;
	while (++column < ms->infos.width)
		ms->infos.matrix[row][column] = ft_atoi(point[column]);
	row++;
	ft_free_tab_char(point);
}

void	ft_get_map(t_fdf *ms, char *file)
{
	int		i;
	int		fd;
	char	*line;

	ms->infos.matrix = ft_calloc(ms->infos.height, sizeof (int *));
	if (!ms->infos.matrix)
		exit(EXIT_FAILURE);
	i = -1;
	while (++i < ms->infos.height)
		ms->infos.matrix[i] = ft_calloc(ms->infos.width, sizeof (int));
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
