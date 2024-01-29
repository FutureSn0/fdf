/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aapryce <aapryce@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 11:40:07 by aapryce           #+#    #+#             */
/*   Updated: 2024/01/29 14:04:03 by aapryce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	init_mlx(t_img_data *data, t_map_data *map)
{
	t_mlx	mlx;

	mlx.mlx_ptr = mlx_init();
	if (!mlx.mlx_ptr)
		return ;
	mlx.win_ptr = mlx_new_window(mlx.mlx_ptr, WIN_LENGTH, WIN_HEIGHT, "fdf");
	if (!mlx.win_ptr)
	{
		mlx_destroy_display(mlx.mlx_ptr);
		free(mlx.mlx_ptr);
		return ;
	}
	data->img_ptr = mlx_new_image(mlx.mlx_ptr, WIN_LENGTH, WIN_HEIGHT);
	data->adress = mlx_get_data_addr(data->img_ptr, &data->bpp,
			&data->line_len, &data->endian);
	map_draw(map, data);
	mlx_put_image_to_window(mlx.mlx_ptr, mlx.win_ptr, data->img_ptr, 0, 0);
	mlx_destroy_image(mlx.mlx_ptr, data->img_ptr);
	mlx_key_hook(mlx.win_ptr, &win_close, &mlx);
	mlx_hook(mlx.win_ptr, 33, 0, &close_button, &mlx);
	mlx_loop(mlx.mlx_ptr);
}
