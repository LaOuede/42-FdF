/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwenolaleroux <gwenolaleroux@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 16:34:37 by gwenolalero       #+#    #+#             */
/*   Updated: 2023/04/25 18:01:43 by gwenolalero      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf_bonus.h"

/* This code implements the DDA (Digital Differential Analyzer) algorithm for
line drawing in a 2D space.

The algorithm works by taking two points in the 2D space, and then computing
the slope between them to determine the change in the x and y coordinates
needed to draw a straight line between them.

Here's a breakdown of what each line in the code does:

ms->algo->delta_x = ms->coord->proj_ex - ms->coord->proj_sx; :
This line computes the difference between the x coordinates of the
start and end points of the line to be drawn.
ms->algo->delta_y = ms->coord->proj_ey - ms->coord->proj_sy; :
This line computes the difference between the y coordinates of the start
and end points of the line to be drawn.
if (fabs(ms->algo->delta_x) >= fabs(ms->algo->delta_y)) :
This line checks if the difference in the x coordinates is greater than
or equal to the difference in the y coordinates.
ms->algo->delta_max = fabs(ms->algo->delta_x); :
If the previous condition is true, this line sets the maximum distance to be
covered by the algorithm to the difference in the x coordinates, otherwise 
t sets it to the difference in the y coordinates.
ms->algo->delta_x /= ms->algo->delta_max; :
This line divides the change in x by the maximum distance to be covered.
This will result in a fraction between 0 and 1 that will be used to
increment the x coordinate in each step of the algorithm.
ms->algo->delta_y /= ms->algo->delta_max; :
This line does the same as the previous one, but for the y coordinate.
ms->algo->pixel = -1; : This line initializes a counter variable pixel to -1.
while (++(ms->algo->pixel) <= ms->algo->delta_max) :
This line starts a loop that will run delta_max + 1 times, where delta_max
is the maximum distance between the start and end points. In each iteration,
the loop increments the pixel variable by 1.
if (ms->coord->proj_sx > MARGE && ms->coord->proj_sy > MARGE &&
ms->coord->proj_sx < WIDTH - MENU_WIDTH - MARGE &&
ms->coord->proj_sy < HEIGHT - MARGE) : This line checks if the current pixel
being drawn is within the boundaries of the window. If so, it calls
ft_colorscheme(ms) to set the color of the pixel.
ms->coord->proj_sx += ms->algo->delta_x; : This line increments
the x coordinate of the pixel by delta_x.
ms->coord->proj_sy += ms->algo->delta_y; : This line does the same as the
previous one, but for the y coordinate.
Overall, this code calculates the slope of the line between two points and
then increments the x and y coordinates of each pixel along that line by a
fraction of that slope until the end point is reached.
The result is a straight line drawn between the two points. */

void	ft_dda_algo(t_fdf *ms)
{
	ms->algo->delta_x = ms->coord->proj_ex - ms->coord->proj_sx;
	ms->algo->delta_y = ms->coord->proj_ey - ms->coord->proj_sy;
	if (fabs(ms->algo->delta_x) >= fabs(ms->algo->delta_y))
		ms->algo->delta_max = fabs(ms->algo->delta_x);
	else
		ms->algo->delta_max = fabs(ms->algo->delta_y);
	ms->algo->delta_x /= ms->algo->delta_max;
	ms->algo->delta_y /= ms->algo->delta_max;
	ms->algo->pixel = -1;
	while (++(ms->algo->pixel) <= ms->algo->delta_max)
	{
		if (ms->coord->proj_sx > MARGE && ms->coord->proj_sy > MARGE
			&& ms->coord->proj_sx < WIDTH - MENU_WIDTH - MARGE
			&& ms->coord->proj_sy < HEIGHT - MARGE)
			ft_colorscheme(ms);
		ms->coord->proj_sx += ms->algo->delta_x;
		ms->coord->proj_sy += ms->algo->delta_y;
	}
}

void	ft_draw_x(t_fdf *ms)
{
	ft_init_line_x(ms);
	if (ms->cam->angle_x != 0 || ms->cam->angle_y != 0 || ms->cam->angle_z != 0)
		ft_rotation(ms);
	ft_map_scale(ms);
	ft_projection(ms);
	ft_get_starting_points(ms);
	ft_translation(ms);
	if (ms->cam->zoom >= -19)
		ft_dda_algo(ms);
}

void	ft_draw_y(t_fdf *ms)
{
	ft_init_line_y(ms);
	if (ms->cam->angle_x != 0 || ms->cam->angle_y != 0 || ms->cam->angle_z != 0)
		ft_rotation(ms);
	ft_map_scale(ms);
	ft_projection(ms);
	ft_get_starting_points(ms);
	ft_translation(ms);
	if (ms->cam->zoom >= -19)
		ft_dda_algo(ms);
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

/* Draw the points of the map */
void	ft_draw(t_fdf *ms)
{
	ft_map_erase(ms);
	ms->y = -1;
	while (++ms->y < ms->height)
	{
		ms->x = -1;
		while (++ms->x < ms->width)
		{
			if (ms->x < ms->width - 1)
				ft_draw_x(ms);
			if (ms->y < ms->height - 1)
				ft_draw_y(ms);
		}
	}
}
