/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_exec.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muteza <muteza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 17:41:20 by muteza            #+#    #+#             */
/*   Updated: 2023/04/14 18:54:54 by muteza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

void	move_back(t_data *data)
{
	mlx_destroy_image(data->mlx.mlx, data->mlx.img);
	data->mlx.img = mlx_xpm_file_to_image(data->mlx.mlx, \
	"src/sprite/black.xpm", &data->mlx.width, &data->mlx.height);
	data->player.pos_y += 64;
	put_img(data);
}

void	move_foward(t_data *data)
{
	mlx_destroy_image(data->mlx.mlx, data->mlx.img);
	data->player.pos_y -= 64;
	put_img(data);
}

void	move_left(t_data *data)
{
	mlx_destroy_image(data->mlx.mlx, data->mlx.img);
	data->player.pos_x -= 64;
	put_img(data);
}

void	move_right(t_data *data)
{
	mlx_destroy_image(data->mlx.mlx, data->mlx.img);
	data->player.pos_x += 64;
	put_img(data);
}
