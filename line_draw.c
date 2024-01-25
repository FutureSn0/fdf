/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_draw.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aapryce <aapryce@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 12:12:18 by aapryce           #+#    #+#             */
/*   Updated: 2024/01/25 17:05:52 by aapryce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	line_draw(t_pixel p1, t_pixel p2, t_img_data *data, t_map_data *map)
{
	t_draw	*draw;
	t_pixel	iso_p1;
	t_pixel	iso_p2;

	p1.z = map->grid[p1.y][p1.x];
	p2.z = map->grid[p2.y][p2.x];
	p1.x *= ZOOM / map->x;
	p1.y *= ZOOM / map->x;
	p2.x *= ZOOM / map->x;
	p2.y *= ZOOM / map->x;
	iso_p1 = third_dimension_layer();
	iso_p2 = third_dimension_layer();
	iso_p1.z = p1.z;
	iso_p2.z = p2.z;

	x_move = x1 - x;
	y_move = y1 - y;
	max = ab(mod(x_move), mod(y_move));
	x_move /= max;
	y_move /= max;
	while ((int)(x - x1) || (int)(y - y1))
	{
		mlx_pixel_put(data->mlx_ptr, data->win_ptr, x, y, data->colour);
		x += x_move;
		y += y_move;
	}
}