/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_all.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rperrin <rperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 14:37:44 by raphaelperr       #+#    #+#             */
/*   Updated: 2023/06/08 19:01:29 by rperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

void	check_walls_end(t_data *data)
{
	int		j;
	int		i;

	j = 0;
	i = 0;
	while (data->map[j])
	{
		while (data->map[j][i])
		{
			if (data->map[j][i] == 'X')
				data->map[j][i] = '0';
			i++;
		}
		i = 0;
		j++;
	}
}

int	make_all_test(t_data *data, int argc, char **argv)
{
	if (check_args(argc, argv))
		return (printf("\n[PARSING ERROR : CHECK ARGS]\n"), 1);
	init_map(argv[1], data);
	if (check_info(data))
		return (printf("\n[PARSING ERROR : CHECK INFO]\n"), 1);
	get_info(data);
	remove_info(data);
	if (get_face(data))
		return (1);
	if (check_walls(data))
		return (printf("\n[PARSING ERROR : CHECK WALLS]\n"), 1);
	check_walls_end(data);
	return (0);
}