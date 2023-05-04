/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raphaelperrin <raphaelperrin@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 16:39:58 by raphaelperr       #+#    #+#             */
/*   Updated: 2023/04/27 21:40:27 by raphaelperr      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int	main(int argc, char **argv)
{
	t_data data;

	if (argc > 2 || parsing_name(argv[0]) || parsing_ext(argv[1]) \
	|| check_file(argv[1]) || check_codec(argv[1]) || parsing_map(argv[1], &data))
		return (printf("\nPARSING [KO]\n"), 1);
	else
		printf("\nPARSING [OK]\n");
}