/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_minimap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raphaelperrin <raphaelperrin@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 22:35:07 by raphaelperr       #+#    #+#             */
/*   Updated: 2023/05/20 17:18:16 by raphaelperr      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

void	norm_mini_map(void)
{
}

void	render_mini_map(t_data *data)
{
	int	i;
	int	j;

	(norm_mini_map(), i = 0, j = 0);
	while (data->map[j])
	{
		while (data->map[j][i])
		{
			if (data->map[j][i])
			{
					
			}
			i++;
		}
		i = 0;
		j++;
	}	
}

void	init_mlx(t_data *data)
{
	data->mlx.mlx = mlx_init();
	data->mlx.width = 640;
	data->mlx.height = 360;
	data->mlx.mlx_win = mlx_new_window(data->mlx.mlx, data->mlx.width, data->mlx.height, "-=- QUOICOUBEH -=-");
	mlx_pixel_put(data->mlx.mlx, data->mlx.mlx_win, 640/2, 360/2, 0xFFFFFF);
	mlx_loop(data->mlx.mlx);
}