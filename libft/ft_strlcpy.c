/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madamou <madamou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 23:53:14 by madamou           #+#    #+#             */
/*   Updated: 2024/12/06 23:50:51 by madamou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	if (size == 0)
		return (ft_strlen(src));
	i = 0;
	while (src[i] && i < size - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (ft_strlen(src));
}

// int main(void)
// {
// 	char dest[] = "a";
// 	// char src[] = "salut";
// 	printf("%ld\n", strlcpy(dest, "lorem ipsum dolor sit amet", 1));
// 	printf("%s\n", dest);
// 	char dest1[] = "a";
// 	// char src1[] = "salut";
// 	printf("%ld\n", ft_strlcpy(dest1, "lorem ipsum dolor sit amet", 1));
// 	printf("%s\n", dest1);
// }