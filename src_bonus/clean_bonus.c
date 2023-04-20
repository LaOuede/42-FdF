/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gle-roux <gle-roux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 08:25:04 by gwenolalero       #+#    #+#             */
/*   Updated: 2023/04/20 13:46:18 by gle-roux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf_bonus.h"

/*
This function :
	- return an error message to the user,
	- close fd if necessary.
*/
void	ft_error(char *err_msg, int fd)
{
	if (err_msg)
		write(STDERR_FILENO, err_msg, ft_strlen(err_msg));
	if (fd)
		close (fd);
	exit(EXIT_FAILURE);
}

/*
This function :
	- call mlx_terminate,
	- free the memory that has been allocated,
	- call ft_error to return a message to the user.
*/
void	ft_clean_up(t_fdf *ms, char *err_msg)
{
	if (ms)
	{
		if (ms->mlx)
			mlx_terminate(ms->mlx);
		if (ms->matrix)
			ft_free_tab_int((int**)ms->matrix, (size_t)ms->height);
		if (ms->cam)
			free(ms->cam);
		if (ms->algo)
			free(ms->algo);
		if (ms->coord)
			free(ms->coord);
		if (ms->menu)
			free(ms->menu);
		free(ms);
	}
	if (err_msg)
		ft_error(err_msg, 2);
}