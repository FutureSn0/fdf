/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aapryce <aapryce@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 11:50:44 by aapryce           #+#    #+#             */
/*   Updated: 2024/01/29 13:14:29 by aapryce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	map_draw(t_map_data *map, t_img_data *data)
{
	int		x;
	int		y;
	t_pixel	p1;
	t_pixel	p2;

	y = 0;
	while (y < map->y)
	{
		x = 0;
		while (x < map->x)
		{
			if (x < map->x - 1)
				line_draw((t_pixel){x, y}, (t_pixel){x + 1, y}, data, map);
			if (y < map->y - 1)
				line_draw((t_pixel){x, y}, (t_pixel){x, y + 1}, data, map);
			x++;
		}
		y++;
	}
}
