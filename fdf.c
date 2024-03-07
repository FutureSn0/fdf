/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aapryce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 11:15:44 by aapryce           #+#    #+#             */
/*   Updated: 2024/03/07 20:28:28 by aapryce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char **argv)
{
	t_map_data	*map;
	t_img_data	data;

	(void)argc;
	if (!argv[1])
		return (-1);
	map = (t_map_data *)malloc(sizeof(t_map_data));
	if (!map)
		return (-1);
	read_file(argv[1], map);
	init_mlx(&data, map);
	return (0);
}
