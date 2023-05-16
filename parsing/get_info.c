/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raphaelperrin <raphaelperrin@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 13:54:24 by rperrin           #+#    #+#             */
/*   Updated: 2023/05/16 21:46:56 by raphaelperr      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

int	strcmp_info(char *check, char *str, int k)
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

char	*copy_data(char *str)
{
	int		i;
	int		j;
	char	*res;

	res = malloc(ft_strlen(str) - 2);
	res[ft_strlen(str) - 3] = 0;
	i = 3; 
	j = 0;
	while (str[i])
		res[j++] = str[i++];
	return (res);
}

int	data_to_tab(t_data *data, char *str, int x)
{
	int	len;
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] && ft_isdigit(str[i]))
		{
			len = 0;
			while (str[i] && ft_isdigit(str[i]) && str[i] != ',')
			{
				i++;
				len++;
			}
			if (copy_data_tab(data, x, str, len, i - len) == 1)
				return (1);
		}
		if (str[i] != '\0')
			i++;
	}
	return (0);
}


int	get_data(t_data *data, int x, char *str)
{
	if (x == 1)
		data->no = copy_data(str);
	else if (x == 2)
		data->so = copy_data(str);
	else if (x == 3)
		data->we = copy_data(str);
	else if (x == 4)
		data->ea = copy_data(str);
	else if (x == 5)
		data_to_tab(data, str, x);
	else if (x == 6)
		if (data_to_tab(data, str, x) == 1)
			return (1);
	return (0);
}

void	get_info(t_data *data)
{
	int	j;

	j = 0;
	while (data->map[j])
	{
		if (strcmp_info("NO ", data->map[j], 2))
			get_data(data, 1, data->map[j]);
		else if (strcmp_info("SO ", data->map[j], 2))
			get_data(data, 2, data->map[j]);
		else if (strcmp_info("WE ", data->map[j], 2))
			get_data(data, 3, data->map[j]);
		else if (strcmp_info("EA ", data->map[j], 2))
			get_data(data, 4, data->map[j]);
		else if (strcmp_info("F ", data->map[j], 1))
			get_data(data, 5, data->map[j]);
		else if (strcmp_info("C ", data->map[j], 1))
			if (get_data(data, 6, data->map[j]) == 1)
				return ;
		j++;
	}
}
