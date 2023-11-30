/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aapryce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 12:08:24 by aapryce           #+#    #+#             */
/*   Updated: 2023/11/30 15:34:40 by aapryce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

float	mod(float i)
{
	if (i < 0)
		return (-i);
	return (i);
}

float	ab(float a, float b)
{
	if (a > b)
		return (a);
	return (b);
}

void	bresenham(float x, float y, float x1, float y1, t_map_data *data)
{
	float	x_move;
	float	y_move;
	int	max;

	 x *= data->zoom;
	 y *= data->zoom;
	 x1 *= data->zoom;
	 y1 *= data->zoom;
	
	x_move = x1 - x;
	y_move = y1 - y;

	max = ab(mod(x_move), mod(y_move));
	x_move /= max;
	y_move /= max;
	while ((int)(x - x1) || (int)(y = y1))
	{
		mlx_pixel_put(data->mlx_ptr, data->win_ptr, x, y, 0xffffff);
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
			bresenham(x, y, x + 1, y, data);
			bresenham(x, y, x, y + 1, data);
			x++;
		}
		y++;
	}
}
