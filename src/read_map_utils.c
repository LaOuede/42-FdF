/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gle-roux <gle-roux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 09:13:16 by gle-roux          #+#    #+#             */
/*   Updated: 2023/04/18 10:44:18 by gle-roux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

/*
Allows to store the value of :
	- the altitude max point,
	- the altitude min point.
*/
void	ft_find_z(t_fdf *ms)
{
	int	y;
	int	x;

	y = -1;
	while (++y < ms->height)
	{
		x = -1;
		while (++x < ms->width)
		{
			if (ms->matrix[y][x] > ms->z_max)
				ms->z_max = ms->matrix[y][x];
			if (ms->matrix[y][x] < ms->z_min)
				ms->z_min = ms->matrix[y][x];
		}
	}
}

/* Checks if the map contains color informations */
void	ft_map_is_colored(t_fdf *ms, char *str)
{
	int			index;

	index = 0;
	while (str[index])
	{
		if (str[index] == 'F' || str[index] == 'f')
			ms->color = T;
		index++;
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
