/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gle-roux <gle-roux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 10:10:07 by gle-roux          #+#    #+#             */
/*   Updated: 2023/04/05 09:05:40 by gle-roux         ###   ########.fr       */
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
# define WIDTH 1100
# define HEIGHT 800

/* -------------------STRUCTURES------------------- */
typedef enum flag
{
	F,
	T
}	t_flag;

typedef struct s_map_point
{
	double	x;
	double	y;
	double	z;
	double	color;
}	t_map_point;

typedef struct s_map
{
	int			width;
	int			height;
	int			z_min;
	int			z_max;
	enum flag	color;
}	t_map;

typedef struct s_fdf
{
	t_map		infos;
	t_map_point	point;
}	t_fdf;

/* --------------------FUNCTIONS------------------- */
void	ft_error_parse(char *err_msg);
void	ft_extract_points(t_fdf *ms, char *file);
char	*ft_get_map(char *file);
void	ft_get_matrix(t_fdf *ms, char *str);
void	ft_map_is_colored(t_fdf *ms, char *str);
void	ft_map_width(t_fdf *ms, char *line);
void	ft_parse_file(char *file);
void	ft_parse_map(t_fdf *ms, char *file);
int		ft_valid_char(char c);

/* ----------------UTILS FUNCTIONS----------------- */

#endif
