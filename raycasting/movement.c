/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muteza <muteza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 14:29:10 by muteza            #+#    #+#             */
/*   Updated: 2023/04/12 14:43:52 by muteza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

void	move_top(t_data *data)
{
	data->player.pos_y -= 64;
	mlx_destroy_image(data->mlx.mlx, data->mlx.img);
	put_img(data);
}
