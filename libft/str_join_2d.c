/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madamou <madamou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 20:02:12 by madamou           #+#    #+#             */
/*   Updated: 2024/12/02 02:53:58 by madamou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*str_join_2d(char **str_2d, char *sep)
{
	char	*str;
	int		i;

	if (str_2d == NULL)
		return (NULL);
	str = NULL;
	i = -1;
	while (str_2d[++i] != NULL)
	{
		if (i != 0)
		{
			str = ft_re_strjoin(str, sep);
			if (str == NULL)
				return (NULL);
		}
		str = ft_re_strjoin(str, str_2d[i]);
		if (str == NULL)
			return (NULL);
	}
	return (str);
}

char	*str_join_2d_and_free(char **str_2d, char *sep)
{
	char	*str;

	if (str_2d == NULL)
		return (NULL);
	str = str_join_2d(str_2d, sep);
	free_2d(str_2d);
	return (str);
}
