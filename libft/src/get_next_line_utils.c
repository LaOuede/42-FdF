/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gle-roux <gle-roux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 10:23:28 by gle-roux          #+#    #+#             */
/*   Updated: 2023/03/30 16:38:46 by gle-roux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/*
  Check a string to find the new line character ('\n')
  Returns 1 if '\n' is found in the string
*/
int	ft_strchr_new_line(char *save)
{
	size_t	i;

	if (!save)
		return (0);
	i = 0;
	while (save[i])
	{
		if (save[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

/*Joins buffer and save*/
char	*ft_strnjoin(char *temp, char *buf)
{
	size_t	i;
	size_t	j;
	size_t	len_temp;
	size_t	len_buf;
	char	*save;

	len_temp = 0;
	while (temp && temp[len_temp])
		len_temp++;
	len_buf = 0;
	while (buf && buf[len_buf])
		len_buf++;
	save = ft_calloc(sizeof * save, len_temp + len_buf + 1);
	if (!save)
		return (NULL);
	i = 0;
	while (temp && len_temp--)
	{
		save[i] = temp[i];
		i++;
	}
	j = 0;
	while (buf && len_buf--)
		save[i++] = buf[j++];
	return (save);
}

/*Free a string if it exists*/
void	*ft_free(char *str1, char *str2)
{
	if (str1)
		free(str1);
	if (str2)
		free(str2);
	return (0);
}
