/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaducurt <gaducurt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 18:14:36 by gaducurt          #+#    #+#             */
/*   Updated: 2025/05/07 15:40:04 by gaducurt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "vector.h"
#include "fdf.h"
#include <math.h>

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	if (x > LENGTH || y > WIDTH)
		return ;
	if (x < 0 || y < 0)
		return ;
	dst = data->addr + (y * data->size_line + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	ft_iso_matrix(t_data_fdf *p)
{
	int	x;
	int	y;

	x = p->x;
	y = p->y;
	p->x = (x * cos(ANGLE)) + (y * cos(ANGLE + 2)) + (p->z * cos(ANGLE - 2));
	p->y = (x * sin(ANGLE)) + (y * sin(ANGLE + 2)) + (p->z * sin(ANGLE - 2));
}

void	ft_display_map(t_vector *vector, t_data *img)
{
	size_t		i;
	t_data_fdf	*origin;
	t_data_fdf	*p1;
	t_data_fdf	*p2;

	i = 0;
	while (i < vector->len - 1)
	{
		origin = (t_data_fdf *)((unsigned char *)vector->array
				+ i * vector->size_type);
		if ((origin->index == 0)
			|| (origin->index + 1) % origin->length != 0)
			p1 = (t_data_fdf *)((unsigned char *)vector->array
					+ (i + 1) * vector->size_type);
		if (i < vector->len - origin->length)
			p2 = (t_data_fdf *)((unsigned char *)vector->array
					+ (i + origin->length) * vector->size_type);
		if ((origin->index == 0) || ((origin->index + 1) % origin->length != 0))
			ft_display_line(img, origin, p1);
		if (i < vector->len - origin->length)
			ft_display_line(img, origin, p2);
		i++;
	}
}

int	ft_handle_win(t_vector *vector, void *mlx, void *mlx_win, t_data *img)
{
	t_hook		params;

	ft_fill_params(&params, mlx, mlx_win, img);
	ft_diff(vector);
	ft_display_map(vector, img);
	ft_free_vector(vector);
	mlx_put_image_to_window(mlx, mlx_win, img->img, 0, 0);
	mlx_key_hook(mlx_win, &ft_exit_free, &params);
	mlx_hook(mlx_win, 17, 0, &ft_close, &params);
	mlx_loop(mlx);
	free(mlx);
	return (1);
}

int	ft_init_win(t_vector *vector)
{
	void		*mlx;
	void		*mlx_win;
	t_data		img;

	mlx = mlx_init();
	if (!mlx)
		return (ft_clean_exit(vector, NULL, NULL, NULL));
	mlx_win = mlx_new_window(mlx, LENGTH, WIDTH, "fdf");
	img.img = mlx_new_image(mlx, LENGTH, WIDTH);
	if (!img.img || !mlx_win)
		return (ft_clean_exit(vector, mlx, mlx_win, &img));
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.size_line,
			&img.endian);
	if (!img.addr)
		return (ft_clean_exit(vector, mlx, mlx_win, &img));
	ft_handle_win(vector, mlx, mlx_win, &img);
	return (1);
}
