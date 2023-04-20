/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muteza <muteza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 15:24:31 by muteza            #+#    #+#             */
/*   Updated: 2023/04/20 16:24:13 by muteza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

void	calc_wall(t_data *data)
{
	int			height;
	int			h;

	height = data->mlx.height;
	data->raycas.dist_perp = data->raycas.side_dist.x - \
	data->raycas.delta_dist.x;
	if (data->raycas.side >= 2)
	{
		data->raycas.dist_perp = data->raycas.side_dist.y - \
		data->raycas.delta_dist.y;
	}
	h = height / data->raycas.dist_perp;
	data->raycas.h_bot = (h / 2) + (height / 2);
	data->raycas.h_top = (-h / 2) + (height / 2);
}

void	pythagour(t_data *data)
{
	if (data->raycas.ray_dir.x == 0)
		data->raycas.delta_dist.x = 1e10;
	else
		data->raycas.delta_dist.x = fabs(1 / data->raycas.ray_dir.x);
	if (data->raycas.ray_dir.y == 0)
		data->raycas.delta_dist.y = 1e10;
	else
		data->raycas.delta_dist.x = fabs(1 / data->raycas.ray_dir.y);
	dir_ray(data);
}

void	perf_rc(t_data *data)
{
	data->raycas.map.x = data->player.pos_x;
	data->raycas.map.y = data->player.pos_y;
	while (data->map[(int)data->raycas.map.y][(int)data->raycas.map.x] != '1')
	{
		// printf("%c\n", data->map[(int)data->raycas.map.y][(int)data->raycas.map.x]);
		if (data->raycas.side_dist.x < data->raycas.side_dist.y)
		{
			data->raycas.side_dist.x += data->raycas.delta_dist.x;
			data->raycas.map.x += data->raycas.stepx;
			data->raycas.side = 0;
			if (data->raycas.stepx > 0)
				data->raycas.side = 1;
		}
		else
		{
			data->raycas.side_dist.y += data->raycas.delta_dist.y;
			data->raycas.map.y += data->raycas.stepy;
			data->raycas.side = 2;
			if (data->raycas.stepy > 0)
				data->raycas.side = 3;
		}
	}
	calc_wall(data);
	// data->raycas.map.x = 0;
	// data->raycas.map.y = 0;
}

void	dir_ray(t_data *data)
{
	if (data->raycas.ray_dir.x < 0)
	{
		data->raycas.stepx = -1;
		data->raycas.side_dist.x = (data->player.pos_x - \
		(int)data->player.pos_x) * data->raycas.delta_dist.x;
	}
	else
	{
		data->raycas.stepx = 1;
		data->raycas.side_dist.x = ((int) data->player.pos_x + 1.0 - \
		data->player.pos_x) * data->raycas.delta_dist.x;
	}
	if (data->raycas.ray_dir.y < 0)
	{
		data->raycas.stepy = -1;
		data->raycas.side_dist.y = (data->player.pos_y - \
		(int)data->player.pos_y) * data->raycas.delta_dist.y;
	}
	else
	{
		data->raycas.stepy = 1;
		data->raycas.side_dist.y = ((int)data->player.pos_y + 1.0 - \
		data->player.pos_y) * data->raycas.delta_dist.y;
	}
	perf_rc(data);
}

int	ray_casting(t_data *data)
{
	int	x;
	int	w;

	x = 0;
	w = data->mlx.width;
	// while (x < w)
	// {
	// 	data->raycas.cam_x = 2 * x / (double)w - 1;
	// 	data->raycas.ray_dir.x = data->raycas.dir_x + \
	// 	data->raycas.plane.x * data->raycas.cam_x;
	// 	data->raycas.ray_dir.y = data->raycas.dir_y + \
	// 	data->raycas.plane.y * data->raycas.cam_x;
	// 	pythagour(data);
	// 	x++;
	// }
	// check_all_movement(data);
	// data->key_code = 0; //check key realease
	hooks_player(data->key_code, data);
	return(0);
}
