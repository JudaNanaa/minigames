/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_string_char_2d.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madamou <madamou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 15:31:48 by madamou           #+#    #+#             */
/*   Updated: 2024/12/08 15:58:12 by madamou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <time.h>

char **add_string_char_2d(char **tab, char *str)
{
	char	**new;
	int		i;

	if (tab == NULL)
		new = malloc(sizeof(char *) * (1 + 1));
	else
		new = malloc(sizeof(char *) * (ft_strlen_2d(tab) + 1 + 1));
	if (!new)
		return (NULL);
	i = 0;
	while (tab && tab[i])
	{
		new[i] = tab[i];
		i++;
	}
	new[i] = str;
	new[++i] = NULL;
	free(tab);
	return (new);
}
