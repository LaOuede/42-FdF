/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gle-roux <gle-roux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 09:03:02 by gwenolalero       #+#    #+#             */
/*   Updated: 2023/04/04 15:42:17 by gle-roux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

/*
Checks if the <map.fdf> is empty.
Gather map infos.
*/
void	ft_parse_map(t_fdf *ms, char *file)
{
	int		fd;
	char	*line;

	fd = open(file, O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		ft_map_width(ms, line);
		ft_map_is_colored(ms, line);
		free(line);
		ms->infos.height++;
	}
	ft_printf("width = %d\n", ms->infos.width);
	ft_printf("height = %d\n", ms->infos.height);
	ft_printf("color = %d\n", ms->infos.color);
	close (fd);
}

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
			KYEL"	-> File cannot be opened / Does not exist <-\n"KNRM);
}
