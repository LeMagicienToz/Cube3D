/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_info.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raphaelperrin <raphaelperrin@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 23:34:57 by raphaelperr       #+#    #+#             */
/*   Updated: 2023/05/16 01:17:52 by raphaelperr      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

int		realloc_get_len(t_data *data, int i, int j)
{
	int		len;

	len = 0;
	while (data->map[j])
	{
		len++;
		while (data->map[j][i])
		{
			i++;
		}
		i = 0;
		j++;
	}
	return (len);	
}

void	free_map(char **map)
{
	int		i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void	realloc_map(t_data *data, int i, int j)
{
	char 	**res;
	int		k;

	k = 0;
	res = malloc(sizeof(char *) * (data->lin + 1));
	res[data->lin] = NULL;
	while (data->map[j])
	{
		res[k] = malloc(sizeof(char) * (ft_strlen(data->map[j]) + 1));
		res[k][ft_strlen(data->map[j])] = '\0';
		while (data->map[j][i])
		{
			res[k][i] = data->map[j][i];
			i++;
		}
		k++;
		i = 0;
		j++;
	}
	free_map(data->map);
	data->map = res;
}

void	set_data_lin(t_data *data)
{
	data->lin = 0;
	while (data->map[data->lin])
		data->lin++;
}

void	remove_info(t_data *data)
{
	data->lin = realloc_get_len(data, 0, 8);
	realloc_map(data, 0, 8);
	set_data_lin(data);
}