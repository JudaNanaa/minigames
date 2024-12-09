/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madamou <madamou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 23:02:31 by madamou           #+#    #+#             */
/*   Updated: 2024/12/09 01:49:46 by madamou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bsq.h"

int main(int argc, char **argv)
{
	t_bsq data;

	ft_bzero(&data, sizeof(t_bsq));
	if (argc != 2)
	{
		ft_printf("Error argmuent\n");
		return 1;
	}
	if (parsing_file(&data, argv[1]) == -1)
		return 1;
	data.size = malloc(sizeof(int *) * data.nb_line);
	if (data.size == NULL)
	{
		ft_printf("Error MALLOC\n");
		return 1;
	}
	int i;
	i = 0;
	while (i < data.nb_line)
	{
		data.size[i] = malloc(sizeof(int *) * data.len_line);
		++i;
	}
	if (find_biggest_sqare(&data) == -1)
		return -1;
	replace_chars(&data);
	print_map(&data);
	free_split(data.map);
	return 0;
}