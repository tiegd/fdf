/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaducurt <gaducurt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 15:39:53 by gaducurt          #+#    #+#             */
/*   Updated: 2025/05/05 17:28:14 by gaducurt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "vector.h"
#include "fdf.h"
#include <math.h>

void	ft_bresenham_one(t_data *img, t_bres f)
{
	while (f.i <= f.d_x)
	{
		my_mlx_pixel_put(img, f.x1, f.y1, f.color1);
		f.i++;
		f.x1 += f.x_incr;
		f.ex -= f.dy;
		if (f.ex < 0)
		{
			f.y1 += f.y_incr;
			f.ex += f.dx;
		}
	}
}

void	ft_bresenham_two(t_data *img, t_bres f)
{
	while (f.i <= f.d_y)
	{
		my_mlx_pixel_put(img, f.x1, f.y1, f.color1);
		f.i++;
		f.y1 += f.y_incr;
		f.ey -= f.dx;
		if (f.ey < 0)
		{
			f.x1 += f.x_incr;
			f.ey += f.dy;
		}
	}
}

void	ft_display_line(t_data *img, t_data_fdf *p1, t_data_fdf *p2)
{
	t_bres	f;

	f.x1 = p1->x;
	f.y1 = p1->y;
	f.x2 = p2->x;
	f.y2 = p2->y;
	f.ex = abs(f.x2 - f.x1);
	f.ey = abs(f.y2 - f.y1);
	f.dx = 2 * f.ex;
	f.dy = 2 * f.ey;
	f.d_x = f.ex;
	f.d_y = f.ey;
	f.i = 0;
	f.x_incr = 1;
	f.y_incr = 1;
	f.color1 = p1->color;
	f.color2 = p2->color;
	if (f.x1 > f.x2)
		f.x_incr = -1;
	if (f.y1 > f.y2)
		f.y_incr = -1;
	if (f.d_x >= f.d_y)
		ft_bresenham_one(img, f);
	if (f.d_x < f.d_y)
		ft_bresenham_two(img, f);
}
