/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aapryce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 10:57:40 by aapryce           #+#    #+#             */
/*   Updated: 2023/11/28 13:55:46 by aapryce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

#include <stdlib.h>
#include "../libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <mlx.h>

typedef struct	s_map_data
{
	int	height;
	int	width;
	int	**z_axis;
	int	zoom;
	int	colour;

	void	*mlx_ptr;
	void	*win_ptr;
} t_map_data;

void	read_file(char *file, t_map_data *data);
size_t	ft_wrdlen(const char *s, char c);
char	*get_next_line(int fd);
size_t	ft_strlen(const char *str);
char	*ft_strjoin(const char *str1, const char *str2);
char	*ft_substr(const char *s, unsigned int start, size_t len);
char	*ft_strcpy(char *dest, const char *src);
char	*ft_strdup(const char *src);
char	*ft_strchr(const char *str, int c);

#endif
