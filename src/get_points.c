/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_points.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gle-roux <gle-roux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 10:52:07 by gle-roux          #+#    #+#             */
/*   Updated: 2023/04/05 13:00:17 by gle-roux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_get_matrix(t_fdf *ms, char *str)
{
	//int		x;
	int		y;
	//int		i;
	//int		z;
	int		x;
	char	**rows;
	char	 **split;
	int		matrix[ms->infos.height][ms->infos.width];


	(void) ms;
	rows = ft_split(str, '\n');
/* 	z = 0;
	while (rows[z])
	{
		ft_printf("Rows %d = %s\n", z, rows[z]);
		z++;
	} */
	ft_printf("width = %d\n", ms->infos.width);
	y = 0;
	while (y < ms->infos.height)
	{
		x = 0;
		split = ft_split(rows[y], ' ');
		while (x < ms->infos.width)
		{
			//ft_printf("split %d = %s\n", x, split[x]);
			matrix[x][y] = ft_atol(split[x]);
			//ft_printf("tab[%d][%d] = %d\n", x, y, matrix[x][y]);
			x++;
		}
		y++;
	}
/* 		while(++y < ms->infos.height)
		{
			x = -1;
			while(++x < ms->infos.width)
			{
				ft_printf("i = %d\n", i);
				matrix[x][y] = ft_atol(&rows[0][i++]);
				ft_printf("value matrix[%d][%d]= %d\n", x, y, matrix[x][y]);
			}
		}
		z++;
	} */
	
/* 			for (int k = 0; k < ms->infos.height; k++ ) {
				for (int j = 0; j < ms->infos.width; j++ ) {
					printf("tab[%d][%d] = %d\n", k,j, matrix[k][j] );
					}
				} */
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
