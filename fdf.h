/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aapryce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 10:57:40 by aapryce           #+#    #+#             */
/*   Updated: 2023/11/30 15:28:55 by aapryce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

#include <stdlib.h>
#include "libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "minilibx-linux/mlx.h"
# include <math.h>
# include <X11/keysym.h>
# define BUFFER_SIZE 1

typedef struct s_point
{
	float	x;
	float	y;
	int	colour;
} t_point;

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
void	bresenham(float x, float y, float x1, float y1, t_map_data *data);
void	draw(t_map_data *data);
int	win_close(int keysym, t_map_data *data);
float	mod(float i);
float	ab(float a, float b);
//int	colour(int z, int z1);//
int     colour(t_point current, t_point start, t_point end, t_point delta);
int     get_colour(t_point current, t_point start, t_point end, t_point delta);
int     get_light(int start, int end, double percentage);
int	no_event(void *data);

#endif
