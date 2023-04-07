/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gle-roux <gle-roux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 09:11:47 by gle-roux          #+#    #+#             */
/*   Updated: 2023/04/07 12:04:38 by gle-roux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_print_matrix(t_fdf *ms)
{
	ft_printf("\nMAP / ms->map.matrix : \n");
	for(int rows = 0; rows < ms->map->height; rows++)
		{
		for(int columns = 0; columns < ms->map->width; columns++)
		{
			printf("%d ", ms->map->matrix[rows][columns]);
		}
		printf("\n");
	}
}

int	ft_valid_char(char c)
{
	if (c == '-' || c == 'x' || c == 'F' || c == 'f' || c == ',')
		return (1);
	if ('0' <= c && c <= '9')
		return (1);
	return (0);
}
