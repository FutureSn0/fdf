/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aapryce <aapryce@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 10:30:38 by aapryce           #+#    #+#             */
/*   Updated: 2024/03/08 13:00:06 by aapryce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	get_height(char *file)
{
	int		fd;
	int		height;
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
	int		fd;
	int		width;
	char	*line;

	fd = open(file, O_RDONLY);
	line = get_next_line(fd);
	width = (ft_wrdlen(line, ' ') - 1);
	free(line);
	close(fd);
	return (width);
}

void	fill_z(int *z_line, char *line)
{
	char	**nbrs;
	int		i;

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

int	grid_init(char *line, t_map_data *data, int fd)
{
	int	i;

	i = 0;
	while (line != NULL)
	{
		fill_z(data->grid[i], line);
		free(line);
		i++;
		line = get_next_line(fd);
		if (i >= data->y)
			break ;
	}
	return (i);
}

void	read_file(char *file, t_map_data *data)
{
	char	*line;
	int		fd;
	int		i;

	check_fd(file, data);
	data->y = get_height(file);
	data->x = get_width(file);
	data->grid = (int **)malloc(sizeof(int *) * (data->y + 1));
	if (!data->grid)
		return ;
	i = 0;
	while (i < data->y)
	{
		data->grid[i] = (int *)malloc(sizeof(int) * (data->x + 1));
		if (!data->grid[i])
			return ;
		i++;
	}
	fd = open(file, O_RDONLY);
	line = get_next_line(fd);
	i = grid_init(line, data, fd);
	close(fd);
	data->grid[i] = NULL;
}
