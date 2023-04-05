/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_points.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gle-roux <gle-roux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 10:52:07 by gle-roux          #+#    #+#             */
/*   Updated: 2023/04/05 14:28:54 by gle-roux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_get_matrix(t_fdf *ms, char *line)
{
	int				x;
	static int		y = 0;
	char			**point;
	int				matrix[ms->infos.height][ms->infos.width];

	(void) ms;
	point = ft_split(line, ' ');
	x = 0;
	while (x < ms->infos.width)
	{
		matrix[y][x] = ft_atoi(point[x]);
		ft_printf("%d ", matrix[y][x]);
		x++;
	}
	y++;
	ft_printf("\n");
	
/* 	for (int k = 0; k < ms->infos.height; k++ ) {
		for (int j = 0; j < ms->infos.width; j++ ) {
			printf("tab[%d][%d] = %d\n", k,j, matrix[k][j] );
		}
	} */
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
		ft_get_matrix(ms, line);
		free(line);
	}
	close (fd);
}

void	ft_extract_points(t_fdf *ms, char *file)
{
	ft_get_map(ms, file);
}
