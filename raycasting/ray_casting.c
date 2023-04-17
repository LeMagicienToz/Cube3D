/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muteza <muteza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 15:24:31 by muteza            #+#    #+#             */
/*   Updated: 2023/04/17 20:37:16 by muteza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

void	pythagour(t_data *data)
{
	// printf("%f\n", data->raycas.raydir_x);
	// printf("%f\n", data->raycas.raydir_y);
	if (data->raycas.raydir_x == 0)
		data->raycas.delta_dist_x = 1e10;
	else
	{
		data->raycas.delta_dist_x = sqrt(1 + \
		(data->raycas.raydir_y * data->raycas.raydir_y) / \
		(data->raycas.raydir_x * data->raycas.raydir_x));
	}
	if (data->raycas.raydir_y == 0)
		data->raycas.delta_dist_y = 1e10;
	else
	{
		data->raycas.delta_dist_y = sqrt(1 + \
		(data->raycas.raydir_x * data->raycas.raydir_x) / \
		(data->raycas.raydir_y * data->raycas.raydir_y));
	}
}

void	perf_rc(t_data *data)
{
	data->raycas.map_x = data->player.pos_x;
	data->raycas.map_y = data->player.pos_y;
	while (data->map[(int)data->raycas.map_y][(int)data->raycas.map_x] != 1)
	{
		printf("%c\n", data->map[(int)data->raycas.map_y][(int)data->raycas.map_x]);
		if (data->raycas.side_dist_x < data->raycas.side_dist_y)
		{
			data->raycas.side_dist_x += data->raycas.delta_dist_x;
			data->raycas.map_x += data->raycas.stepx;
			data->raycas.side = 0;
			if (data->raycas.stepy > 0)
				data->raycas.side = 1;
		}
		else
		{
			data->raycas.side_dist_y += data->raycas.delta_dist_y;
			data->raycas.map_y += data->raycas.stepy;
			data->raycas.side = 2;
			// printf("END\n");
			if (data->raycas.stepx > 0)
				data->raycas.side = 3;
		}
	}
	exit(1);
	// data->raycas.hit = 1;
}

void	dir_ray(t_data *data)
{
	if (data->raycas.raydir_x < 0)
	{
		data->raycas.stepx = -1;
		data->raycas.side_dist_x = (data->player.pos_x - \
		(int)data->player.pos_x) * data->raycas.delta_dist_x;
	}
	else
	{
		data->raycas.stepx = 1;
		data->raycas.side_dist_x = ((int) data->player.pos_x + 1.0 - \
		data->player.pos_x) * data->raycas.delta_dist_x;
	}
	if (data->raycas.raydir_y < 0)
	{
		data->raycas.stepy = -1;
		data->raycas.side_dist_y = (data->player.pos_y - \
		(int)data->player.pos_y) * data->raycas.delta_dist_y;
	}
	else
	{
		data->raycas.stepy = 1;
		data->raycas.side_dist_y = ((int)data->player.pos_y + 1.0 - \
		data->player.pos_y) * data->raycas.delta_dist_y;
	}
	perf_rc(data);
}

int	ray_casting(t_data *data)
{
	int	x;
	int	w;

	x = 0;
	w = data->mlx.width;
	while (x < w)
	{
		data->raycas.cam_x = 2 * x / (double)w - 1;
		data->raycas.raydir_x = data->raycas.dir_x + \
		data->raycas.plane_x + data->raycas.cam_x;
		data->raycas.raydir_y = data->raycas.dir_y + \
		data->raycas.plane_y + data->raycas.cam_x;
		x++;
		pythagour(data);
		dir_ray(data);
	}
	// check_all_movement(data);
	data->key_code = 0; //check key realease
	return(0);
}
