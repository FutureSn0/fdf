/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aapryce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 12:08:24 by aapryce           #+#    #+#             */
/*   Updated: 2024/01/24 18:37:25 by aapryce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*int	colour(int z, int z1)
{
	if (z || z1)
		return (0xe80c0c);
	return (0xff00);
}*/

void	third_dimension_layer(float *x, float *y, int z)
{
	*x = (*x - *y) * cos(0.8);
	*y = (*x + *y) * sin(0.8) - z;
}

void	bresenham(float x, float y, float x1, float y1, t_map_data *data)
{
	float	x_move;
	float	y_move;
	int	max;
	int	z;
	int	z1;

	z = data->z_axis[(int)y][(int)x];
	z1 = data->z_axis[(int)y1][(int)x1];
	x *= data->zoom;
	y *= data->zoom;
	x1 *= data->zoom;
	y1 *= data->zoom;
	data->colour = get_colour(current, start, end, delta);
	third_dimension_layer(&x, &y, z);
	third_dimension_layer(&x1, &y1, z1);
	x += 350;
	y += 350;
	x1 += 350;
	y1 += 350;
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

void	draw(t_map_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < data->height)
	{
		x = 0;
		while (x < data->width)
		{
			if (x < data->width - 1)
				bresenham(x, y, x + 1, y, data);
			if (y < data->height - 1)
				bresenham(x, y, x, y + 1, data);
			x++;
		}
		y++;
	}
}
