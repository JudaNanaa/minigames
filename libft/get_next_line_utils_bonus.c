/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madamou <madamou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 16:39:33 by itahri            #+#    #+#             */
/*   Updated: 2024/12/06 23:40:26 by madamou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <stdbool.h>
#include <string.h>

int	ft_strlen_gnl(char *str, int cas)
{
	int	i;

	i = 0;
	if (cas == 1)
	{
		while (str && str[i])
			i++;
	}
	if (cas == 2)
	{
		while (str[i] && str[i] != '\n')
			i++;
		i++;
	}
	return (i);
}

bool	ft_check_if_newline(char *sortie)
{
	int	i;

	i = 0;
	if (!sortie)
		return (false);
	while (sortie[i])
	{
		if (sortie[i] == '\n')
			return (true);
		i++;
	}
	return (false);
}

char	*ft_format_sortie(char *sortie)
{
	int		i;
	char	*str;
	int		j;

	j = 0;
	i = ft_strlen_gnl(sortie, 2);
	str = malloc(sizeof(char) * (i + 1));
	if (!str)
		return (free(sortie), NULL);
	while (j < i)
	{
		str[j] = sortie[j];
		++j;
	}
	str[j] = '\0';
	free(sortie);
	return (str);
}
