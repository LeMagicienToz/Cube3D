/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raphaelperrin <raphaelperrin@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 16:39:58 by raphaelperr       #+#    #+#             */
/*   Updated: 2023/05/16 01:45:40 by raphaelperr      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int	main(int argc, char **argv)
{
	t_data data;

	if (make_all_test(&data, argc, argv))
		return (1);
	else
		printf("\n[PARSING : GOOD]\n");
}
