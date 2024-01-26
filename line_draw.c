/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_draw.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aapryce <aapryce@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 12:12:18 by aapryce           #+#    #+#             */
/*   Updated: 2024/01/26 17:12:31 by aapryce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_pixel	iso_layer(t_pixel pixel)
{
	t_pixel	new_pixel;

	new_pixel.x = (pixel.x - pixel.y) * cos(0.8);
	new_pixel.y = (pixel.x + pixel.y) * sin(0.8) - pixel.z;
	return (new_pixel);
}

t_draw	*init_draw(int x, int x1, int y, int y1)
{
	t_draw	*draw;

	draw = (t_draw *)malloc(sizeof (t_draw));
	if (!draw)
		return ;
	draw->x_move = (float)(x1 - x);
	draw->y_move = (float)(y1 - y);
	draw->max = (int)fmax(fabs(draw->x_move), fabs(draw->y_move));
	draw->x_move /= draw->max;
	draw->y_move /= draw->max;
	return (draw);
}
/*
void	my_mlx_pixel_put()

void	pixel_put()
*/

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
	iso_p1 = iso_layer(p1);
	iso_p2 = iso_layer(p2);
	iso_p1.z = p1.z;
	iso_p2.z = p2.z;
	draw = init_draw(iso_p1.x, iso_p2.x, iso_p1.y, iso_p2.y);
}