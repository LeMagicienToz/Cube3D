/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muteza <muteza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 15:24:31 by muteza            #+#    #+#             */
/*   Updated: 2023/04/12 10:58:03 by muteza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

void	make_img(t_data *data)
{
	data->mlx.width = ft_strlen(data->map[0]) * 64;
	data->mlx.height = ft_strlen_y(data->map) * 64;
	data->mlx.img = 0;
}

void	ray_casting(t_data *data)
{
	(void)data;
}
