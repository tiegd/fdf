/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_addone.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaducurt <gaducurt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 15:37:36 by gaducurt          #+#    #+#             */
/*   Updated: 2025/05/06 15:23:27 by gaducurt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

static void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*ndest;
	const char		*nsrc;

	i = 0;
	ndest = dest;
	nsrc = src;
	if (dest == 0 && src == 0)
		return (NULL);
	while (i < n)
	{
		ndest[i] = nsrc[i];
		i++;
	}
	return (dest);
}

int	ft_vector_addone(t_vector *vector, void *element)
{
	if (vector->len == vector->capacity)
		if (!ft_realloc_vector(vector))
			return (0);
	ft_memcpy((unsigned char *)vector->array + vector->len
		* vector->size_type, element, vector->size_type);
	vector->len++;
	return (1);
}
