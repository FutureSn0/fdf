/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utills.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aapryce <aapryce@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 12:45:30 by aapryce           #+#    #+#             */
/*   Updated: 2024/03/08 12:57:34 by aapryce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

size_t	ft_wrdlen(const char *s, char c)
{
	size_t	res;

	if (!s)
		return (0);
	res = 0;
	while (*s != '\0')
	{
		if (*s != c)
		{
			++res;
			while (*s != '\0' && *s != c)
				++s;
		}
		else
			++s;
	}
	return (res);
}

void	free_grid(int **grid)
{
	int	i;

	i = 0;
	while (grid[i])
	{
		free(grid[i]);
		i++;
	}
	free(grid);
}

void	check_fd(char *file, t_map_data *data)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		free(data);
		write(2, "Error\n", 6);
		exit(1);
	}
	close(fd);
}
