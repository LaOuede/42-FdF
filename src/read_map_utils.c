/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gle-roux <gle-roux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 09:13:16 by gle-roux          #+#    #+#             */
/*   Updated: 2023/04/07 10:05:28 by gle-roux         ###   ########.fr       */
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
	while (++y < ms->infos.height)
	{
		x = -1;
		while (++x < ms->infos.width)
		{
			if (ms->infos.matrix[y][x] > ms->infos.z_max)
				ms->infos.z_max = ms->infos.matrix[y][x];
			if (ms->infos.matrix[y][x] < ms->infos.z_min)
				ms->infos.z_min = ms->infos.matrix[y][x];
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
			ms->infos.color = T;
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
			ms->infos.width++;
			while (ft_iswhitespace(str[index]) == 0)
				index++;
		}
	}
}
