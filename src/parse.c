/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwenolaleroux <gwenolaleroux@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 09:03:02 by gwenolalero       #+#    #+#             */
/*   Updated: 2023/04/06 17:26:07 by gwenolalero      ###   ########.fr       */
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
void	ft_parse_file(char *file)
{
	int		fd;
	char	*check_file;

	check_file = NULL;
	check_file = ft_strrchr(file, '.');
	if (!check_file)
		ft_error("Usage : ./fdf <map.fdf>\n"
			KYEL"	-> File is invalid / Does not exist <-\n"KNRM);
	if (ft_strcmp(check_file, ".fdf") != 0)
		ft_error("Usage : ./fdf <map.fdf>\n"
			KYEL"	-> File has an invalid extension <-\n"KNRM);
/* 	fd = open(file, O_DIRECTORY);
	if (fd)
		exit(EXIT_FAILURE);
	close(fd); */
	fd = open(file, O_RDONLY);
	if (fd == -1)
		ft_error("Usage : ./fdf <map.fdf>\n"
			KYEL"	-> File cannot be opened / Does not exist <-\n"KNRM);
	close(fd);
}
