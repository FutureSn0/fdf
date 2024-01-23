/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aapryce <aapryce@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 13:00:47 by aapryce           #+#    #+#             */
/*   Updated: 2024/01/23 14:58:06 by aapryce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int     win_close(int keysym, t_mlx *data)
{
        if (keysym == XK_Escape)
	{
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);
		exit(1);
	}
        return(0);
}
