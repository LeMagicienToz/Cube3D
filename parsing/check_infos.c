/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_infos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rperrin <rperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 16:24:36 by rperrin           #+#    #+#             */
/*   Updated: 2023/06/08 19:05:28 by rperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

void	norm_check_infos(void)
{
}

int	check_line(char *str, int i)
{
	while (str[i])
	{
		if (str[i] != ' ')
			x = 1;
		if (x == 1)
		{
			while (str[i])
			{
				if (str[i] != ' ')
					return (1);
				i++;
			}
		}
		i++;
	}
	return (0);
}

int	check_infos(t_data *data)
{
	int					j;
	int					i;
	int					x;
	const static char	infos[6][6] = {"NO", "SO", "WE", "EA", "F", "C"};

	(norm_check_infos(), j = 0, x = 0);
	while (data->map[j])
	{
		i = 0;
		while (data->map[j][i])
		{
			if (data->map[j][i] != ' ')
			{
				while (infos[x])
				{
					if (strcmp_info_check(infos[x], data->map[j], \
					ft_stlren(infos[x++]), i))
						return (check_line(data->map[j], i));
				}
			}
			i++;
		}
		j++;
	}
	return (0);
}
