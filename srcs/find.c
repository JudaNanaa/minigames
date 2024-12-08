/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madamou <madamou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 23:39:06 by madamou           #+#    #+#             */
/*   Updated: 2024/12/08 14:23:35 by madamou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bsq.h"
#include <stdbool.h>

long get_size_sqare(t_bsq *data, long x, long y, long size)
{
	long save_x;
	long save_y;

	if (data->nb_line < y + size)
		return size;
	if (data->len_line < x + size)
		return size;
	save_x = x;
	save_y = y;
	while (y < save_y + size)
	{
		x = save_x;
		while (x < save_x + size)
		{
			if (data->map[y][x] != data->chars[EMPTY])
				return size;
			x++;
		}
		y++;
	}
	return get_size_sqare(data, save_x, save_y, size + 1);
}

void replace_chars(t_bsq *data)
{
	long x;
	long y;

	y = data->index.y;
	while (y < data->index.y + data->size)
	{
		x = data->index.x;
		while (x < data->index.x + data->size)
		{
			data->map[y][x] = data->chars[FULL];
			x++;
		}
		y++;
	}
}

void print_map(t_bsq *data)
{
	long i;

	i = 0;
	while (data->map[i])
	{
		ft_printf("%s\n", data->map[i]);
		i++;
	}
}

void find_biggest_sqare(t_bsq *data)
{
	long y;
	long x;
	long size;

	y = 0;
	while (y < data->nb_line - data->size)
	{
		x = 0;
		while (x < data->len_line - data->size)
		{
			if (data->map[y][x] == data->chars[EMPTY])
			{
				size = get_size_sqare(data, x, y, data->size);
				if (size > data->size)
				{
					data->size = size;
					data->index.x = x;
					data->index.y = y;
				}
			}
			x++;
		}
		y++;
	}
}
