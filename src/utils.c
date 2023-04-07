/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gle-roux <gle-roux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 09:11:47 by gle-roux          #+#    #+#             */
/*   Updated: 2023/04/07 11:12:14 by gle-roux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_print_matrix(t_fdf *ms)
{
	ft_printf("\nMAP / ms->infos.matrix : \n");
	for(int rows = 0; rows < ms->infos->height; rows++)
		{
		for(int columns = 0; columns < ms->infos->width; columns++)
		{
			printf("%d ", ms->infos->matrix[rows][columns]);
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
