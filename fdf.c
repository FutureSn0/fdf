/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aapryce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 11:15:44 by aapryce           #+#    #+#             */
/*   Updated: 2023/11/30 15:47:16 by aapryce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "minilibx-linux/mlx.h"
#include <stdio.h>

/*int	deal_key(int key, t_map_data *data)
{
	printf("%d", key);
	return (0);
}*/

int	main(int argc, char **argv)
{
	t_map_data	*data;

	data = (t_map_data*)malloc(sizeof(t_map_data));
	read_file(argv[1], data);
	if (!argv[1])
		return (0);

	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, 1000, 1000, "fdf");
	data->zoom = 50;
	
	draw(data);
	/*mlx_key_hook(data->win_ptr, deal_key, NULL);*/
	mlx_loop_hook(data->mlx_ptr, &no_event, &data);
	mlx_key_hook(data->win_ptr, &win_close, &data);
	mlx_loop(data->mlx_ptr);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
}
