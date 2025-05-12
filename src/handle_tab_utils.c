/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_tab_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaducurt <gaducurt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 15:49:40 by gaducurt          #+#    #+#             */
/*   Updated: 2025/05/06 17:04:20 by gaducurt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <unistd.h>

int	ft_lentab(char **c_tab)
{
	int	i;

	i = 0;
	while (c_tab[i])
		i++;
	return (i);
}

void	ft_double_free(char **s, int nb_word)
{
	int	i;

	i = 0;
	while (i < nb_word + 1)
	{
		free(s[i]);
		i++;
	}
	free(s);
}

void	ft_replace(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == '\n')
			line[i] = ' ';
		i++;
	}
}

int	ft_check_add_vector(t_vector *vector, t_data_fdf *data,
		int fd, char **c_tab)
{
	int	i;

	i = 0;
	while (c_tab[i])
		i++;
	if (!ft_vector_addone(vector, data))
	{
		close(fd);
		ft_double_free(c_tab, i);
		exit(1);
	}
	return (0);
}
