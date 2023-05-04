/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raphaelperrin <raphaelperrin@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 18:48:06 by raphaelperr       #+#    #+#             */
/*   Updated: 2023/04/26 16:06:34 by raphaelperr      ###   ########.fr       */
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
		{
			printf("\nPlease launch with ./cube3d !\n");
			return (1);
		}
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
		{
			printf("Bad characters :/ \n");
			return (close(fd), 1);	
		}
	}
	return (close(fd), 0);
}