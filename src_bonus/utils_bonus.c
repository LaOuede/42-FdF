/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gle-roux <gle-roux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 09:11:47 by gle-roux          #+#    #+#             */
/*   Updated: 2023/04/25 15:01:10 by gle-roux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf_bonus.h"

int	ft_get_rgba(int r, int g, int b, int a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

/* Get the starting points on the screen */
void	ft_get_starting_points(t_fdf *ms)
{
	ms->coord->proj_sx += WIDTH / 2 - MENU_WIDTH / 2;
	ms->coord->proj_sy += HEIGHT / 2;
	ms->coord->proj_ex += WIDTH / 2 - MENU_WIDTH / 2;
	ms->coord->proj_ey += HEIGHT / 2;
}

void	ft_add_menu(t_fdf *ms)
{
	ms->menu->menu_txt = mlx_load_png(MENU);
	ms->menu->menu_img = mlx_texture_to_image(ms->mlx, ms->menu->menu_txt);
	mlx_delete_texture(ms->menu->menu_txt);
	mlx_image_to_window(ms->mlx, ms->menu->menu_img, 1620, 0);
	if (!ms->menu->menu_img
		|| (mlx_image_to_window(ms->mlx, ms->menu->menu_img, 1620, 0) == 0))
		ft_clean_up(ms, KRED"Menu initialization failed\n"KNRM);
}

void	ft_map_scale(t_fdf *ms)
{
	int	x;
	int	y;

	x = (WIDTH - MENU_WIDTH - MARGE) / ms->width;
	y = (HEIGHT - MARGE) / ms->height;
	if (x < 20 || y < 20)
		ms->cam->scale = 10;
	else if (x <= y)
		ms->cam->scale = x / 5;
	else if (x > y)
		ms->cam->scale = y / 5;
	ms->coord->sx *= ms->cam->scale + ms->cam->zoom;
	ms->coord->sy *= ms->cam->scale + ms->cam->zoom;
	ms->coord->sz *= (ms->cam->scale + ms->cam->zoom) / ms->cam->scale;
	ms->coord->ex *= ms->cam->scale + ms->cam->zoom;
	ms->coord->ey *= ms->cam->scale + ms->cam->zoom;
	ms->coord->ez *= (ms->cam->scale + ms->cam->zoom) / ms->cam->scale;
}
