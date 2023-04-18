/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwenolaleroux <gwenolaleroux@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 09:03:02 by gwenolalero       #+#    #+#             */
/*   Updated: 2023/04/10 09:01:43 by gwenolalero      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

/*
Checks :
	- if the <map.fdf> is valid / exist,
	- if the extension is .fdf,
	- if .fdf is a file and not a directory,
	- if the file can be opened.
*/
void	ft_parse_file(t_fdf *ms, char *file)
{
	int		fd;
	char	*check_file;

	check_file = NULL;
	check_file = ft_strrchr(file, '.');
	if (!check_file)
		ft_clean_up(ms, "Usage : ./fdf <map.fdf>\n"
			KYEL"	-> File is invalid <-\n"KNRM);
	if (ft_strcmp(check_file, ".fdf") != 0)
		ft_clean_up(ms, "Usage : ./fdf <map.fdf>\n"
			KYEL"	-> File has an invalid extension <-\n"KNRM);
	fd = open(file, O_RDONLY);
	if (fd == -1)
		ft_clean_up(ms, "Usage : ./fdf <map.fdf>\n"
			KYEL"	-> File can't be opened OR File doesn't exist <-\n"KNRM);
	close(fd);
}
