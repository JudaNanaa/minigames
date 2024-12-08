/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_str2d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madamou <madamou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 01:27:18 by madamou           #+#    #+#             */
/*   Updated: 2024/12/02 02:49:20 by madamou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	sort_str2d(char **str)
{
	int		temp;
	char	*lower;
	int		i;
	int		y;

	y = -1;
	while (str[++y] != NULL)
	{
		i = y;
		temp = i;
		lower = str[i];
		while (str[++i] != NULL)
		{
			if (ft_strcmp(lower, str[i]) > 0)
			{
				temp = i;
				lower = str[i];
			}
		}
		str[temp] = str[y];
		str[y] = lower;
	}
}
