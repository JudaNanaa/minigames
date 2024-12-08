/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madamou <madamou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 00:17:41 by madamou           #+#    #+#             */
/*   Updated: 2024/12/06 23:51:01 by madamou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_min(size_t size, size_t result)
{
	if (size <= result)
		return (size);
	return (result);
}

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	result;

	i = 0;
	while (dst[i])
		i++;
	result = i;
	j = 0;
	while (src[j] && i < size - 1 && size > 0)
		dst[i++] = src[j++];
	dst[i] = '\0';
	return (ft_strlen(src) + ft_min(size, result));
}

// int main(void)
// {
// 	char dest[300] = "a";
// 	// char src[] = "Salut";
// 	printf("%ld\n", strlcat(dest, "lorem ipsum dolor sit amet", 2));
// 	printf("%s\n", dest);
// 	char dest1[300] = "a";
// 	// char src1[] = "Salut";
// 	printf("%ld\n", ft_strlcat(dest1, "lorem ipsum dolor sit amet", 2));
// 	printf("%s\n", dest1);
// }