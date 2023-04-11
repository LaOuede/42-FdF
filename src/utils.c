/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gle-roux <gle-roux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 09:11:47 by gle-roux          #+#    #+#             */
/*   Updated: 2023/04/11 15:16:53 by gle-roux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

/* bool	ft_limits(t_fdf *ms)
{
	int	x = -1;
	int	y = -1;

	while (++y < (ms->map->height))
	{
		while (++x < ms->map->width)
		{
			if (ms->map->matrix[y][x] > (WIDTH  - MARGE)
			|| ms->map->matrix[y][x] > (HEIGHT - MARGE))
				return (F);
		}
	}
	return (T);
} */

/* Print map infos*/
void	ft_print_infos(t_fdf *ms)
{
	int	rows;
	int	columns;

	printf("\n******* MAP infos : ******\n");
	printf("   -> width  ="KYEL"  %f\n"KNRM, ms->map->width);
	printf("   -> height ="KYEL"  %f\n"KNRM, ms->map->height);
	printf("   -> color  ="KYEL"  %d\n"KNRM, ms->map->color);
	printf("   -> z_max  ="KYEL"  %f\n"KNRM, ms->map->z_max);
	printf("   -> z_min  ="KYEL"  %f\n"KNRM, ms->map->z_min);
	printf("   -> scale  ="KYEL"  %f\n"KNRM, ms->map->scale);
	printf("\n>>>>>> MAP / ms->map.matrix : <<<<<<\n");
	rows = -1;
	while (++rows < ms->map->height)
	{
		columns = -1;
		while (++columns < ms->map->width)
			printf("%d ", ms->map->matrix[rows][columns]);
		printf("\n");
	}
}

/* int	ft_valid_char(char c)
{
	if (c == '-' || c == 'x' || c == 'F' || c == 'f' || c == ',')
		return (1);
	if ('0' <= c && c <= '9')
		return (1);
	return (0);
} */
