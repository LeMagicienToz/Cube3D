/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muteza <muteza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 02:43:34 by rperrin           #+#    #+#             */
/*   Updated: 2023/04/17 14:04:26 by muteza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

void	norm()
{
}

int	ft_strcmp(char *check, char *str)
{
	int		i;
	int		j;

	(norm(), i = 0, j = 0);
	while (check[j])
	{
		while (str[i])
		{
			if (str[i++] == check[j])
				return (1);
		}
		i = 0;
		j++;
	}
	return (0);
}

int	check_walls_cut(t_data *data, int i, int j)
{
	if ('0' == data->map[j][i + 1])
	{
		data->map[j][i + 1] = 'X';
		check_walls_cut(data, i + 1, j);
	}
	if ('0' == data->map[j][i - 1])
	{
		data->map[j][i - 1] = 'X';
		check_walls_cut(data, i - 1, j);
	}
	if ('0' == data->map[j - 1][i])
	{
		data->map[j - 1][i] = 'X';
		check_walls_cut(data, i, j - 1);
	}
	if ('0' == data->map[j + 1][i])
	{
		data->map[j + 1][i] = 'X';
		check_walls_cut(data, i, j + 1);
	}
	return (0);
}

int	check_walls(t_data	*data)
{
	int		i;
	int		j;
	int		k;

	(norm(), i = 0, k = 0, j = 0);
	while (data->map[j])
	{
		while (data->map[j][i])
		{
			if (data->map[j][i] == 'N')
			{
				printf("coucou [%c]\n\n", data->map[j][i]);
				check_walls_cut(data, i, j);
				// check_walls_3000(data, i, j);
				print_map(data->map);
			}
			i++;
		}
		printf("\n");
		i = 0;
		j++;
	}
	return (0);
}
