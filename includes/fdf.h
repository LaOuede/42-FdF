/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwenolaleroux <gwenolaleroux@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 10:10:07 by gle-roux          #+#    #+#             */
/*   Updated: 2023/04/26 14:45:38 by gwenolalero      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../MLX42/include/MLX42/MLX42.h"
# include "../MLX42/include/MLX42/MLX42_Input.h"
# include "../libft/includes/libft.h"
# include "../ft_printf/includes/ft_printf.h"
# include <fcntl.h> // O_RDONLY
# include <stdio.h> // open
# include <math.h>
# include <limits.h>

/* ---------------------COLORS--------------------- */
# define KNRM "\x1B[m"
# define KRED "\x1B[31m"
# define KYEL "\x1B[33m"

/* ----------------WINDOW SETTINGS----------------- */
# define WIDTH 960
# define HEIGHT 540

/* ----------------------MENU---------------------- */
# define MENU "./images/menu.png"

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
	mlx_image_t		*menu_img;
	mlx_texture_t	*menu_txt;
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
	int			scale;
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
void	ft_init_line_x(t_fdf *ms);
void	ft_init_line_y(t_fdf *ms);
void	ft_init_matrix(t_fdf *ms);
t_flag	ft_init_mlx(t_fdf *ms, char *file);
t_fdf	*ft_init_ms(void);
void	ft_parse_file(t_fdf *ms, char *file);

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
void	ft_projection(t_fdf *ms);
void	ft_projection_hook(t_fdf *ms, keys_t key);

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

/* ---------------------UTILS---------------------- */
void	ft_add_menu(t_fdf *ms);
void	ft_avernus(t_fdf *ms);
void	ft_icewindale(t_fdf *ms);
void	ft_isometric_view(t_fdf *ms);
void	ft_phandelver(t_fdf *ms);
void	ft_strahd(t_fdf *ms);
void	ft_top_view(t_fdf *ms);

#endif
