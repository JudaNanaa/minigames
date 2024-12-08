/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madamou <madamou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 23:05:03 by madamou           #+#    #+#             */
/*   Updated: 2024/12/08 00:36:49 by madamou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bsq.h"
#include <fcntl.h>
#include <stdbool.h>

int set_infos(t_bsq *data, char *line)
{
	int i;

	i = 0;
	while (line[i] >= '0' && line[i] <= '9')
	{
		data->nb_line *= 10;
		data->nb_line += (line[i] - '0');
		i++;
	}
	if (data->nb_line == 0 || ft_strlen(&line[i]) != 4)
	{
		free(line);
		return -1;
	}
	data->chars[EMPTY] = line[i++];
	data->chars[OBSTACLE] = line[i++];
	data->chars[FULL] = line[i];
	free(line);
	return 0;
}

int check_chars(char *line, char *chars)
{
	int i;
	int length_line;
	int row;

	i = 0;
	row = 0;
	length_line = -1;
	while (line[i])
	{
		if (line[i] == '\n')
		{
			if (length_line == -1)
				length_line = row;
			else if (length_line != row)
			{
				ft_printf("Error not sqare\n", line[i]);
				return -1;
			}
			row = 0;
		}
		if (ft_is_in_charset(line[i], chars) == false && line[i] != '\n')
		{
			ft_printf("Error bad char '%c'\n", line[i]);
			return -1;
		}
		if (line[i] != '\n')
			row++;
		i++;
	}
	return length_line;
}

int parsing_file(t_bsq *data, char *file)
{
	int fd;
	char *line;

	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		ft_printf("Error open file\n");
		return -1;
	}
	line = get_next_line(fd);
	if (line == NULL)
	{
		ft_printf("Error file empty\n");
		return -1;
	}
	if (set_infos(data, line) == -1)
		return -1;
	line = read_file(fd);
	if (line == NULL)
	{
		ft_printf("Error malloc\n");
		return -1;
	}
	data->len_line = check_chars(line, data->chars);
	if (data->len_line == -1)
	{
		free(line);
		return -1;
	}
	data->map = ft_split(line, "\n");
	free(line);
	if (data->map == NULL)
	{
		ft_printf("Error malloc\n");
		return -1;
	}
	if (ft_strlen_2d(data->map) != data->nb_line)
	{
		ft_printf("Error nb_line file\n");
		free_split(data->map);
		return -1;
	}
	return 0;
}
