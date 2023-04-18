/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gle-roux <gle-roux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 09:11:47 by gle-roux          #+#    #+#             */
/*   Updated: 2023/04/18 15:44:28 by gle-roux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

/* Get the starting points on the screen */
void	ft_get_starting_points(t_fdf *ms)
{
	/* 	ms->iso->start_x += WIDTH / 2 - ((ms->map->width * ms->cam->scale / 2) - (ms->map->height * ms->cam->scale / 2));
		ms->iso->start_y += HEIGHT / 2 - (ms->map->height * ms->cam->scale / 2);
		ms->iso->end_x += WIDTH / 2 - ((ms->map->width * ms->cam->scale / 2) - (ms->map->height * ms->cam->scale / 2));
		ms->iso->end_y += HEIGHT / 2 - (ms->map->height * ms->cam->scale / 2); */
	ms->coord->proj_sx += WIDTH / 2;
	ms->coord->proj_sy += HEIGHT / 2 - (ms->height * ms->cam->scale / 2);
	ms->coord->proj_ex += WIDTH / 2;
	ms->coord->proj_ey += HEIGHT / 2 - (ms->height * ms->cam->scale / 2);
		/* ms->iso->start_x = (WIDTH / 2) - (ms->map->width * ms->cam->scale / 2);
		ms->iso->start_y = (HEIGHT / 2) - (ms->map->height * ms->cam->scale / 2); */
}

/* Draw the points of the previous image with the background color */
void	ft_map_erase(t_fdf *ms)
{
	double	x;
	double	y;

	x = 0;
	while (x < WIDTH)
	{
		y = 0;
		while (y < HEIGHT)
		{
			mlx_put_pixel(ms->image, x, y, ft_get_rgba(102, 102, 102, 115));
			y++;
		}
		x++;
	}
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
