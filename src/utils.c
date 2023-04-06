/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gle-roux <gle-roux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 09:11:47 by gle-roux          #+#    #+#             */
/*   Updated: 2023/04/06 11:54:01 by gle-roux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_print_matrix(t_fdf *ms)
{
	ft_printf("\nMAP / ms->infos.matrix : \n");
	for(int rows = 0; rows < ms->infos.height; rows++)
		{
		for(int columns = 0; columns < ms->infos.width; columns++)
		{
			printf("%d ", ms->infos.matrix[rows][columns]);
		}
		printf("\n");
	}
}
