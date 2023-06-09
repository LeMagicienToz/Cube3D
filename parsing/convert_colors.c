/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_colors.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rperrin <rperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 00:29:29 by raphaelperr       #+#    #+#             */
/*   Updated: 2023/06/07 19:53:16 by rperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

void	norm_hex(void)
{
}

char	*convert_tab_to_char(char base[16], int *tab)
{
	int		i;
	int		j;
	char	*hex;

	(norm_hex(), hex = malloc(sizeof(char) * 9), \
	hex[0] = '0', hex[1] = 'x', hex[8] = '\0', i = 0, j = 2);
	while (i < 3)
	{
		if (tab[i] == 0)
			(norm_hex(), hex[j++] = '0', hex[j++] = '0', i++);
		else
		{
			hex[j++] = base[tab[i] / 16];
			if (tab[i] % 16)
				hex[j++] = base[tab[i++] % 16];
			else
				(norm_hex(), hex[j++] = '0', i++);
		}
	}
	return (hex);
}

void	convert_rgb_to_hex(t_data *data)
{
	data->hex_ff = convert_tab_to_char("0123456789ABCDEF", data->ff);
	data->hex_cc = convert_tab_to_char("0123456789ABCDEF", data->cc);
}
