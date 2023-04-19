/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gle-roux <gle-roux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 09:11:47 by gle-roux          #+#    #+#             */
/*   Updated: 2023/04/19 15:18:46 by gle-roux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf_bonus.h"

void	ft_colorscheme(t_fdf *ms)
{
	if (ms->cam->colors == icewindale)
		ft_icewindale(ms);
	else if (ms->cam->colors == phandelver)
		ft_phandelver(ms);
	else if (ms->cam->colors == strahd)
		ft_strahd(ms);
	else if (ms->cam->colors == avernus)
		ft_avernus(ms);
}

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
	if (x < 20 || y < 20)
		ms->cam->scale = 10;
	else if (x <= y)
		ms->cam->scale = x / 5;
	else if (x > y)
		ms->cam->scale = y / 5;
	ms->coord->sx *= ms->cam->scale + ms->cam->zoom;
	ms->coord->sy *= ms->cam->scale + ms->cam->zoom;
	ms->coord->ex *= ms->cam->scale + ms->cam->zoom;
	ms->coord->ey *= ms->cam->scale + ms->cam->zoom;
}


/*
Allows to store the value of :
	- the altitude max point,
	- the altitude min point.
*/
void	ft_find_z(t_fdf *ms)
{
	int	y;
	int	x;

	y = -1;
	while (++y < ms->height)
	{
		x = -1;
		while (++x < ms->width)
		{
			if (ms->matrix[y][x] > ms->z_max)
				ms->z_max = ms->matrix[y][x];
			if (ms->matrix[y][x] < ms->z_min)
				ms->z_min = ms->matrix[y][x];
		}
	}
}

/* Checks if the map contains color informations */
void	ft_map_is_colored(t_fdf *ms, char *str)
{
	int			index;

	index = 0;
	while (str[index])
	{
		if (str[index] == 'F' || str[index] == 'f')
			ms->color = T;
		index++;
	}
}