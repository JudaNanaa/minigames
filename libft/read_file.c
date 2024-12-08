/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madamou <madamou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 20:03:40 by madamou           #+#    #+#             */
/*   Updated: 2024/12/08 15:39:24 by madamou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*read_file(int fd)
{
	char	*temp;
	char	*str;

	str = NULL;
	temp = get_next_line(fd);
	while (temp != NULL)
	{
		str = ft_re_strjoin(str, temp);
		free(temp);
		if (str == NULL)
			return (NULL);
		temp = get_next_line(fd);
	}
	return (str);
}

char	**read_file_2d(int fd)
{
	char	*temp;
	char	**tab;
	char	**buff;

	tab = NULL;
	temp = get_next_line(fd);
	while (temp != NULL)
	{
		buff = add_string_char_2d(tab, temp);
		if (buff == NULL)
			return (free_split(tab), NULL);
		tab = buff;
		temp = get_next_line(fd);
	}
	return (tab);
}
