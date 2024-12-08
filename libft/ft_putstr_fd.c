/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madamou <madamou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 15:06:15 by marvin            #+#    #+#             */
/*   Updated: 2024/12/07 00:10:49 by madamou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	write(fd, s, ft_strlen(s));
}

/*int main(void)
{
	char s[] = "je suis entrain de test";
	int fd = open("test.txt", O_RDWR | O_TRUNC | O_CREAT, 0640);
	ft_putstr_fd(s, fd);
}*/