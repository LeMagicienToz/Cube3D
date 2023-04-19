/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_raycas.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muteza <muteza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 16:03:06 by muteza            #+#    #+#             */
/*   Updated: 2023/04/19 15:01:51 by muteza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

void	make_img(t_data *data)
{
	// data->mlx.width = 1920;
	// data->mlx.height = 1080;
	data->mlx.width = ft_strlen(data->map[0]) * 64;
	data->mlx.height = ft_strlen_y(data->map) * 64;
	data->mlx.img = 0;
}

void	ini_raycas(t_data *data)
{
	data->player.pos_x = 3;
	data->player.pos_y = 2;
	data->raycas.side_dist.x = 0;
	data->raycas.side_dist.y = 0;
	data->raycas.map.y = 0;
	data->raycas.map.x = 0;
	data->raycas.hit = 0;
	data->raycas.dir_x = -1;
	data->raycas.dir_y = 0;
	data->raycas.plane.x = 0;
	data->raycas.plane.y = 0.66;
	data->raycas.time = 0;
	data->raycas.old_time = 0;
}
