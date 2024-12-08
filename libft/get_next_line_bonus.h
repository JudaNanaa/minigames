/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madamou <madamou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 15:32:08 by itahri            #+#    #+#             */
/*   Updated: 2024/12/08 01:08:02 by madamou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include "libft.h"
# include <bsd/string.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000000
# endif // !BUFFER_SIZE

int		ft_strlen_gnl(char *str, int cas);
bool	ft_check_if_newline(char *sortie);

char	*get_next_line(int fd);

char	*ft_format_sortie(char *sortie);

#endif // !GET_NEXT_LINE_BONUS
