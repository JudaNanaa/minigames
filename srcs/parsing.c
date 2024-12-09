/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madamou <madamou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 23:05:03 by madamou           #+#    #+#             */
/*   Updated: 2024/12/09 01:26:09 by madamou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bsq.h"
#include <fcntl.h>
#include <stdbool.h>
#include <unistd.h>

int str_is_in_charset(char *str, char *set)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] != set[0] && str[i] != set[1])
			return false;
		++i;
	}
	return true;
}

void free_split_index(char **split, int index)
{
	if (split)
	{
		while (index >= 0)
		{
			free(split[index]);
			--index;
		}
		free(split);
	}
}

char	**read_file_2d_bsq(t_bsq *data, int fd)
{
	char	*temp;
	char	**tab;
	int		nb_lines;

	tab = malloc(sizeof(char *) * (data->nb_line + 1));
	if (tab == NULL)
		return (NULL);
	nb_lines = 0;
	data->len_line = -1;
	tab[data->nb_line] = NULL;
	while (true)
	{
		if (nb_lines > data->nb_line)
			return (free_split(tab), NULL);
		temp = get_next_line(fd);
		if (temp == NULL)
			break;
		if (data->len_line == -1)
			data->len_line = ft_strlen(temp) - 1;
		if (temp[data->len_line] != '\n')
			return (free_split_index(tab, nb_lines - 1), NULL);
		temp[data->len_line] = '\0';
		tab[nb_lines] = temp;
		++nb_lines;
	}
	return (tab);
}

int set_infos(t_bsq *data, char *line)
{
	int i;

	i = 0;
	while (line[i] >= '0' && line[i] <= '9')
	{
		data->nb_line *= 10;
		data->nb_line += (line[i] - '0');
		++i;
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
		return (close(fd), -1);
	}
	if (set_infos(data, line) == -1)
		return (close(fd), -1);
	data->map = read_file_2d_bsq(data, fd);
	close(fd);
	if (data->map == NULL)
	{
		ft_printf("Error map\n");
		return -1;
	}
	return 0;
}
