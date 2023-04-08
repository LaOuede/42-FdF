/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwenolaleroux <gwenolaleroux@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 08:25:04 by gwenolalero       #+#    #+#             */
/*   Updated: 2023/04/08 11:48:37 by gwenolalero      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

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
	if (ms->mlx)
		mlx_terminate(ms->mlx);
	if (ms->map && ms->map->matrix)
	{
		ft_free_tab_int(ms->map->matrix, (size_t)ms->map->height);
		free(ms->map);
	}
	free(ms);
	if (err_msg)
		ft_error(err_msg, 2);
}
