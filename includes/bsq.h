/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madamou <madamou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 23:01:40 by madamou           #+#    #+#             */
/*   Updated: 2024/12/09 01:22:28 by madamou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
#define BSQ_H

#include "../libft/libft.h"

typedef enum s_chars
{
	EMPTY,
	OBSTACLE,
	FULL,
}t_chars;

typedef struct s_vec
{
	long x;
	long y;
}t_vec;

typedef struct s_bsq
{
	int nb_line;
	char chars[3];
	char **map;
	int **size;
	int len_line;
	t_vec index;
	// int size;
	bool increment;
} t_bsq;

int parsing_file(t_bsq *data, char *file);

int find_biggest_sqare(t_bsq *data);
void replace_chars(t_bsq *data);
void print_map(t_bsq *data);

#endif