/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_bonus.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gle-roux <gle-roux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 10:10:07 by gle-roux          #+#    #+#             */
/*   Updated: 2023/04/26 11:35:47 by gle-roux         ###   ########.fr       */
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

/* ---------------------COLORS--------------------- */
# define KNRM "\x1B[m"
# define KRED "\x1B[31m"
# define KYEL "\x1B[33m"

/* --------------------SETTINGS-------------------- */
# define WIDTH 1920
# define HEIGHT 1080
# define MENU_WIDTH 300
# define MARGE 25
# define PI 3.14159265358979323846

/* ----------------------MENU---------------------- */
# define MENU "./image/menu_bonus.png"

/* -------------------STRUCTURES------------------- */
typedef enum scheme
{
	standard,
	icewindale,
	phandelver,
	strahd,
	avernus,
}	t_scheme;

typedef enum view
{
	isometric_view,
	top_view,
	oblique_view,
	width_side_view,
	height_side_view,
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
	double	pixel;
}	t_dda;

typedef struct s_camera
{
	t_scheme	colors;
	t_view		projection;
	double		x_offset;
	double		y_offset;
	double		z_offset;
	int			scale;
	double		angle_x;
	double		angle_y;
	double		angle_z;
	double		zoom;
}	t_camera;

typedef struct s_fdf
{
	int			x;
	int			y;
	double		height;
	double		width;
	int			**matrix;
	t_camera	*cam;
	t_dda		*algo;
	t_line		*coord;
	t_menu		*menu;
	mlx_t		*mlx;
	mlx_image_t	*image;
	keys_t		*keys;
}	t_fdf;

/* -------------PARSING & INITIALIZING------------- */
void	ft_parse_file(t_fdf *ms, char *file);
void	ft_init_line_x(t_fdf *ms);
void	ft_init_line_y(t_fdf *ms);
void	ft_init_matrix(t_fdf *ms);
t_flag	ft_init_mlx(t_fdf *ms, char *file);
t_fdf	*ft_init_ms(void);

/* ------------------CLEANING UP------------------- */
void	ft_clean_up(t_fdf *ms, char *err_msg);
void	ft_error(char *err_msg, int fd);

/* ------------------READING MAP------------------- */
void	ft_extract_infos(t_fdf *ms, char *file);
void	ft_extract_points(t_fdf *ms, char *line);
void	ft_read_map(t_fdf *ms, char *file);
void	ft_map_width(t_fdf *ms, char *line);

/* ---------------------HOOKS---------------------- */
void	ft_colors_hook(t_fdf *ms, keys_t key);
void	ft_fdf_keys(mlx_key_data_t keydata, void *param);
void	ft_keys_1(mlx_key_data_t keydata, void *param);
void	ft_keys_2(mlx_key_data_t keydata, void *param);
void	ft_projection(t_fdf *ms);
void	ft_projection_hook(t_fdf *ms, keys_t key);
void	ft_rotation(t_fdf *ms);
void	ft_rotation_x(t_fdf *ms);
void	ft_rotation_y(t_fdf *ms);
void	ft_rotation_z(t_fdf *ms);
void	ft_translation(t_fdf *ms);
void	ft_translation_hook(t_fdf *ms, keys_t key);

/* --------------------DRAWING--------------------- */
void	ft_colorscheme(t_fdf *ms);
void	ft_dda_algo(t_fdf *ms);
void	ft_draw(t_fdf *ms);
void	ft_draw_x(t_fdf *ms);
void	ft_draw_y(t_fdf *ms);
int		ft_get_rgba(int r, int g, int b, int a);
void	ft_get_starting_points(t_fdf *ms);
void	ft_map_erase(t_fdf *ms);
void	ft_map_scale(t_fdf *ms);
void	ft_modifications(t_fdf *ms);

/* ---------------------UTILS---------------------- */
void	ft_add_menu(t_fdf *ms);
void	ft_avernus(t_fdf *ms);
void	ft_bottom_view(t_fdf *ms);
void	ft_height_side_view(t_fdf *ms);
void	ft_icewindale(t_fdf *ms);
void	ft_isometric_view(t_fdf *ms);
void	ft_oblique_view(t_fdf *ms);
void	ft_phandelver(t_fdf *ms);
void	ft_standard(t_fdf *ms);
void	ft_strahd(t_fdf *ms);
void	ft_top_view(t_fdf *ms);
void	ft_width_side_view(t_fdf *ms);

#endif
