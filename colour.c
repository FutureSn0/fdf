/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colour.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aapryce <aapryce@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 13:26:04 by aapryce           #+#    #+#             */
/*   Updated: 2024/01/31 15:50:05 by aapryce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	colour(int z)
{
	if (z > 0)
		return (0xe80c0c);
	else if (z < 0)
		return (0x0000ff);
	return (0x00ff00);
}

double	get_percent(int start, int end, int curr)
{
	double	placement;
	double	distance;

	placement = curr - start;
	distance = end - start;
	if (distance == 0)
		return (1.0);
	return (placement / distance);
}

int	get_light(int start, int end, double percentage)
{
	return ((int)((1 - percentage) * start + percentage * end));
}

int	interpolate_colour(t_pixel curr, t_pixel start, t_pixel end, t_pixel delta)
{
	int		red;
	int		green;
	int		blue;
	double	percentage;

	if (curr.colour == end.colour)
		return (curr.colour);
	if (delta.x > delta.y)
		percentage = get_percent(start.x, end.x, curr.x);
	else
		percentage = get_percent(start.y, end.y, curr.y);
	red = get_light((start.colour >> 16) & 0xFF,
			(end.colour >> 16) & 0xFF, percentage);
	green = get_light((start.colour >> 8) & 0xFF,
			(end.colour >> 8) & 0xFF, percentage);
	blue = get_light(start.colour & 0xFF, end.colour & 0xFF, percentage);
	return ((red << 16) | (green << 8) | blue);
}
