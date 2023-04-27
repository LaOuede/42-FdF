/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gle-roux <gle-roux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 10:52:07 by gle-roux          #+#    #+#             */
/*   Updated: 2023/04/27 08:13:48 by gle-roux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

/* Extracts points from the map and store them in a two-dimensionnal array */
void	ft_extract_points(t_fdf *ms, char *line)
{
	int			column;
	char		**point;
	static int	row = 0;

	point = ft_split(line, ' ');
	column = -1;
	while (++column < ms->width)
		ms->matrix[row][column] = ft_atoi(point[column]);
	row++;
	ft_free_tab_char(point);
}

/* Initializes the two-dimensioonnal array. */
void	ft_init_matrix(t_fdf *ms)
{
	int	i;

	ms->matrix = ft_calloc(ms->height, sizeof(int *));
	if (!ms->matrix)
		ft_clean_up(ms, KYEL"-> Failed to init the matrix <-"KNRM);
	i = -1;
	while (++i < ms->height)
	{
		ms->matrix[i] = ft_calloc(ms->width, sizeof(int));
		if (!ms->matrix[i])
			ft_clean_up(ms, KYEL"-> Failed to init the matrix <-"KNRM);
	}
}

/* Allows to store the value of the map's width */
void	ft_map_width(t_fdf *ms, char *str)
{
	int	index;

	index = 0;
	while (str[index])
	{
		if (ft_iswhitespace(str[index]) == 1)
			index++;
		else if (ft_iswhitespace(str[index]) == 0)
		{
			ms->width++;
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
	int		flag;
	char	*line;

	flag = 0;
	fd = open(file, O_RDONLY);
	while (42)
	{
		line = get_next_line(fd);
		if (line == NULL && flag == 0)
			ft_clean_up(ms, "Usage : ./fdf <map.fdf>\n"
				KYEL"	-> File is empty / Map doesn't exist / "KNRM
				KYEL"Trying to open a directory ? <-\n"KNRM);
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
This function :
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
