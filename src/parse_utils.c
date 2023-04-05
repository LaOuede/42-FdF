/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gle-roux <gle-roux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 09:13:16 by gle-roux          #+#    #+#             */
/*   Updated: 2023/04/04 15:41:41 by gle-roux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_map_width(t_fdf *ms, char *line)
{
	int	index;
	static int	flag = 0;

	index = 0;
	while (flag == 0 && line[index])
	{
		if (ft_iswhitespace(line[index]) == 1)
			index++;
		if (ft_valid_char(line[index]) == 1)
		{
			ms->infos.width++;
			while (ft_valid_char(line[index]) == 1)
				index++;
		}
	}
	flag--;
}

int	ft_valid_char(char c)
{
	if (c == '-' || c == 'x' || c == 'F' || c == 'f' || c == ',')
		return (1);
	if ('0' <= c && c <= '9')
		return (1);
	return (0);
}

void	ft_map_is_colored(t_fdf *ms, char *str)
{
	int			index;
	static int	flag = 0;

	index = 0;
	while (str[index] && flag == 0)
	{
		if (str[index] == 'F' || str[index] == 'f')
		{
			ms->infos.color = T;
			flag--;
		}
		index++;
	}
}
