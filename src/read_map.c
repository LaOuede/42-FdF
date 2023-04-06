/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwenolaleroux <gwenolaleroux@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 10:52:07 by gle-roux          #+#    #+#             */
/*   Updated: 2023/04/06 17:39:58 by gwenolalero      ###   ########.fr       */
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

/*
Checks if the <map.fdf> is empty.
Gather map infos.
*/
void	ft_parse_map(t_fdf *ms, char *file)
{
	int		fd;
	char	*line;

	fd = open(file, O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
/* 		{
			close(fd);
			ft_error("Usage : ./fdf <map.fdf>\n"
				KYEL"	-> File is empty / Map doesn't exist <-\n"KNRM);
		} */
		ft_map_width(ms, line);
		ft_map_is_colored(ms, line);
		free(line);
		ms->infos.height++;
	}
	ft_printf("width = %d\n", ms->infos.width);
	ft_printf("height = %d\n", ms->infos.height);
	ft_printf("color = %d\n", ms->infos.color);
	close (fd);
}

void	ft_read_map(t_fdf *ms, char *file)
{
	int		fd;
	char	*line;

	ft_parse_map(ms, file);
	ft_init_matrix(ms);
	fd = open(file, O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		ft_extract_points(ms, line);
		free(line);
	}
	ft_print_matrix(ms);
	close (fd);
}
