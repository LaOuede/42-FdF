/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gle-roux <gle-roux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 10:10:07 by gle-roux          #+#    #+#             */
/*   Updated: 2023/04/07 12:17:51 by gle-roux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../MLX42/include/MLX42/MLX42.h"
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
/* # define WIDTH 1920
# define HEIGHT 1080 */

/* -------------------STRUCTURES------------------- */
typedef enum flag
{
	F,
	T
}	t_flag;

typedef struct s_infos
{
	int			width;
	int			height;
	int			z_min;
	int			z_max;
	enum flag	color;
	int			**matrix;
}	t_infos;

typedef struct s_fdf
{
	t_infos		*map;
	mlx_t		*mlx;
	mlx_image_t	*image;
}	t_fdf;

/* --------------------FUNCTIONS------------------- */
void	ft_clean_up(t_fdf *ms, char *err_msg);
void	ft_error(char *err_msg, int fd);
void	ft_extract_infos(t_fdf *ms, char *file);
void	ft_extract_points(t_fdf *ms, char *line);
void	ft_find_z(t_fdf *ms);
t_infos	*ft_init_infos(void);
void	ft_init_matrix(t_fdf *ms);
void	ft_init_mlx(t_fdf *ms);
t_fdf	*ft_init_ms(void);
void	ft_map_is_colored(t_fdf *ms, char *str);
void	ft_map_width(t_fdf *ms, char *line);
void	ft_parse_file(t_fdf *ms, char *file);
void	ft_read_map(t_fdf *ms, char *file);

/* ----------------UTILS FUNCTIONS----------------- */
void	ft_print_matrix(t_fdf *ms);
int		ft_valid_char(char c);

#endif
