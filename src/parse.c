/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwenolaleroux <gwenolaleroux@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 09:03:02 by gwenolalero       #+#    #+#             */
/*   Updated: 2023/03/31 22:54:36 by gwenolalero      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

/* void	ft_parse_map(t_map_infos map, char *file)
{
	
} */

/*
Checks :
	- if the <map.fdf> is valid / exist,
	- if the extension is .fdf,
	- if the file can be opened.
*/
void	ft_parse_file(char *file)
{
	int		fd;
	char	*check_file;

	check_file = NULL;
	check_file = ft_strrchr(file, '.');
	if (!check_file)
		ft_error_parse("Usage : ./fdf <map.fdf>\n"
			KYEL"	-> File is invalid / Does not exist <-\n"KNRM);
	if (ft_strcmp(check_file, ".fdf") != 0)
		ft_error_parse("Usage : ./fdf <map.fdf>\n"
			KYEL"	-> File has an invalid extension <-\n"KNRM);
	fd = open(file, O_RDONLY);
	if (fd == -1)
		ft_error_parse("Usage : ./fdf <map.fdf>\n"
			KYEL"	-> File cannot be opened <-\n"KNRM);
	check_file = get_next_line(fd);
	if (check_file <= 0)
		ft_error_parse("Usage : ./fdf <map.fdf>\n"
			KYEL"	-> File is empty <-\n"KNRM);
}
