/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muteza <muteza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 10:43:32 by raphaelperr       #+#    #+#             */
/*   Updated: 2023/04/17 14:25:32 by muteza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

void	init_map(char *myfile, t_data *data)
{
	int	filedesc;
	int	x;

	x = 0;
	filedesc = open(myfile, O_RDONLY);
	if (filedesc == -1)
		return ;
	data->lin = 1;
	while (read(filedesc, &data->c, 1) > 0)
	{
		if (data->c == '\n')
			data->lin++;
		x = 1;
	}
	if (x == 0)
		data->lin = 0;
	data->map = NULL;
	data->map = malloc(sizeof(char *) * (data->lin + 1));
	data->map[data->lin] = NULL;
	if (data->map == NULL)
		exit (EXIT_FAILURE);
	close (filedesc);
}

void	init_map_string(char *myfile, t_data *data)
{
	int	i;
	int	filedesc;

	i = 0;
	filedesc = open(myfile, O_RDONLY);
	while (read(filedesc, &data->c, 1) > 0)
	{
		if (data->c == '\n')
		{
			data->map[i] = malloc(data->col + 1);
			if (data->map[i] == NULL)
				exit(EXIT_FAILURE);
			data->map[i++][data->col] = '\0';
		}
		else
			data->col++;
	}
	data->map[i] = malloc(data->col + 1);
	if (data->map[i] == NULL)
		exit(EXIT_FAILURE);
	data->map[i][data->col] = '\0';
	close(filedesc);
}

void	get_map(char *myfile, t_data *data)
{
	int		filedesc;
	char	c;

	data->i = 0;
	data->j = 0;
	filedesc = open(myfile, O_RDONLY);
	if (filedesc == -1)
		return ;
	while (read(filedesc, &c, 1) > 0)
	{
		if (c == '\n')
		{
			data->j++;
			data->i = 0;
		}
		else
			data->map[data->j][data->i++] = c;
	}
	close(filedesc);
}

void	parcing_map(char *name, t_data *data)
{
	data->lin = 0;
	data->col = 0;
	init_map(name, data);
	init_map_string(name, data);
	get_map(name, data);
	print_map(data->map);
	// printf("===================================\n");
	// printf("%d", check_walls(data));
}
