/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gle-roux <gle-roux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 09:03:02 by gwenolalero       #+#    #+#             */
/*   Updated: 2023/04/06 11:24:45 by gle-roux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

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
		ft_error("Usage : ./fdf <map.fdf>\n"
			KYEL"	-> File is invalid / Does not exist <-\n"KNRM);
	if (ft_strcmp(check_file, ".fdf") != 0)
		ft_error("Usage : ./fdf <map.fdf>\n"
			KYEL"	-> File has an invalid extension <-\n"KNRM);
	fd = open(file, O_RDONLY);
	if (fd == -1)
		ft_error("Usage : ./fdf <map.fdf>\n"
			KYEL"	-> File cannot be opened / Does not exist <-\n"KNRM);
}
