/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp_r.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raphaelperrin <raphaelperrin@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 18:59:38 by raphaelperr       #+#    #+#             */
/*   Updated: 2023/04/24 19:00:55 by raphaelperr      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

void	norm(void)
{
}

int	ft_strcmp(char *check, char *str)
{
	int		i;
	int		j;

	(norm(), i = 0, j = 0);
	while (check[j])
	{
		while (str[i])
		{
			if (str[i] == check[j])
				return (1);
			i++;
		}
		i = 0;
		j++;
	}
	return (0);
}