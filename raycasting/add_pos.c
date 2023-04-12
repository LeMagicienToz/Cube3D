/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_pos.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muteza <muteza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 12:49:17 by muteza            #+#    #+#             */
/*   Updated: 2023/04/12 14:52:40 by muteza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

void	register_pos(t_data *data, int i, int k)
{
	if (data->map[i][k] == 'N')
	{
		data->player.pos_x = k * 64;
		data->player.pos_y = i * 64;
		printf("pos x = %d\n", data->player.pos_x);
		printf("pos y = %d\n", data->player.pos_y);
		put_img(data);
	}
	else
		printf("ok\n");
}

void	exit_esc(t_data *data)
{
	int	i;

	i = 0;
	mlx_destroy_window(data->mlx.mlx, data->mlx.mlx_win);
	while (data->map[i])
	{
		free(data->map[i++]);
	}
	exit(0);
}

int	hooks_player(int keycode, t_data *data)
{
	// if (keycode == 13)
	// 	move_top(data);
	// if (keycode == 1)
	// 	move_down(data);
	// if (keycode == 2)
	// 	move_right(data);
	// if (keycode == 0)
	// 	move_left(data);
	if (keycode == 53)
		exit_esc(data);
	return (0);

}

void	check_pos(t_data *data)
{
	int	i;
	int	k;

	k = 0;
	i = 0;
	while (data->map[i])
	{
		while (data->map[i][k])
		{
			if (data->map[i][k] == '0' || data->map[i][k] == '1' || \
			data->map[i][k] == 'N' || data->map[i][k] == 'S' || \
			data->map[i][k] == 'E' || data->map[i][k] == 'W')
				register_pos(data, i, k);
			else
				exit(0);
			k++;
		}
		i++;
		k = 0;
	}
}