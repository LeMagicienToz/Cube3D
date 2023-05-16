/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_info.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raphaelperrin <raphaelperrin@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 01:22:06 by raphaelperr       #+#    #+#             */
/*   Updated: 2023/05/16 21:45:10 by raphaelperr      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

void	norm_info(void)
{
}

int	strcmp_info_check(char *check, char *str, int k)
{
	int		i;

	i = 0;
	while (check[i] && k > 0)
	{
		if (str[i] != check[i])
			return (0);
		k--;
		i++;
	}
	return (1);
}

int check_info_3000(t_data *data, int x)
{
	int i;
	int g;
	int	h;

	(norm_info(), h = 0, g = 0, i = 0);
	while (data->map[x][i])
	{
		if (ft_isdigit(data->map[x][i]))
		{
			h++;
			while (data->map[x][i + g] && ft_isdigit((int)data->map[x][i + g]))
				g++;
			if (g > 3 || h > 3)
				return (1);
			if (i + g >= ft_strlen(data->map[x]) - 1)
				break ;
			i = i + g;
			g = 0;
		}
		if (ft_strlen(data->map[x]) - 1 >= i)
			i++;
	}
	if (h != 3)
		return (1);
	return (0);
}

int	check_info(t_data *data)
{
	if (!strcmp_info_check("NO", data->map[0], 2))
		return (1);
	if (!strcmp_info_check("SO", data->map[1], 2))
		return (2);
	if (!strcmp_info_check("WE", data->map[2], 2))
		return (3);
	if (!strcmp_info_check("EA", data->map[3], 2))
		return (4);
	if (ft_strlen(data->map[4]) != 0)
		return (5);
	if (!strcmp_info_check("F", data->map[5], 1) || !ft_isdigit(data->map[5][2]) || check_info_3000(data, 5))
		return (6);
	if (!strcmp_info_check("C", data->map[6], 1) || !ft_isdigit(data->map[6][2]) || check_info_3000(data, 6))
		return (7);
	if (ft_strlen(data->map[7]) != 0)
		return (8);
	return (0);
}

