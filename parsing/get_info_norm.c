/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_info_norm.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raphaelperrin <raphaelperrin@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 21:46:35 by raphaelperr       #+#    #+#             */
/*   Updated: 2023/05/16 21:47:00 by raphaelperr      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

int copy_data_tab_cut(t_data *data, int x, char *res)
{
	static int alloc = 0;
	if (x == 5)
	{
		if (alloc == 0)
			data->ff = (int *) malloc(sizeof(int[3]));
		data->ff[alloc++] = ft_atoi(res);
		free(res);
	}
	else if (x == 6)
	{
		if (alloc == 0)
			data->cc = (int *) malloc(sizeof(int[3]));
		data->cc[alloc++] = ft_atoi(res);
		free(res);
		if (alloc == 3)
			return (1);
	}
	if (alloc == 3)
		alloc = 0;
	return (0);
}

int	copy_data_tab(t_data *data, int x, char *str, int len, int i)
{
	char		*res;
	int			j;

	j = 0;
	res = malloc(len + 1);
	res[len] = 0;
	while (str[i] && len > 0)
	{
		res[j] = str[i];
		i++;
		j++;
		len--;
	}
	if (copy_data_tab_cut(data, x, res) == 1)
		return (1);
	return (0);
}