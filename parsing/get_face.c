/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_face.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rperrin <rperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 20:11:09 by rperrin           #+#    #+#             */
/*   Updated: 2023/06/08 16:23:17 by rperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

int	get_face(t_data *data)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (data->map[j])
	{
		while (data->map[j][i])
		{
			if (data->map[j][i] == 'N' || data->map[j][i] == 'S'
				|| data->map[j][i] == 'E' || data->map[j][i] == 'W')
			{
				if (data->face)
					return (printf("\n[PARSING ERROR : MULTIPLE FACES]\n"), 1);
				data->face = data->map[j][i];
			}
			i++;
		}
		i = 0;
		j++;
	}
	if (!data->face)
		return (printf("\n[PARSING ERROR : NO FACE]\n"), 1);
	return (0);
}
