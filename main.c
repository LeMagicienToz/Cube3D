/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muteza <muteza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 13:41:24 by muteza            #+#    #+#             */
/*   Updated: 2023/04/12 11:09:35 by muteza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

char	*parcing_name(char *str)
{
	int		i;
	char	*res;

	i = 0;
	while (str[i])
		i++;
	res = malloc(sizeof(char ) * i + 1);
	return (str);
}

int	main(int argc, char **argv)
{
	int		fd;
	char	*name;
	t_data	data;

	if (argc != 2)
		return (0);
	name = parcing_name(argv[1]);
	fd = open(name, O_RDONLY);
	parcing_map(fd, &data);
	data.mlx.mlx = mlx_init();
	ray_casting(&data);
	make_img(&data);
	data.mlx.mlx_win = mlx_new_window(data.mlx.mlx, data.mlx.width, \
			data.mlx.height, "Cube 3D");
	data.mlx.img = mlx_new_image(data.mlx.mlx, data.mlx.height, \
			data.mlx.width);
	mlx_loop(data.mlx.mlx);
}
