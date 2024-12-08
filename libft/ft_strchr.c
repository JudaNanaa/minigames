/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madamou <madamou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 02:57:30 by madamou           #+#    #+#             */
/*   Updated: 2024/12/07 00:15:41 by madamou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	int		n;
	char	*ptr;

	ptr = (char *)s;
	i = 0;
	n = ft_strlen(s);
	while (i <= n)
	{
		if (ptr[i] == (char)c)
			return (&ptr[i]);
		i++;
	}
	return (NULL);
}

/*      int main(void)
{
	char chain[] = "oui je test";
	char c = 'i';
	printf("%s\n", ft_strchr(chain, c));
	printf("%s\n", strchr(chain, c));
}*/