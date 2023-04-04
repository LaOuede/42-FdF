/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_points.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gle-roux <gle-roux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 10:52:07 by gle-roux          #+#    #+#             */
/*   Updated: 2023/04/04 15:42:27 by gle-roux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_get_matrix(t_fdf *ms, char *str)
{
	int		z;
	char	**rows;
	int		matrix[ms->infos.height][ms->infos.width];

	for (int i = 0; i < ms->infos.height; i++ ) {
		for (int j = 0; j < ms->infos.width; j++ ) {
			printf("tab[%d][%d] = %d\n", i,j, matrix[i][j] );
		}
	}
	(void) ms;
	rows = ft_split(str, '\n');
	z = 0;
	while (rows[z])
	{
		ft_printf("Rows %d = %s\n", z, rows[z]);
		z++;
	}
	ft_free_tab(rows);
}

char	*ft_get_map(char *file)
{
	int		fd;
	char	*line;
	char	*map;
	char	*tmp;

	map = ft_strdup("");
	fd = open(file, O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		tmp = map;
		map = ft_strjoin(map, line);
		free(line);
		free(tmp);
	}
	close (fd);
	return(map);
}

void	ft_extract_points(t_fdf *ms, char *file)
{
	char	*map;

	map = ft_get_map(file);
	ft_printf("map = \n%s", map);
	ft_get_matrix(ms, map);
	free(map);
}
