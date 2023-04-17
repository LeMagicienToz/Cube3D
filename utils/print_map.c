/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rperrin <rperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 01:31:15 by rperrin           #+#    #+#             */
/*   Updated: 2023/04/15 02:42:21 by rperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

void	print_map(char **str)
{
	int		i;
	int		j;

	j = 0;
	i = 0;
	if (str == NULL)
	{
		printf("ERROR NO MAP !\n");
		return ;
	}
	printf("");
	while (str[j])
	{
		while (str[j][i])
			printf("%c", str[j][i++]);
		printf("\n");
		i = 0;
		j++;
	}
}
