/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_bonus.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gle-roux <gle-roux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 10:10:07 by gle-roux          #+#    #+#             */
/*   Updated: 2023/04/20 13:47:32 by gle-roux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_BONUS_H
# define FDF_BONUS_H

# include "../MLX42/include/MLX42/MLX42.h"
# include "../MLX42/include/MLX42/MLX42_Input.h"
# include "../libft/includes/libft.h"
# include "../ft_printf/includes/ft_printf.h"
# include <fcntl.h> // O_RDONLY
# include <stdio.h> // open
# include <stdlib.h>
# include <stdbool.h>
# include <math.h>
# include <limits.h>

/* ---------------------MENU---------------------- */
# define MENU "./image/menu_bonus.png"

/* --------------------COLORS--------------------- */
# define KNRM "\x1B[m"
# define KBLD "\x1B[1m"
# define KGRE "\x1B[2m"
# define KITA "\x1B[3m"
# define KUND "\x1B[4m"
# define KRST "\x1B[5m"
# define KRED "\x1B[31m"
# define KGRN "\x1B[32m"
# define KYEL "\x1B[33m"
# define KBLU "\x1B[34m"
# define KMAG "\x1B[35m"
# define KCYN "\x1B[36m"
# define KWHT "\x1B[37m"

/* ----------------WINDOW SETTINGS----------------- */
# define WIDTH 1920
# define HEIGHT 1080
# define MARGE 100

/* -------------------STRUCTURES------------------- */
typedef enum scheme
{
	icewindale,
	phandelver,
	strahd,
	avernus,
}	t_scheme;

typedef enum view
{
	isometric,
	top_view,
}	t_view;

typedef enum flag
{
	F,
	T
}	t_flag;

typedef struct s_menu
{
	mlx_texture_t	*menu_txt;
	mlx_image_t		*menu_img;
}	t_menu;

/* typedef struct s_iso
{
	double	sx;
	double	sy;
	double	sz;
	double	ex;
	double	ey;
	double	ez;
}	t_iso; */

typedef struct s_line
{
	double	sx;
	double	sy;
	double	sz;
	double	ex;
	double	ey;
	double	ez;
	double	proj_sx;
	double	proj_sy;
	double	proj_sz;
	double	proj_ex;
	double	proj_ey;
	double	proj_ez;
}	t_line;

typedef struct s_dda
{
	double	x;
	double	y;
	double	delta_x;
	double	delta_y;
	double	ptp;
	double	delta_max;
}	t_dda;

typedef struct s_camera
{
	double		x_offset;
	double		y_offset;
	double		z_offset;
	double		theta_x;
	double		theta_y;
	double		theta_z;
	double		zoom;
	int			scale;
	t_view		projection;
	t_scheme	colors;
}	t_camera;

typedef struct s_fdf
{
	double		width;
	double		height;
	int		**matrix;
	bool		color;
	int			x;
	int			y;
	int			z_max;
	int			z_min;
	t_camera	*cam;
	t_dda		*algo;
	t_line		*coord;
	mlx_t		*mlx;
	mlx_image_t	*image;
	keys_t		*keys;
	t_menu		*menu;
}	t_fdf;

/* --------------------FUNCTIONS------------------- */
void	ft_add_menu(t_fdf *ms);
void	ft_avernus(t_fdf *ms);
void	ft_clean_up(t_fdf *ms, char *err_msg);
void	ft_colors_hook(t_fdf *ms, keys_t key);
void	ft_colorscheme(t_fdf *ms);
void	ft_dda_algo(t_fdf *ms);
void	ft_draw(t_fdf *ms);
void	ft_error(char *err_msg, int fd);
void	ft_extract_infos(t_fdf *ms, char *file);
void	ft_extract_points(t_fdf *ms, char *line);
void	ft_fdf_keys(mlx_key_data_t keydata, void *param);
int		ft_get_rgba(int r, int g, int b, int a);
void	ft_get_starting_points(t_fdf *ms);
void	ft_icewindale(t_fdf *ms);
void	ft_init_line_x(t_fdf *ms);
void	ft_init_line_y(t_fdf *ms);
void	ft_init_matrix(t_fdf *ms);
bool	ft_init_mlx(t_fdf *ms, char *file);
t_fdf	*ft_init_ms(void);
void	ft_isometric(t_fdf *ms);
void	ft_map_erase(t_fdf *ms);
void	ft_map_scale(t_fdf *ms);
void	ft_map_width(t_fdf *ms, char *line);
void	ft_modifications(t_fdf *ms);
void	ft_parse_file(t_fdf *ms, char *file);
void	ft_phandelver(t_fdf *ms);
void	ft_projection(t_fdf *ms);
void	ft_projection_hook(t_fdf *ms, keys_t key);
void	ft_read_map(t_fdf *ms, char *file);
void	ft_rotation(t_fdf *ms);
void	ft_strahd(t_fdf *ms);
void	ft_top_view(t_fdf *ms);
void	ft_translation(t_fdf *ms);
void	ft_translation_hook(t_fdf *ms, keys_t key);
/* ----------------UTILS FUNCTIONS----------------- */
#endif
