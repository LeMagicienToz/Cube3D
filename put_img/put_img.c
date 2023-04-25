/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_img.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muteza <muteza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 12:30:15 by muteza            #+#    #+#             */
/*   Updated: 2023/04/20 17:37:23 by muteza           ###   ########.fr       */
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

void	nothing(void)
{
	
}

void	put_file_to_img(int x, int y, int i, t_data *data)
{
	if (i == 1)
	{
		data->mlx.img = mlx_xpm_file_to_image(data->mlx.mlx, \
			"utils/sprite/bricksx64.xpm", &data->mlx.width, &data->mlx.height);
		mlx_put_image_to_window(data->mlx.mlx, data->mlx.mlx_win, \
			data->mlx.img, (x * 64), (y * 64));
	}
	if (i == 2)
	{
		data->mlx.img = mlx_xpm_file_to_image(data->mlx.mlx, \
			"utils/sprite/grass.xpm", &data->mlx.width, &data->mlx.height);
		mlx_put_image_to_window(data->mlx.mlx, data->mlx.mlx_win, \
			data->mlx.img, (x * 64), (y * 64));
	}
	if (i == 3)
	{
		data->mlx.img = mlx_xpm_file_to_image(data->mlx.mlx, \
			"utils/sprite/grass.xpm", &data->mlx.width, &data->mlx.height);
		mlx_put_image_to_window(data->mlx.mlx, data->mlx.mlx_win, \
			data->mlx.img, (x * 64), (y * 64));
		data->mlx.img = mlx_xpm_file_to_image(data->mlx.mlx, \
			"utils/sprite/goose.xpm", &data->mlx.width, &data->mlx.height);
		mlx_put_image_to_window(data->mlx.mlx, data->mlx.mlx_win, \
			data->mlx.img, (x * 64), (y * 64));
	}
}

void	put_map_to_window_first(t_data *data)
{
	int	x;
	int	y;
	int	i;

	(nothing(), x = 0, y = 0, i = 0);
	while (data->map[y])
	{
		while (data->map[y][x])
		{
			if (data->map[y][x] == '1')
				put_file_to_img(x, y, 1, data);
			if (data->map[y][x] == '0')
				put_file_to_img(x, y, 2, data);
			if (data->map[y][x] == 'N')
				put_file_to_img(x, y, 3, data);
			x++;
		}
		y++;
		x = 0;
	}
}

void	put_map_to_window(t_data *data)
{
	int	x;
	int	y;
	int	i;

	// printf("dwadawdwa\n");
	(nothing(), x = 0, y = 0, i = 0);
	while (data->map[y])
	{
		while (data->map[y][x])
		{
			if (data->map[y][x] == '1')
				put_file_to_img(x, y, 1, data);
			if (data->map[y][x] == '0')
				put_file_to_img(x, y, 2, data);
			if (data->map[y][x] == 'N')
				put_file_to_img(x, y, 2, data);
			x++;
		}
		y++;
		x = 0;
	}
}
