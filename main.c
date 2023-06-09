/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rperrin <rperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 16:39:58 by raphaelperr       #+#    #+#             */
/*   Updated: 2023/06/07 18:44:51 by rperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int	main(int argc, char **argv)
{
	t_data	data;

	if (make_all_test(&data, argc, argv))
		return (1);
	// printf("%d %d %d\n", data.ff[0], data.ff[1], data.ff[2]);
	convert_rgb_to_hex(&data);
	printf("%s\n", data.hex_ff);
	printf("%s\n", data.hex_cc);
	// init_mlx(data);
	printf("\n[PARSING : GOOD]\n");
}
