/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_draw.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aapryce <aapryce@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 12:12:18 by aapryce           #+#    #+#             */
/*   Updated: 2024/03/11 13:41:53 by aapryce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_pixel	iso_layer(t_pixel pixel)
{
	t_pixel	new_pixel;

	new_pixel.x = (pixel.x - pixel.y) * cos(0.5);
	new_pixel.y = (pixel.x + pixel.y) * sin(0.5) - pixel.z;
	return (new_pixel);
}

t_draw	*init_draw(int x, int x1, int y, int y1)
{
	t_draw	*draw;

	draw = (t_draw *)malloc(sizeof (t_draw));
	if (!draw)
		return (NULL);
	draw->x_move = fabs((float)(x1 - x));
	draw->y_move = fabs((float)(y1 - y));
	draw->err = draw->x_move - draw->y_move;
	if ((x1 - x) > 0)
		draw->sx = 1;
	else
		draw->sx = -1;
	if ((y1 - y) > 0)
		draw->sy = 1;
	else
		draw->sy = -1;
	return (draw);
}

void	my_mlx_pixel_put(t_img_data *data, t_pixel pixel)
{
	char	*dst;

	dst = data->adress + (pixel.y + 200) * data->line_len
		+(pixel.x + 1750) * (data->bpp / 8);
	*(unsigned int *)dst = pixel.colour;
}

void	pixel_put(t_pixel p1, t_pixel p2, t_img_data *data, t_draw *draw)
{
	t_pixel	delta;
	t_pixel	current;

	current = p1;
	delta.x = abs(p2.x - p1.x);
	delta.y = abs(p2.y - p1.y);
	while ((int)(current.x - p2.x) || (int)(current.y - p2.y))
	{
		current.colour = interpolate_colour(current, p1, p2, delta);
		my_mlx_pixel_put(data, current);
		draw->e2 = 2 * draw->err;
		if (draw->e2 >= -draw->y_move)
		{
			draw->err -= draw->y_move;
			current.x += draw->sx;
		}
		if (draw->e2 <= draw->x_move)
		{
			draw->err += draw->x_move;
			current.y += draw->sy;
		}
	}
}

void	line_draw(t_pixel p1, t_pixel p2, t_img_data *data, t_map_data *map)
{
	t_draw	*draw;
	t_pixel	iso_p1;
	t_pixel	iso_p2;

	data->zoom = 1600;
	p1.z = map->grid[p1.y][p1.x];
	p2.z = map->grid[p2.y][p2.x];
	p1.x *= data->zoom / map->x;
	p1.y *= data->zoom / map->x;
	p2.x *= data->zoom / map->x;
	p2.y *= data->zoom / map->x;
	iso_p1 = iso_layer(p1);
	iso_p2 = iso_layer(p2);
	iso_p1.z = p1.z;
	iso_p2.z = p2.z;
	draw = init_draw(iso_p1.x, iso_p2.x, iso_p1.y, iso_p2.y);
	iso_p1.colour = colour(p1.z);
	iso_p2.colour = colour(p2.z);
	pixel_put(iso_p1, iso_p2, data, draw);
	free(draw);
}
