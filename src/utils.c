/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwenolaleroux <gwenolaleroux@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 09:11:47 by gle-roux          #+#    #+#             */
/*   Updated: 2023/04/07 17:20:29 by gwenolalero      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_draw_something(t_fdf *ms)
{
	for (uint32_t x = 0; x < 77; ++x)
	{
		for (uint32_t y = 0; y < 25; ++y)
		{
			mlx_put_pixel(ms->image, x, y, 0xFF0000FF);
		}
	}
}

void	ft_print_infos(t_fdf *ms)
{
	ft_printf("\n******* MAP infos : ******\n");
	ft_printf("   -> width  ="KYEL"  %d\n"KNRM, ms->map->width);
	ft_printf("   -> height ="KYEL"  %d\n"KNRM, ms->map->height);
	ft_printf("   -> color  ="KYEL"  %d\n"KNRM, ms->map->color);
	ft_printf("   -> z_max  ="KYEL"  %d\n"KNRM, ms->map->z_max);
	ft_printf("   -> z_min  ="KYEL"  %d\n"KNRM, ms->map->z_min);
	ft_printf("\n>>>>>> MAP / ms->map.matrix : <<<<<<\n");
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
