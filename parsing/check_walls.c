/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_walls.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raphaelperrin <raphaelperrin@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 02:43:34 by rperrin           #+#    #+#             */
/*   Updated: 2023/05/16 21:43:09 by raphaelperr      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

void	norm_walls(void)
{
}

int	get_last_x(t_data *data, int i, int j)
{
	int		x;

	while (data->map[j][i])
	{
		if (data->map[j][i] == 'X')
			x = i;
		i++;
	}
	return (x);
}

int	check_walls_3000(t_data *data, int i, int j)
{
	while (data->map[j])
	{
		while (data->map[j][i])
		{
			if (data->map[j][i] == 'X')
			{
				if (j == 0 || i == 0 || i == ft_strlen(data->map[j]) - 1 || j == data->col - 1)
					return (1);
				if (!ft_strchr("X1", data->map[j - 1][i]) || !ft_strchr("X1", data->map[j][i + 1]) \
				|| !ft_strchr("X1", data->map[j + 1][i]) || !ft_strchr("X1", data->map[j][i - 1]))
					return (2);
			}
			i++;
		}
		i = 0;
		j++;
	}
	return (0);
}

void	check_walls_cut(t_data *data, int i, int j)
{
	data->map[j][i] = 'X';
	if (j == 0 || i == 0 || i == ft_strlen(data->map[j]) - 1 || j == data->col - 1)
		return ;
	if (data->map[j][i + 1] && '0' == data->map[j][i + 1])
	{
		data->map[j][i + 1] = 'X';
		check_walls_cut(data, i + 1, j);
	}
	if (data->map[j][i - 1] && '0' == data->map[j][i - 1])
	{	
		data->map[j][i - 1] = 'X';
		check_walls_cut(data, i - 1, j);
	}
	if (data->map[j - 1][i] && '0' == data->map[j - 1][i])
	{
		data->map[j - 1][i] = 'X';
		check_walls_cut(data, i, j - 1);
	}
	if (data->map[j + 1][i] && '0' == data->map[j + 1][i])
	{
		data->map[j + 1][i] = 'X';
		check_walls_cut(data, i, j + 1);
	}
}

int	check_walls(t_data	*data)
{
	int		i;
	int		j;
	int		k;

	(norm_walls(), i = 0, k = 0, j = 0);
	while (data->map[j])
	{
		while (data->map[j][i])
		{
			if (ft_strncmp("NEOS", data->map[j][i]))
			{
				data->map[j][i] = 'X';
				check_walls_cut(data, i, j);
				k = check_walls_3000(data, 0, 0);
				if (k > 0)
					return (k);
			}
			i++;
		}
		i = 0;
		j++;
	}
	return (0);
}
