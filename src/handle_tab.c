/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_tab.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaducurt <gaducurt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 14:28:35 by gaducurt          #+#    #+#             */
/*   Updated: 2025/05/07 14:08:57 by gaducurt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"
#include "get_next_line_bonus.h"
#include <unistd.h>

char	**ft_new_tab(int fd)
{
	char	*line;
	char	**double_tab;

	line = get_next_line(fd);
	if (line)
		ft_replace(line);
	double_tab = ft_split(line, ' ');
	free(line);
	if (!double_tab)
		return (NULL);
	return (double_tab);
}

t_len_map	ft_len_map(t_vector *vector)
{
	size_t		i;
	t_data_fdf	*p;
	t_len_map	len;

	i = 0;
	while (i < vector->len)
	{
		p = ((t_data_fdf *)vector->array) + i;
		i++;
	}
	len.lenght = p->x + 1;
	len.width = p->y + 1;
	return (len);
}

void	ft_size_map(t_vector *vector)
{
	size_t		i;
	t_data_fdf	*p;
	t_len_map	len;

	i = 0;
	len = ft_len_map(vector);
	while (i < vector->len)
	{
		p = ((t_data_fdf *)vector->array) + i;
		p->length = len.lenght;
		p->width = len.width;
		i++;
	}
}

int	ft_check_malloc(char **c_tab, int fd, t_vector *vector)
{
	if (!c_tab)
	{
		close(fd);
		if (!vector)
			free(c_tab);
		else
			ft_free_vector(vector);
		exit(1);
	}
	return (0);
}

int	ft_fill_tab(int size, int fd, t_vector *vector)
{
	char		**c_tab;
	t_data_fdf	data;

	ft_init_vector(vector, sizeof(t_data_fdf));
	c_tab = ft_new_tab(fd);
	data.index = 0;
	data.y = 0;
	while (size-- != 0)
	{
		ft_check_malloc(c_tab, fd, vector);
		data.x = 0;
		while (data.x < ft_lentab(c_tab))
		{
			data.z = ft_atoi(c_tab[data.x]);
			ft_fill_color(c_tab[data.x], &data);
			ft_check_add_vector(vector, &data, fd, c_tab);
			data.x++;
			data.index++;
		}
		ft_double_free(c_tab, data.x);
		c_tab = ft_new_tab(fd);
		data.y++;
	}
	ft_size_map(vector);
	return (1);
}
