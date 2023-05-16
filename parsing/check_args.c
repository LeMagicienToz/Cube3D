/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raphaelperrin <raphaelperrin@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 18:48:06 by raphaelperr       #+#    #+#             */
/*   Updated: 2023/05/13 02:29:54 by raphaelperr      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

int	parsing_name(char *str)
{
	int i;
	char test[9] = "./cube3d";
	i = 0;
	while (str && str[i])
	{
		if (str[i] != test[i])
			return (1);
		i++;
	}
	return (0);
}

int	parsing_ext(char *str)
{
	int i;
	int j;
	char test[4] = ".cub";

	j = 0;
	if (!str)
		return (1);
	i = ft_strlen(str) - 1;
	if (i <= 4)
		return (1);
	while (j < 2)
	{
		if (str[i] != test[3 - j])
			return (1);
		i--;
		j++;
	}
	return (0);
}

int	check_file(char *name)
{
	int fd;
	if (!name)
		return (1);
	fd = open(name, O_RDONLY);
	if (fd < 0)
		return (close(fd), 1);
	return (close(fd), 0);
}

int	check_codec(char *name)
{
	int 	fd;
	char	c;

	fd = open(name, O_RDONLY);	
	while (read(fd, &c, 1) > 0)
	{
		if ((c < 32 || c > 126 ) && c != 10)
			return (close(fd), 1);	
	}
	return (close(fd), 0);
}

int	check_args(int ac, char **av)
{
	if (ac == 1)
		return (printf("\nPlease launch with ./cube3d <map.cub> !\n"), 1);
	if (ac > 2)
		return (printf("\nToo many arguments !\n"), 1);
	if (parsing_name(av[0]) == 1)
		return (printf("\nBad name !\n"), 1);
	if (parsing_ext(av[1]) == 1)
		return (printf("\nBad extension !\n"), 1);
	if (check_file(av[1]) == 1)
		return (printf("\nBad map file !\n"), 1);
	if (check_codec(av[1]) == 1)
		return (printf("\nBad characters in map file !\n"), 1);
	return (0);
}