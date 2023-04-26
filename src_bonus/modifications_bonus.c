/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modifications_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwenolaleroux <gwenolaleroux@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 12:24:53 by gle-roux          #+#    #+#             */
/*   Updated: 2023/04/26 16:17:10 by gwenolalero      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf_bonus.h"

void	ft_colorscheme(t_fdf *ms)
{
	if (ms->cam->colors == standard)
		ft_standard(ms);
	else if (ms->cam->colors == icewindale)
		ft_icewindale(ms);
	else if (ms->cam->colors == phandelver)
		ft_phandelver(ms);
	else if (ms->cam->colors == strahd)
		ft_strahd(ms);
	else if (ms->cam->colors == avernus)
		ft_avernus(ms);
	else if (ms->cam->colors == rainbow)
		ft_secret_colors(ms);
}

void	ft_translation(t_fdf *ms)
{
	ms->coord->proj_sx += ms->cam->x_offset;
	ms->coord->proj_sy += ms->cam->y_offset;
	ms->coord->proj_ex += ms->cam->x_offset;
	ms->coord->proj_ey += ms->cam->y_offset;
}

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

void	ft_rotation(t_fdf *ms)
{
	ft_rotation_x(ms);
	ft_rotation_y(ms);
	ft_rotation_z(ms);
}
