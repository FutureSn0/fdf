/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aapryce <aapryce@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 13:00:47 by aapryce           #+#    #+#             */
/*   Updated: 2024/03/01 14:14:54 by aapryce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	close_button(t_img_data *data)
{
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	exit(0);
	return (0);
}

int	win_close(int keysym, t_img_data *data)
{
	if (keysym == XK_Escape)
	{
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);
		exit(1);
	}
	return (0);
}

/*int	zoom(int keysym, t_mlx *data)
{
	if (keysym == XK_KP_Multiply)
		data->zoom += 1;
	if (keysym == XK_KP_Subtract)
		data->zoom -= 1;
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	map_draw(data);
	return (0);
}*/
