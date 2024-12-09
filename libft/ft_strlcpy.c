/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madamou <madamou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 23:53:14 by madamou           #+#    #+#             */
/*   Updated: 2024/12/08 21:51:39 by madamou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	*intdest;
	size_t	*intsrc;
	size_t	len_int;
	size_t	i;

	i = 0;
	if (src)
	{
		intdest = (size_t *)dest;
		intsrc = (size_t *)src;
		len_int = size / sizeof(size_t);
		while (i < len_int)
		{
			intdest[i] = intsrc[i];
			i++;
		}
		i *= sizeof(size_t);
		while (i < size && src[i])
		{
			dest[i] = src[i];
			i++;
		}
	}
	return (dest[i] = '\0', i);
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