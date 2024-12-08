/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madamou <madamou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 15:32:08 by itahri            #+#    #+#             */
/*   Updated: 2024/12/08 20:33:35 by madamou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include "libft.h"
# include <bsd/string.h>
# include <stdio.h>
# include <stdlib.h>
#include <string.h>
# include <unistd.h>
#include <stdbool.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 16384
# endif // !BUFFER_SIZE

typedef struct s_gnl
{
	char	stach[1010][BUFFER_SIZE + 1];
	int fd;
	char *sortie;
	size_t	len_sortie[1010];
	size_t	len;
	bool	newline;
} t_gnl;

char	*ft_strchr(const char *s, int c);
size_t	ft_strlen(const char *str);
bool	ft_check_if_newline(char *sortie);

char	*get_next_line(int fd);

int	ft_strlen_gnl(char *str, int cas);
size_t	find_nl(char *str);
void	ft_format_sortie(t_gnl *data);

#endif // !GET_NEXT_LINE_BONUS
