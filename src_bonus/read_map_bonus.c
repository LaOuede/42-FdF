/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gle-roux <gle-roux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 10:52:07 by gle-roux          #+#    #+#             */
/*   Updated: 2023/04/25 12:33:18 by gle-roux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf_bonus.h"

/* Extracts points from the map and store them in a two-dimensionnal array */
void	ft_extract_points(t_fdf *ms, char *line)
{
	int				column;
	static int		row = 0;
	char			**point;

	point = ft_split(line, ' ');
	column = -1;
	while (++column < ms->width)
		ms->matrix[row][column] = ft_atoi(point[column]);
	row++;
	ft_free_tab_char(point);
}

/* Initialize the two-dimensioonnal array. */
void	ft_init_matrix(t_fdf *ms)
{
	int	i;

	ms->matrix = ft_calloc(ms->height, sizeof(int *));
	if (!ms->matrix)
		exit(EXIT_FAILURE);
	i = -1;
	while (++i < ms->height)
	{
		ms->matrix[i] = ft_calloc(ms->width, sizeof(int));
		if (!ms->matrix[i])
		{
			ft_free_tab_int(ms->matrix, ms->height);
			exit(EXIT_FAILURE);
		}
	}
}

/* Allows to store the value of the map's width */
void	ft_map_width(t_fdf *ms, char *str)
{
	int			index;

	index = 0;
	while (str[index])
	{
		if (ft_iswhitespace(str[index]) == 1)
			index++;
		else if (ft_iswhitespace(str[index]) == 0)
		{
			(ms->width)++;
			while (ft_iswhitespace(str[index]) == 0)
				index++;
		}
	}
}

/*
Checks if the <map.fdf> is empty.
Gather map infos (width, height, color).
*/
void	ft_extract_infos(t_fdf *ms, char *file)
{
	int		fd;
	char	*line;
	int		flag;

	flag = 0;
	fd = open(file, O_RDONLY);
	while (42)
	{
		line = get_next_line(fd);
		if (line == NULL && flag == 0)
			ft_clean_up(ms, "Usage : ./fdf <map.fdf>\n"
				KYEL"	-> File is empty / Map doesn't exist <-\n"KNRM);
		if (line == NULL)
			break ;
		if (flag == 0)
			ft_map_width(ms, line);
		free(line);
		(ms->height)++;
		flag = 42;
	}
	close (fd);
}

/*
This function
	- reads the map,
	- extracts informations,
	- extracts points from the map,
	- stores the points (y,x) in a two-dimentional array.
*/
void	ft_read_map(t_fdf *ms, char *file)
{
	int		fd;
	char	*line;

	ft_extract_infos(ms, file);
	ft_init_matrix(ms);
	fd = open(file, O_RDONLY);
	while (42)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		ft_extract_points(ms, line);
		free(line);
	}
	close (fd);
}
