/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madamou <madamou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 11:42:25 by madamou           #+#    #+#             */
/*   Updated: 2024/12/07 00:14:10 by madamou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char	*ptr;
	long long		check_nmemb;
	long long		check_size;

	check_nmemb = (long long)nmemb;
	check_size = (long long)size;
	if ((nmemb > 4294967295 || size > 4294967295) && check_nmemb < 0
		&& check_size < 0)
		return (NULL);
	if (check_nmemb * check_size < 0)
		return (NULL);
	else
		ptr = malloc(nmemb * size);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, nmemb * size);
	return ((void *)ptr);
}

// int main(void)
// {
// 	if (ft_calloc(3, -5) == NULL)
// 		printf("yes\n");
// 	else
// 		printf("no\n");
// 	if (calloc(3, -5) == NULL)
// 		printf("yes\n");
// 	else
// 		printf("no\n");
// }