/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaducurt <gaducurt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 15:36:46 by gaducurt          #+#    #+#             */
/*   Updated: 2025/05/05 18:40:10 by gaducurt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "vector.h"
#include "fdf.h"
#include <math.h>
#include <stdlib.h>

void	ft_zoom(t_vector *vector, t_limits *limits)
{
	int			diff;
	int			factor;
	t_data_fdf	*p;
	size_t		i;

	diff = limits->x_max - limits->x_min;
	if (diff < limits->y_max - limits->y_min)
		diff = limits->y_max - limits->y_min;
	factor = ft_check_zoom(diff);
	i = 0;
	diff *= factor;
	while (i < vector->len)
	{
		p = (t_data_fdf *)((unsigned char *)vector->array
				+ i * vector->size_type);
		p->x *= factor;
		p->y *= factor;
		p->z *= factor;
		ft_iso_matrix(p);
		ft_move_to_zero(limits, p, factor);
		i++;
	}
	ft_middle(vector, diff);
}

void	ft_init_limits(t_limits *limits, t_data_fdf *p, size_t i)
{
	if (i == 0)
	{
		limits->x_min = (p->x * cos(ANGLE))
			+ (p->y * cos(ANGLE + 2)) + (p->z * cos(ANGLE - 2));
		limits->x_max = (p->x * cos(ANGLE))
			+ (p->y * cos(ANGLE + 2)) + (p->z * cos(ANGLE - 2));
		limits->y_min = (p->x * sin(ANGLE))
			+ (p->y * sin(ANGLE + 2)) + (p->z * sin(ANGLE - 2));
		limits->y_max = (p->x * sin(ANGLE))
			+ (p->y * sin(ANGLE + 2)) + (p->z * sin(ANGLE - 2));
	}
	limits->x = (p->x * cos(ANGLE))
		+ (p->y * cos(ANGLE + 2)) + (p->z * cos(ANGLE - 2));
	limits->y = (p->x * sin(ANGLE))
		+ (p->y * sin(ANGLE + 2)) + (p->z * sin(ANGLE - 2));
}

void	ft_diff(t_vector *vector)
{
	t_data_fdf	*p;
	t_limits	limits;
	size_t		i;

	i = 0;
	while (i < vector->len)
	{
		p = (t_data_fdf *)((unsigned char *)vector->array
				+ i * vector->size_type);
		ft_init_limits(&limits, p, i);
		if (limits.x < limits.x_min)
			limits.x_min = limits.x;
		if (limits.x > limits.x_max)
			limits.x_max = limits.x;
		if (limits.y < limits.y_min)
			limits.y_min = limits.y;
		if (limits.y > limits.y_max)
			limits.y_max = limits.y;
		i++;
	}
	ft_zoom(vector, &limits);
}
