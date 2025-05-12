/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaducurt <gaducurt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 17:30:30 by gaducurt          #+#    #+#             */
/*   Updated: 2025/05/07 14:09:09 by gaducurt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "get_next_line_bonus.h"
#include "libft.h"
#include "vector.h"

int	ft_check_format(char *str)
{
	int	i;
	int	j;

	i = 0;
	while (str[i])
		i++;
	j = i - 4;
	if (str[j] == '.' && str[j + 1] == 'f' && str[j + 2] == 'd'
		&& str[j + 3] == 'f')
		return (1);
	return (0);
}

static int	ft_count_word(char *s)
{
	int	nb_word;
	int	i;

	nb_word = 0;
	i = 0;
	while (s[i])
	{
		while ((s[i] && s[i] == ' ') || (s[i] == '\n'))
			i++;
		if ((s[i] && s[i] != ' ') && (s[i] != '\n'))
			nb_word++;
		while (s[i] && s[i] != ' ')
			i++;
	}
	return (nb_word);
}

static int	ft_only_num(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (ft_isdigit(s[i]) || (s[i] == ' ') || (s[i] == '-') || (s[i] == '\n')
			|| (s[i] == ',') || (s[i] == 'x') || (s[i] >= 'A' && s[i] <= 'F')
			|| (s[i] >= 'a' && s[i] <= 'f'))
			i++;
		else
			return (0);
	}
	return (1);
}

int	ft_check_map(char *file, int size)
{
	int		len;
	char	*line;
	int		fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (0);
	line = get_next_line(fd);
	if (!line)
		return (0);
	len = ft_count_word(line);
	free(line);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if ((ft_count_word(line) != len) || (!ft_only_num(line)))
			return (ft_return_free(line, fd));
		free(line);
		size++;
	}
	close(fd);
	return (size);
}

void	ft_fill_color(char *s, t_data_fdf *data)
{
	char	**tab;
	char	*base;
	int		i;
	int		len;

	i = 0;
	base = "0123456789ABCDEF";
	if (ft_check_color(s))
	{
		tab = ft_split(s, ',');
		len = ft_strlen(tab[1]);
		while (tab[1][i])
		{
			if (tab[1][i] >= 'a' && tab[1][i] <= 'f')
				tab[1][i] -= 32;
			i++;
		}
		data->color = ft_atoi_inter_base(tab[1], base, 2, len - 1);
		data->z = ft_atoi(tab[0]);
		ft_double_free(tab, 1);
	}
	else
		data->color = 16777215;
}
