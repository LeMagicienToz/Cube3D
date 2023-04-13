/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rperrin <rperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 14:34:26 by muteza            #+#    #+#             */
/*   Updated: 2023/04/13 02:57:53 by rperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

void	getlenmap(int fd, t_data *data)
{
	int		r;
	char	c;

	r = 1;
	data->u.len = 0;
	data->u.line = 0;
	data->u.col = 0;
	while (r > 0)
	{
		r = read(fd, &c, 1);
		if (r == -1)
		{
			data->error = 10;
			return ;
		}
		if (c == '\n')
			data->u.line++;
		data->u.len++;
		if (data->u.len == 1)
			data->u.line++;
	}
	data->u.col = data->u.len / data->u.line;
	close (fd);
}

void	copymap(int fd, t_data *data)
{
	char	c;
	int		r;

	r = 1;
	while (r > 0)
	{
		r = read(fd, &c, 1);
		data->map[data->u.j][data->u.i] = c;
		if (c == '\n')
		{
			data->u.i = 0;
			data->u.j++;
		}
		if (c != '\0')
			data->u.i++;
	}
	close (fd);
}

void	initmap(char	*name, t_data *data)
{
	int		r;
	int		fd;

	r = 1;
	data->u.j = 0;
	data->u.i = 0;
	fd = open(name, O_RDONLY);
	getlenmap(fd, data);
	printf("data->u.line %d data->u.col %d data->u.len %d\n", data->u.line, data->u.len, data->u.col);
	if (data->error == 10)
		printf("bug init map\n");
	fd = open(name, O_RDONLY);
	data->map = malloc(sizeof(char *) * (data->u.line + 1));
	if (!data->map)
		return ;
	data->map[data->u.line] = NULL;
	while (data->map[data->u.j])
	{
		data->map[data->u.j] = malloc(data->u.col + 1);
		if (!data->map[data->u.j])
			return ;
		data->map[data->u.j++][data->u.col] = 0;
	}
	data->u.j = 0;
	copymap(fd, data);
}


void	print_map(char **str)
{
	int		i;

	i = 0;
	if (str == NULL)
	{
		printf("ERROR NO MAP !\n");
		return ;
	}
	while (str && str[i])
	{
		printf("lol\n");
		i++;
	}
		// printf("%s", str[i++]);
}


void	parcing_map(char *name, t_data *data)
{
	data->map = NULL;
	//initmap(name, data);
	print_map(data->map);
}

// int		check_wall(t_data *data)
// {
// 	while (data->map[j])
// 	{
// 		while (data->map[j][i])
// 		{
			
// 		}
// 	}
// }
