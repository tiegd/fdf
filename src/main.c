/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaducurt <gaducurt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 18:01:52 by gaducurt          #+#    #+#             */
/*   Updated: 2025/05/12 10:23:20 by gaducurt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <fcntl.h>
#include <stdlib.h>
#include "libft.h"
#include "vector.h"
#include <unistd.h>

int	ft_close_fd(int fd)
{
	close(fd);
	return (1);
}

int	ft_putstr_error(char *s, int fd)
{
	write(fd, s, ft_strlen(s));
	return (1);
}

int	main(int ac, char **av)
{
	int			fd;
	int			size;
	t_vector	*vector;

	if (ac != 2)
		return (ft_putstr_error(
				"Error : The process need to take one file in input\n", 2));
	if (!ft_check_format(av[1]) || !ft_check_map(av[1], 1))
		return (ft_putstr_error("Error : The file is not valid\n", 2));
	size = ft_check_map(av[1], 1);
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
		return (1);
	vector = malloc(sizeof(t_vector));
	if (!vector)
		return (ft_close_fd(fd));
	if (ft_fill_tab(size, fd, vector))
	{
		close(fd);
		ft_init_win(vector);
	}
	return (0);
}
