/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwenolaleroux <gwenolaleroux@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 09:03:02 by gwenolalero       #+#    #+#             */
/*   Updated: 2023/03/31 13:18:09 by gwenolalero      ###   ########.fr       */
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
	char	*file_ext;

	file_ext = NULL;
	file_ext = ft_strrchr(file, '.');
	if (!file_ext)
		ft_error_args("Usage : ./fdf <map.fdf>\n"
			KYEL"	-> File is invalid / Does not exist\n"KNRM);
	if (ft_strcmp(file_ext, ".fdf") != 0)
		ft_error_args("Usage : ./fdf <map.fdf>\n"
			KYEL"	-> File has an invalid extension\n"KNRM);
	fd = open(file, O_RDONLY);
	if (fd == -1)
		ft_error_args("Usage : ./fdf <map.fdf>\n"
			KYEL"	-> File cannot be opened\n"KNRM);
}
