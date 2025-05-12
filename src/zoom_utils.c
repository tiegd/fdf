/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaducurt <gaducurt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 17:18:44 by gaducurt          #+#    #+#             */
/*   Updated: 2025/05/06 18:13:19 by gaducurt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "vector.h"
#include "fdf.h"

void	ft_middle(t_vector *vector, int diff)
{
	size_t		i;
	t_data_fdf	*p;

	i = 0;
	while (i < vector->len)
	{
		p = (t_data_fdf *)((unsigned char *)vector->array
				+ i * vector->size_type);
		p->x = (p->x + (LENGTH / 2 - diff / 2));
		p->y = (p->y + (WIDTH / 2 - diff / 2));
		i++;
	}
}

int	ft_check_zoom(int diff)
{
	int	factor;

	factor = LENGTH * 0.8 / diff;
	while (1)
	{
		if (diff * factor > LENGTH * 0.8)
			factor--;
		if (diff * factor > WIDTH * 0.8)
			factor--;
		else
			return (factor);
	}
}

void	ft_move_to_zero(t_limits *limits, t_data_fdf *p, int factor)
{
	if (limits->x_min != 0)
		p->x -= limits->x_min * factor;
	if (limits->y_min != 0)
		p->y -= limits->y_min * factor;
}
