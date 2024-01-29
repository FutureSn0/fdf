/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_draw.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aapryce <aapryce@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 12:12:18 by aapryce           #+#    #+#             */
/*   Updated: 2024/01/29 14:19:31 by aapryce          ###   ########.fr       */
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
		return (NULL);
	draw->x_move = (float)(x1 - x);
	draw->y_move = (float)(y1 - y);
	draw->max = (int)fmax(fabs(draw->x_move), fabs(draw->y_move));
	draw->x_move /= draw->max;
	draw->y_move /= draw->max;
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
	while ((int)(p1.x - p2.x) || (int)(p1.y - p2.y))
	{
		my_mlx_pixel_put(data, p1);
		draw->e2 = 2 * draw->err;
		if (draw->e2 >= draw->y_move)
		{
			draw->err += draw->y_move;
			p1.x += draw->sx;
		}
		if (draw->e2 <= draw->x_move)
		{
			draw->err += draw->x_move;
			p1.y += draw->sy;
		}
	}
}

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
	p1.colour = 0xFFFFFF;
	p2.colour = 0xFFFFFF;
	pixel_put(iso_p1, iso_p2, data, draw);
	free(draw);
}
