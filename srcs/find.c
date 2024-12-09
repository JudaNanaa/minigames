/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madamou <madamou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 23:39:06 by madamou           #+#    #+#             */
/*   Updated: 2024/12/09 01:27:26 by madamou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bsq.h"
#include <stdbool.h>
#include <stdio.h>
#include <unistd.h>

void find_size(t_bsq *data, long x, long y)
{
	int min;

	if (x == 0 || y == 0)
		data->size[y][x] = 1;
	else
	{
		if (data->size[y][x - 1] < data->size[y - 1][x])
			min = data->size[y][x - 1];
		else
			min = data->size[y - 1][x];
		if (min < data->size[y - 1][x - 1])
			min += 1;
		else
		 	min = data->size[y - 1][x - 1] + 1;
		if (min > data->size[data->index.y][data->index.x])
		{
			data->index.x = x;
			data->index.y = y;
		}
		data->size[y][x] = min;
	}
}

void replace_chars(t_bsq *data)
{
	long x;
	long y;
	int size;
	
	size = data->size[data->index.y][data->index.x];
	y = data->index.y;
	while (y > data->index.y - size)
	{
		x = data->index.x;
		while (x > data->index.x - size)
		{
			data->map[y][x] = data->chars[FULL];
			--x;
		}
		--y;
	}
}

void print_map(t_bsq *data)
{
	long i;

	i = 0;
	while (data->map[i])
	{
		write(STDOUT_FILENO, data->map[i], data->len_line);
		write(STDOUT_FILENO, "\n", 1);
		++i;
	}
}

int find_biggest_sqare(t_bsq *data)
{
	long y;
	long x;

	y = 0;
	while (y < data->nb_line)
	{
		x = 0;
		while (x < data->len_line)
		{
			if (data->map[y][x] == data->chars[OBSTACLE])
				data->size[y][x] = 0;
			else if (data->map[y][x] == data->chars[EMPTY])
				find_size(data, x, y);
			else
			 	return ft_dprintf(2, "Error map\n"), -1;
			++x;
		}
		++y;
	}
	return 0;
}
