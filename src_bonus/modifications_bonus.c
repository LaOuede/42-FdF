/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modifications_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gle-roux <gle-roux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 12:24:53 by gle-roux          #+#    #+#             */
/*   Updated: 2023/04/25 15:20:32 by gle-roux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf_bonus.h"

void	ft_translation(t_fdf *ms)
{
	ms->coord->proj_sx += ms->cam->x_offset;
	ms->coord->proj_sy += ms->cam->y_offset;
	ms->coord->proj_ex += ms->cam->x_offset;
	ms->coord->proj_ey += ms->cam->y_offset;
}

/* This implementation sets the projection angle to 45 degrees,
which is equivalent to pi/4 radians. The function then calculates
the cosine and sine of the angle, as before. The projected coordinates
are then calculated using either the formula for isometric or oblique
projection, depending on the value of the projection_type parameter.
Note that this implementation assumes that the projection is in the direction
of the positive x-axis for the oblique projection. If you need to
support different projection directions, you'll need to modify
the calculation accordingly. */
void	ft_projection(t_fdf *ms)
{
	if (ms->cam->projection == isometric_view)
		ft_isometric_view(ms);
	else if (ms->cam->projection == top_view)
		ft_top_view(ms);
	else if (ms->cam->projection == oblique_view)
		ft_oblique_view(ms);
	else if (ms->cam->projection == width_side_view)
		ft_width_side_view(ms);
	else if (ms->cam->projection == height_side_view)
		ft_height_side_view(ms);
}

void	ft_colorscheme(t_fdf *ms)
{
	if (ms->cam->colors == standard)
		ft_standard(ms);
	if (ms->cam->colors == icewindale)
		ft_icewindale(ms);
	else if (ms->cam->colors == phandelver)
		ft_phandelver(ms);
	else if (ms->cam->colors == strahd)
		ft_strahd(ms);
	else if (ms->cam->colors == avernus)
		ft_avernus(ms);
}
