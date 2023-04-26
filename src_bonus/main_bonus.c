/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwenolaleroux <gwenolaleroux@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 08:15:28 by gle-roux          #+#    #+#             */
/*   Updated: 2023/04/26 16:34:19 by gwenolalero      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf_bonus.h"

/*
Handles hooks :
	- Program closure;
	- Projection;
	- Color;
	- Translation;
	- Altitude;
	- Zoom;
	- Rotation;
	- Reset;
*/
void	ft_fdf_keys(mlx_key_data_t keydata, void *param)
{
	(void) param;
	ft_keys_1(keydata, param);
	ft_keys_2(keydata, param);
}

/* Initialize and set the graphic library and the window */
t_flag	ft_init_mlx(t_fdf *ms, char *file)
{
	ms->mlx = mlx_init(WIDTH, HEIGHT, file, F);
	ms->image = mlx_new_image(ms->mlx, WIDTH, HEIGHT);
	mlx_image_to_window(ms->mlx, ms->image, 300, 0);
	if (!ms->mlx || !ms->image
		|| (mlx_image_to_window(ms->mlx, ms->image, 300, 0) == 0))
		ft_clean_up(ms, KRED"MLX initialization failed\n"KNRM);
	return (T);
}

/*
Checks :
	- if the <map.fdf> is valid / exist,
	- if the extension is .fdf,
	- if .fdf is a file and not a directory,
	- if the file can be opened.
*/
void	ft_parse_file(t_fdf *ms, char *file)
{
	int		fd;
	char	*check_file;

	check_file = NULL;
	check_file = ft_strrchr(file, '.');
	if (!check_file)
		ft_clean_up(ms, "Usage : ./fdf <map.fdf>\n"
			KYEL"	-> File is invalid <-\n"KNRM);
	if (ft_strcmp(check_file, ".fdf") != 0)
		ft_clean_up(ms, "Usage : ./fdf <map.fdf>\n"
			KYEL"	-> File has an invalid extension <-\n"KNRM);
	fd = open(file, O_RDONLY);
	if (fd == -1)
		ft_clean_up(ms, "Usage : ./fdf <map.fdf>\n"
			KYEL"	-> File can't be opened OR File doesn't exist <-\n"KNRM);
	close(fd);
}

int	main(int argc, char **argv)
{
	t_fdf	*ms;

	if (argc != 2)
		ft_clean_up(0, "Usage : ./fdf <map.fdf>\n"
			KYEL"	-> An argument is needed <-\n"KNRM);
	ms = ft_init_ms();
	ft_parse_file(ms, argv[1]);
	ft_read_map(ms, argv[1]);
	if (ft_init_mlx(ms, argv[1]) == T)
	{
		mlx_key_hook(ms->mlx, &ft_fdf_keys, ms);
		ft_draw(ms);
		ft_add_menu(ms);
		mlx_loop(ms->mlx);
	}
	ft_clean_up(ms, NULL);
}
