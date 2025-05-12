/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_fdf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaducurt <gaducurt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 15:41:24 by gaducurt          #+#    #+#             */
/*   Updated: 2025/05/07 15:38:28 by gaducurt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "vector.h"
#include "fdf.h"

int	ft_clean_exit(t_vector *vector, void *mlx, void *mlx_win, t_data *img)
{
	if (img && img->img && mlx)
		mlx_destroy_image(mlx, img->img);
	if (mlx_win && mlx)
		mlx_destroy_window(mlx, mlx_win);
	if (mlx)
	{
		mlx_destroy_display(mlx);
		free(mlx);
	}
	ft_free_vector(vector);
	exit(1);
}

int	ft_close(t_hook *params)
{
	mlx_destroy_image(params->mlx, params->img->img);
	mlx_destroy_window(params->mlx, params->mlx_win);
	mlx_destroy_display(params->mlx);
	free(params->mlx);
	exit(0);
	return (0);
}

int	ft_exit_free(int keycode, t_hook *params)
{
	if (keycode == 65307)
	{
		ft_close(params);
		return (0);
	}
	return (1);
}

void	ft_fill_params(t_hook *params, void *mlx, void *mlx_win, t_data *img)
{
	params->img = img;
	params->mlx = mlx;
	params->mlx_win = mlx_win;
}
