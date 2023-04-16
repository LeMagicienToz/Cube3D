/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rperrin <rperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 02:43:34 by rperrin           #+#    #+#             */
/*   Updated: 2023/04/16 01:47:26 by rperrin          ###   ########.fr       */
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
	// printf("[%c]", data->map[j + 1][i]);
	// printf("[%c]", data->map[j][i + 1]);
	// printf("[%c]", data->map[j - 1][i]);
	// printf("[%c]\n\n", data->map[j][i - 1]);
	// printf("VALIDE %d\n", ft_strcmp("0NSWE ", &data->map[j + 1][i]));
	// printf("PAS VALIDE %d\n", ft_strcmp("0NSWE ", &data->map[j][i - 1]));
	if (data->map[j + 1][i] && data->map[j - 1][i] && ft_strcmp(\
	"1", &data->map[j + 1][i]) == 0 && ft_strcmp("1", &data->map[j - 1][i]))
	{
		printf("COUCOU\n");
		if (!data->map[j][i + 1] || !data->map[j][i - 1])
			return (1);
		if ((data->map[j][i + 1] && data->map[j][i - 1] ) && ( ft_strcmp("0NSWE "\
		, &data->map[j][i + 1]) && ft_strcmp("0NSWE ", &data->map[j][i - 1]) ))
			return (1);
	}
	return (0);
	// if (data->map[j - 1][i] && ft_strcmp("1", &data->map[j - 1][i]))

	// if (data->map[j][i + 1] && ft_strcmp("0NSWE ", &data->map[j][i + 1]))
	// 	return (1);
	// 	return (1);
	// if (data->map[j][i - 1] && ft_strcmp("0NSWE ", &data->map[j - 1][i]))
	// 	return (1);
	// return (0);
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
			//printf("TEST j = %d i = %d [%c]\n", j, i, data->map[j][i]);
			if (data->map[j][i++] == '0')
			{
				if (check_walls_cut(data, 4, 1))
				{
					printf("PAS VALIDE\n");
				}
			}
		}
		printf("\n");
		i = 0;
		j++;
	}
	return (0);
}
