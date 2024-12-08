/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str2d_join.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madamou <madamou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 06:52:03 by madamou           #+#    #+#             */
/*   Updated: 2024/12/03 00:32:30 by madamou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**str2d_join(char **str1, char **str2)
{
	char	**join;

	if (str1 == NULL || str2 == NULL)
		return (NULL);
	if (str2 == NULL && str1 != NULL)
		return (str2 = strdup2d(str1), str2);
	if (str1 == NULL && str2 != NULL)
		return (str1 = strdup2d(str2), str1);
	join = malloc(sizeof(char *)
			* (ft_strlen_2d(str1) + ft_strlen_2d(str2) + 1));
	if (join == NULL)
		return (NULL);
	if (join2d(join, str1, str2) == EXIT_FAILURE)
		return (NULL);
	return (join);
}

char	**re_str2djoin(char **str1, char **str2)
{
	char	**join;

	if (str1 == NULL && str2 == NULL)
		return (NULL);
	if (str2 == NULL && str1 != NULL)
		return (str2 = strdup2d(str1), free_2d(str1), str2);
	if (str1 == NULL && str2 != NULL)
		return (strdup2d(str2));
	join = malloc(sizeof(char *)
			* (ft_strlen_2d(str1) + ft_strlen_2d(str2) + 1));
	if (join == NULL)
		return (free_2d(str1), NULL);
	if (join2d(join, str1, str2) == EXIT_FAILURE)
		return (free_2d(str1), NULL);
	return (free_2d(str1), join);
}
