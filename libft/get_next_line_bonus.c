/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madamou <madamou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 15:31:37 by itahri            #+#    #+#             */
/*   Updated: 2024/12/08 21:52:30 by madamou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include "ft_printf/ft_printf.h"
#include "libft.h"
#include <stdbool.h>

char	*ft_buff_to_all(t_gnl *data, char *buff, int nb_read)
{
	char	*str;

	str = malloc(sizeof(char) * (data->len_sortie[data->fd] + nb_read + 1));
	if (!str)
		return (free(data->sortie), NULL);
	str[0] = '\0';
	ft_strlcpy(str, data->sortie, data->len_sortie[data->fd]);
	free(data->sortie);
	ft_strlcpy(&str[data->len_sortie[data->fd]], buff, nb_read);
	data->len_sortie[data->fd] += nb_read;
	return (str);
}

char	*ft_read_file(t_gnl *data, int fd)
{
	int	nb_read;

	data->stach[fd][0] = '\0';
	if (ft_strchr(data->sortie, '\n'))
		return (data->newline = true, data->len = find_nl(data->sortie), data->sortie);
	nb_read = BUFFER_SIZE;
	while (1)
	{
		data->sortie = ft_realloc(data->sortie, BUFFER_SIZE);
		if (data->sortie == NULL)
			return (NULL);
		nb_read = read(fd, &data->sortie[data->len_sortie[fd]], BUFFER_SIZE);
		if (nb_read == -1)
			return (free(data->sortie), NULL);
		if (nb_read == 0)
			return (data->newline = false, data->sortie);
		data->len_sortie[fd] += nb_read;
		data->sortie[data->len_sortie[fd]] = '\0';
		if (ft_strchr(&data->sortie[data->len_sortie[fd] - nb_read], '\n'))
		{
			data->len = data->len_sortie[fd] - nb_read + find_nl(&data->sortie[data->len_sortie[fd] - nb_read]);
			return (data->newline = true, data->sortie);
		}
	}
	data->newline = true;
	return (data->sortie);
}

char	*get_next_line(int fd)
{
	static t_gnl data;

	if (fd < 0)
		return (NULL);
	data.sortie = ft_strdup(data.stach[fd]);
	if (data.sortie == NULL)
		return (data.stach[fd][0] = '\0', data.len_sortie[fd] = 0, NULL);
	data.fd = fd;
	data.sortie = ft_read_file(&data, fd);
	if (data.sortie == NULL)
		return (data.stach[fd][0] = '\0', data.len_sortie[fd] = 0, NULL);
	if (data.newline == true)
	{
		ft_strlcpy(data.stach[fd], &data.sortie[data.len + 1], data.len_sortie[fd] - data.len);
		data.sortie[data.len + 1] = '\0';
		data.len_sortie[fd] -= data.len + 1;
	}
	else
	{
		data.stach[fd][0] = '\0';
		data.len_sortie[fd] = 0;
		if (data.sortie[0] == '\0')
			return (free(data.sortie), NULL);
	}
	return (data.sortie);
}

/*
#include <fcntl.h>

int	main(void)
{
	int		fd;
	char	*line;

	// Ouvrir le fichier en lecture
	fd = open("read_error.txt", O_RDONLY);
	if (fd == -1)
	{
		perror("Error opening file");
		return (1);
	}
	line = get_next_line(fd);
	printf("%s", line);
	free(line);
	line = get_next_line(fd);
	printf("%s", line);
	free(line);
	line = get_next_line(10);
	printf("%s", line);
	free(line);
	close(fd);
	fd = open("read_error.txt", O_RDONLY);
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("[%s]\n", line);
		free(line);
	}
	line = get_next_line(10);
	printf("%s", line);
	free(line);
	return (0);
}*/
