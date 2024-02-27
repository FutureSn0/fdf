/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aapryce <aapryce@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 11:50:44 by aapryce           #+#    #+#             */
/*   Updated: 2024/02/27 16:00:39 by aapryce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	map_draw(t_map_data *map, t_img_data *data)
{
	int		x;
	int		y;

	y = 0;
	while (y < map->y)
	{
		x = 0;
		while (x < map->x)
		{
			if (x < map->x - 1)
				line_draw((t_pixel){x, y, 0, 0},
					(t_pixel){x + 1, y, 0, 0}, data, map);
			if (y < map->y - 1)
				line_draw((t_pixel){x, y, 0, 0},
					(t_pixel){x, y + 1, 0, 0}, data, map);
			x++;
		}
		y++;
	}
}
