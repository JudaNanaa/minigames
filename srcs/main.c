/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madamou <madamou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 23:02:31 by madamou           #+#    #+#             */
/*   Updated: 2024/12/08 16:19:40 by madamou          ###   ########.fr       */
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
	find_biggest_sqare(&data);
	replace_chars(&data);
	print_map(&data);
	free_split(data.map);
	return 0;
}