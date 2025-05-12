/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaducurt <gaducurt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 15:31:22 by gaducurt          #+#    #+#             */
/*   Updated: 2025/05/07 16:12:25 by gaducurt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "vector.h"

# define ZOOM_Z		4
# define ANGLE		120
# define LENGTH		1920
# define WIDTH		1080

typedef struct s_len_map
{
	int	lenght;
	int	width;
}		t_len_map;

typedef struct s_data_fdf
{
	int	x;
	int	y;
	int	z;
	int	index;
	int	color;
	int	length;
	int	width;
}	t_data_fdf;

typedef struct s_limits
{
	int	x;
	int	y;
	int	x_min;
	int	x_max;
	int	y_min;
	int	y_max;
}		t_limits;

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
}			t_data;

typedef struct s_kook
{
	void	*mlx;
	void	*mlx_win;
	t_data	*img;
}			t_hook;

typedef struct s_win
{
	int		x;
	int		y;
}			t_win;

typedef struct s_bres
{
	int	x1;
	int	x2;
	int	y1;
	int	y2;
	int	ex;
	int	ey;
	int	dx;
	int	dy;
	int	d_x;
	int	d_y;
	int	i;
	int	color1;
	int	color2;
	int	x_incr;
	int	y_incr;
}		t_bres;

void		ft_bresenham_one(t_data *img, t_bres f);
void		ft_bresenham_two(t_data *img, t_bres f);
void		ft_display_line(t_data *img, t_data_fdf *p1, t_data_fdf *p2);
void		my_mlx_pixel_put(t_data *data, int x, int y, int color);
int			ft_handle_win(t_vector *vector, void *mlx, void *mlx_win,
				t_data *img);
int			ft_lentab(char **c_tab);
void		ft_double_free(char **s, int nb_word);
void		ft_replace(char *line);
char		**ft_new_tab(int fd);
t_len_map	ft_len_map(t_vector *vector);
void		ft_size_map(t_vector *vector);
int			ft_fill_tab(int size, int fd, t_vector *vector);
int			ft_close(t_hook *params);
int			ft_exit_free(int keycode, t_hook *params);
void		ft_fill_params(t_hook *params, void *mlx, void *mlx_win,
				t_data *img);
int			ft_atoi_inter_base(char *s, char *base, int start, int end);
int			ft_check_color(char *s);
int			ft_size_tab(char **s);
int			ft_check_format(char *str);
int			ft_check_map(char *file, int size);
void		ft_fill_color(char *s, t_data_fdf *data);
void		ft_middle(t_vector *vector, int diff);
int			ft_check_zoom(int diff);
void		ft_zoom(t_vector *vector, t_limits *limits);
void		ft_diff(t_vector *vector);
void		ft_iso_matrix(t_data_fdf *p);
void		ft_display_map(t_vector *vector, t_data *img);
void		ft_move_to_zero(t_limits *limits, t_data_fdf *p, int factor);
void		ft_init_limits(t_limits *limits, t_data_fdf *p, size_t i);
void		ft_move_to_zero(t_limits *limits, t_data_fdf *p, int factor);
int			ft_return_free(char *line, int fd);
int			ft_check_add_vector(t_vector *vector, t_data_fdf *data,
				int fd, char **c_tab);
int			ft_check_malloc(char **c_tab, int fd, t_vector *vector);
int			ft_init_win(t_vector *vector);
int			ft_clean_exit(t_vector *vector, void *mlx, void *mlx_win,
				t_data *img);
int			ft_putstr_error(char *s, int fd);

#endif