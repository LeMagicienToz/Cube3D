/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muteza <muteza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 15:24:31 by muteza            #+#    #+#             */
/*   Updated: 2023/04/14 18:43:33 by muteza           ###   ########.fr       */
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
	data->raycas.dir_x = -1;
	data->raycas.dir_y = 0;
	data->raycas.plane_x = 0;
	data->raycas.plane_y = 0.66;
	data->raycas.time = 0;
	data->raycas.old_time = 0;
}

int	ray_casting(t_data *data)
{
	int	x;
	int	w;

	x = 0;
	w = data->mlx.width;
	// printf("%d\n %d", data->mlx.width);
	while (x < w)
	{
		data->raycas.cam_x = 2 * x / (double)w - 1;
		data->raycas.raydir_x = data->raycas.dir_x + \
		data->raycas.plane_x + data->raycas.cam_x;
		data->raycas.raydir_y = data->raycas.dir_y + \
		data->raycas.plane_y + data->raycas.cam_x;
		x++;
	}
	check_all_movement(data);
	data->key_code = 0; //check key realease
	return(0);
}
