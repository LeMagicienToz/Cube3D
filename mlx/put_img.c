/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_img.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muteza <muteza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 12:30:15 by muteza            #+#    #+#             */
/*   Updated: 2023/04/12 14:43:38 by muteza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

void	put_img(t_data	*data)
{
	data->mlx.img = mlx_xpm_file_to_image(data->mlx.mlx, \
		"utils/sprite/goose.xpm", &data->mlx.width, &data->mlx.height);
	mlx_put_image_to_window(data->mlx.mlx, data->mlx.mlx_win, \
		data->mlx.img, data->player.pos_x, data->player.pos_y);
}
