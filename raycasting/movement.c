/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muteza <muteza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 14:29:10 by muteza            #+#    #+#             */
/*   Updated: 2023/04/20 18:21:32 by muteza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

void	rota_vec(t_vec *vector, double ankle)
{
	double	x;
	double	y;

	x = cos(ankle) * vector->x + -sin(ankle) * vector->y;
	y = sin(ankle) * vector->x + cos(ankle) * vector->y;
	vector->x = x;
	vector->y = y;
}

void	rotation_exec(t_data *data)
{
	if (data->key_code == 6)
		rota_vec(&data->raycas.plane, M_PI / -180 * ROTA);
	if (data->key_code == 7)
		rota_vec(&data->raycas.plane, M_PI / 180 * ROTA);
}

void	check_all_movement(t_data *data)
{
	if (data->key_code == 2)
		move_foward(data);
	if (data->key_code == 1)
		exit_esc(data);
	if (data->key_code == 3)
		move_back(data);
	if (data->key_code == 4)
		move_left(data);
	if (data->key_code == 5)
		move_right(data);
	rotation_exec(data);
	data->key_code = 0;
}

int	key_press_code(int key, t_data *data)
{
	if (key == KEY_ESC)
		data->key_code = 1;
	if (key == KEY_W)
		data->key_code = 2;
	if (key == KEY_S)
		data->key_code = 3;
	if (key == KEY_A)
		data->key_code = 4;
	if (key == KEY_D)
		data->key_code = 5;
	if (key == ROT_R)
		data->key_code = 6;
	if (key == ROT_L)
		data->key_code = 7;
	// check_all_movement(data);
	return (0);
}
