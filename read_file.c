/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aapryce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 10:30:38 by aapryce           #+#    #+#             */
/*   Updated: 2023/11/28 11:17:54 by aapryce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

int	get_height(char *file)
{
	int	fd;
	int	height;
	char	*line;

	fd = open(file, O_RDONLY);
	height = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		height++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (height);
}

int	get_width(char *file)
{
	int	fd;
	int	width;
	char	*line;

	fd = open(file, O_RDONLY);
	line = get_next_line(fd);
	width = ft_wrdlen(line, ' ');
	free(line);
	close(fd);
	return (width);
}

void	fill_z(int *z_line, char *line)
{
	char	**nbrs;
	int	i;

	nbrs = ft_split(line, ' ');
	i = 0;
	while (nbrs[i])
	{
		z_line[i] = ft_atoi(nbrs[i]);
		free(nbrs[i]);
		i++;
	}
	free(nbrs);
}

void	read_file(char *file, t_map_data *data)
{
	char	*line;
	int	fd;
	int	i;

	data->height = get_height(file);
	data->width = get_width(file);

	data->z_axis = (int **)malloc(sizeof(int *) * (data->height + 1));
		if (!data->z_axis)
			return ;
	i = 0;
	while (i < data->height)
	{
		data->z_axis[i++] = (int*)malloc(sizeof(int) * (data->width + 1));
			if (!data->z_axis)
			{
				return ;
			}
	}
	fd = open(file, O_RDONLY);
	line = get_next_line(fd);
	i = 0;
	while (line != NULL)
	{
		fill_z(data->z_axis[i], line);
		free(line);
		i++;
		line = get_next_line(fd);
		if (i >= data->height)
			break ;
	}
	close(fd);
	data->z_axis[i] = NULL;
}
