/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaducurt <gaducurt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 11:44:33 by gaducurt          #+#    #+#             */
/*   Updated: 2025/05/06 11:39:29 by gaducurt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"
#include <math.h>

static int	ft_pos(char c, char *hex_base)
{
	int	i;

	i = 0;
	while (c != hex_base[i])
		i++;
	return (i);
}

int	ft_atoi_inter_base(char *s, char *base, int start, int end)
{
	int	i;
	int	len;
	int	pos;
	int	result;
	int	len_base;

	i = start;
	len = end - start + 1;
	len_base = ft_strlen(base);
	result = 0;
	while (len)
	{
		pos = ft_pos(s[i], base);
		result += pos * ((int)pow(len_base, len - 1));
		len--;
		i++;
	}
	return (result);
}

int	ft_check_color(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if (s[i] == ',')
			return (1);
		i++;
	}
	return (0);
}

int	ft_size_tab(char **s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	ft_return_free(char *line, int fd)
{
	free(line);
	close(fd);
	return (0);
}
