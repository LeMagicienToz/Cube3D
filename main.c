/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rperrin <rperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 13:41:24 by muteza            #+#    #+#             */
/*   Updated: 2023/04/15 01:41:44 by rperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

char	*parcing_name(char *str)
{
	int		i;
	char	*res;

	i = 0;
	while (str && str[i])
		i++;
	res = malloc(sizeof(char ) * i + 1);
	if (!res)
		return (NULL);
	res[i] = 0;
	i = 0;
	while (str[i])
	{
		res[i] = str[i];
		i++;
	}
	return (str);
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2)
		return (0);
	parcing_map(argv[1], &data);
	exit(1);
	data.mlx.mlx = mlx_init();
	ray_casting(&data);
	make_img(&data);
	data.mlx.mlx_win = mlx_new_window(data.mlx.mlx, data.mlx.width, data.mlx.height, "Cube 3D");
	data.mlx.img = mlx_new_image(data.mlx.mlx, data.mlx.height, \
			data.mlx.width);
	check_pos(&data);
	mlx_key_hook(data.mlx.mlx_win, hooks_player, &data);
	// mlx_hook(data.mlx.mlx_win, 17, 1L << 0, exit_two, &data);
	mlx_loop(data.mlx.mlx);
}
