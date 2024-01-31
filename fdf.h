/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aapryce <aapryce@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 10:57:40 by aapryce           #+#    #+#             */
/*   Updated: 2024/01/31 15:51:44 by aapryce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>
# include <X11/keysym.h>
# include <X11/X.h>
# include "../libft/libft.h"
# include "minilibx-linux/mlx.h"
# define BUFFER_SIZE 1
# define WIN_HEIGHT 2000
# define WIN_LENGTH 3500
# define ZOOM 1600

typedef struct s_mlx
{
	void	*mlx_ptr;
	void	*win_ptr;
}	t_mlx;

typedef struct s_img_data
{
	void	*img_ptr;
	void	*adress;
	int		bpp;
	int		line_len;
	int		endian;
	float	zoom;
	int		colour;
	int		win_x;
	int		win_y;
}	t_img_data;

typedef struct s_draw
{
	int		max;
	int		sx;
	int		sy;
	int		err;
	int		e2;
	float	x_move;
	float	y_move;
}	t_draw;

typedef struct s_map_data
{
	int	x;
	int	y;
	int	**grid;
}	t_map_data;

typedef struct s_pixel
{
	int	x;
	int	y;
	int	z;
	int	colour;
}	t_pixel;

void	read_file(char *file, t_map_data *data);
int		get_height(char *file);
int		get_width(char *file);
void	fill_z(int *z_line, char *line);
int		grid_init(char *line, t_map_data *data, int fd);

size_t	ft_wrdlen(const char *s, char c);
char	*get_next_line(int fd);
size_t	ft_strlen(const char *str);
char	*ft_strjoin(const char *str1, const char *str2);
char	*ft_substr(const char *s, unsigned int start, size_t len);
char	*ft_strcpy(char *dest, const char *src);
char	*ft_strdup(const char *src);
char	*ft_strchr(const char *str, int c);

int		win_close(int keysym, t_mlx *data);
int		close_button(t_mlx *data);
void	init_mlx(t_img_data *data, t_map_data *map);

void	map_draw(t_map_data *map, t_img_data *data);

t_pixel	iso_layer(t_pixel pixel);
t_draw	*init_draw(int x, int x1, int y, int y1);
void	my_mlx_pixel_put(t_img_data *data, t_pixel pixel);
void	pixel_put(t_pixel p1, t_pixel p2, t_img_data *data, t_draw *draw);
void	line_draw(t_pixel p1, t_pixel p2, t_img_data *data, t_map_data *map);

int		colour(int z);
double	get_percent(int start, int end, int curr);
int		get_light(int start, int end, double percentage);
int		interpolate_colour(t_pixel current, t_pixel start,
			t_pixel end, t_pixel delta);
void	free_grid(int **grid);

#endif
