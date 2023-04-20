/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_exec.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muteza <muteza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 17:41:20 by muteza            #+#    #+#             */
/*   Updated: 2023/04/20 17:19:05 by muteza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

void	move_back(t_data *data)
{
	mlx_clear_window(data->mlx.mlx, data->mlx.mlx_win);
	put_map_to_window(data);
	data->player.pos_y += 5;
	put_img(data);
}

void	move_foward(t_data *data)
{
	mlx_clear_window(data->mlx.mlx, data->mlx.mlx_win);
	put_map_to_window(data);
	data->player.pos_y -= 5;
	put_img(data);
}

void	move_left(t_data *data)
{
	mlx_clear_window(data->mlx.mlx, data->mlx.mlx_win);
	put_map_to_window(data);
	data->player.pos_x -= 5;
	put_img(data);
}

void	move_right(t_data *data)
{
	mlx_clear_window(data->mlx.mlx, data->mlx.mlx_win);
	put_map_to_window(data);
	data->player.pos_x += 5;
	put_img(data);
}
