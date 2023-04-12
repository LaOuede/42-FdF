/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwenolaleroux <gwenolaleroux@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 10:10:07 by gle-roux          #+#    #+#             */
/*   Updated: 2023/04/12 17:48:25 by gwenolalero      ###   ########.fr       */
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
# include <stdlib.h>
# include <stdbool.h>
# include <math.h>
# include <limits.h>

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
# define WIDTH 960
# define HEIGHT 540
# define MARGE 25
/* # define WIDTH 1920
# define HEIGHT 1080
# define MARGE 100 */

/* -------------------STRUCTURES------------------- */
typedef enum flag
{
	F,
	T
}	t_flag;

typedef struct s_point
{
	float	start_x;
	float	start_y;
	float	start_z;
	float	end_x;
	float	end_y;
	float	end_z;
}	t_point;

typedef struct s_bresenham
{
	int	delta_x;
	int	delta_y;
	int	ptp;
	int	delta_max;
}	t_bresenham;

typedef struct s_camera
{
	double	x_offset;
	double	y_offset;
	int		scale;
}	t_camera;

typedef struct s_infos
{
	double		width;
	double		height;
	double		z_min;
	double		z_max;
	enum flag	color;
	int			**matrix;
	double		x_start;
	double		y_start;

}	t_infos;

typedef struct s_fdf
{
	t_infos		*map;
	t_camera	*cam;
	t_bresenham	*algo;
	t_point		*coord;
	mlx_t		*mlx;
	mlx_image_t	*image;
	keys_t		*keys;
}	t_fdf;

/* --------------------FUNCTIONS------------------- */
void	ft_clean_up(t_fdf *ms, char *err_msg);
void	ft_draw_line(t_fdf *ms);
void	ft_error(char *err_msg, int fd);
void	ft_extract_infos(t_fdf *ms, char *file);
void	ft_extract_points(t_fdf *ms, char *line);
void	ft_fdf_keys(mlx_key_data_t keydata, void *param);
void	ft_find_z(t_fdf *ms);
void	ft_get_starting_points(t_fdf *ms);
t_infos	*ft_init_infos(void);
void	ft_init_matrix(t_fdf *ms);
bool	ft_init_mlx(t_fdf *ms, char *file);
t_fdf	*ft_init_ms(void);
void	ft_map_is_colored(t_fdf *ms, char *str);
void	ft_map_width(t_fdf *ms, char *line);
void	ft_parse_file(t_fdf *ms, char *file);
void	ft_read_map(t_fdf *ms, char *file);

/* ----------------UTILS FUNCTIONS----------------- */
void	ft_print_infos(t_fdf *ms);
int		ft_valid_char(char c);
void	ft_draw_cross(t_fdf *ms);
void	ft_map_erase(t_fdf *ms);
void	ft_draw_map_square(t_fdf *ms);
bool	ft_limits(t_fdf *ms);
void	ft_find_scale(t_fdf *ms);
void	ft_map_scale(t_fdf *ms);

#endif
