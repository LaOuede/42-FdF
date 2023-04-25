/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gle-roux <gle-roux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 09:11:47 by gle-roux          #+#    #+#             */
/*   Updated: 2023/04/25 14:38:21 by gle-roux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

/* Get the starting points on the screen */
void	ft_get_starting_points(t_fdf *ms)
{
	ms->coord->proj_sx += WIDTH / 2;
	ms->coord->proj_sy += HEIGHT / 2 - (ms->height * ms->cam->scale / 2);
	ms->coord->proj_ex += WIDTH / 2;
	ms->coord->proj_ey += HEIGHT / 2 - (ms->height * ms->cam->scale / 2);
}

void	ft_colorscheme(t_fdf *ms)
{
	if (ms->cam->colors == standard)
		mlx_put_pixel(ms->image, (ms->coord->proj_sx + \
						ms->cam->x_offset), (ms->coord->proj_sy + \
						ms->cam->y_offset), ft_get_rgba(0, 0, 0, 255));
	else if (ms->cam->colors == icewindale)
		ft_icewindale(ms);
	else if (ms->cam->colors == phandelver)
		ft_phandelver(ms);
	else if (ms->cam->colors == strahd)
		ft_strahd(ms);
	else if (ms->cam->colors == avernus)
		ft_avernus(ms);
}

void	ft_add_menu(t_fdf *ms)
{
	ms->menu->menu_txt = mlx_load_png(MENU);
	ms->menu->menu_img = mlx_texture_to_image(ms->mlx, ms->menu->menu_txt);
	mlx_delete_texture(ms->menu->menu_txt);
	mlx_image_to_window(ms->mlx, ms->menu->menu_img, 0, 0);
	if (!ms->menu->menu_img
		|| (mlx_image_to_window(ms->mlx, ms->menu->menu_img, 0, 0) == 0))
		ft_clean_up(ms, KRED"Menu initialization failed\n"KNRM);
}

void	ft_map_scale(t_fdf *ms)
{
	int	x;
	int	y;

	x = WIDTH / ms->width;
	y = HEIGHT / ms->height;
	if (x < 10 || y < 10)
		ms->cam->scale = 10;
	else if (x <= y)
		ms->cam->scale = x / 2;
	else if (x > y)
		ms->cam->scale = y / 2;
	ms->coord->sx = ms->coord->sx * ms->cam->scale;
	ms->coord->sy = ms->coord->sy * ms->cam->scale;
	ms->coord->ex = ms->coord->ex * ms->cam->scale;
	ms->coord->ey = ms->coord->ey * ms->cam->scale;
}
