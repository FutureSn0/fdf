/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aapryce <aapryce@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 11:40:07 by aapryce           #+#    #+#             */
/*   Updated: 2024/03/04 14:03:25 by aapryce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	init_mlx(t_img_data *data, t_map_data *map)
{
	data->mlx_ptr = mlx_init();
	if (!data->mlx_ptr)
		return ;
	data->win_ptr = mlx_new_window(data->mlx_ptr,
			WIN_LENGTH, WIN_HEIGHT, "fdf");
	if (!data->win_ptr)
	{
		mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);
		return ;
	}
	data->img_ptr = mlx_new_image(data->mlx_ptr, WIN_LENGTH, WIN_HEIGHT);
	data->adress = mlx_get_data_addr(data->img_ptr, &data->bpp,
			&data->line_len, &data->endian);
	map_draw(map, data);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_ptr, 0, 0);
	mlx_key_hook(data->win_ptr, &win_close, data);
	mlx_hook(data->win_ptr, 33, 0, &close_button, data);
	free_grid(map->grid);
	free(map);
	mlx_loop(data->mlx_ptr);
}
