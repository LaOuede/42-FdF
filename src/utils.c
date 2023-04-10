/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwenolaleroux <gwenolaleroux@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 09:11:47 by gle-roux          #+#    #+#             */
/*   Updated: 2023/04/10 16:37:05 by gwenolalero      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

/* Print map infos*/
void	ft_print_infos(t_fdf *ms)
{
	int	rows;
	int	columns;

	ft_printf("\n******* MAP infos : ******\n");
	ft_printf("   -> width  ="KYEL"  %d\n"KNRM, ms->map->width);
	ft_printf("   -> height ="KYEL"  %d\n"KNRM, ms->map->height);
	ft_printf("   -> color  ="KYEL"  %d\n"KNRM, ms->map->color);
	ft_printf("   -> z_max  ="KYEL"  %d\n"KNRM, ms->map->z_max);
	ft_printf("   -> z_min  ="KYEL"  %d\n"KNRM, ms->map->z_min);
	ft_printf("\n>>>>>> MAP / ms->map.matrix : <<<<<<\n");
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
