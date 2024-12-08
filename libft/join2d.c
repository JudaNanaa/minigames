/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join2d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madamou <madamou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 02:50:28 by madamou           #+#    #+#             */
/*   Updated: 2024/12/02 02:51:08 by madamou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	join2d(char **join, char **str1, char **str2)
{
	int	i;
	int	j;

	i = -1;
	j = -1;
	while (str1[++i] != NULL)
	{
		join[++j] = ft_strdup(str1[i]);
		if (join[j] == NULL)
			return (free_2d(join), EXIT_FAILURE);
	}
	i = -1;
	while (str2[++i] != NULL)
	{
		join[++j] = ft_strdup(str2[i]);
		if (join[j] == NULL)
			return (free_2d(join), EXIT_FAILURE);
	}
	join[++j] = NULL;
	return (EXIT_SUCCESS);
}
