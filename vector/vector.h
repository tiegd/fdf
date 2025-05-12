/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaducurt <gaducurt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 18:30:01 by gaducurt          #+#    #+#             */
/*   Updated: 2025/04/24 18:30:59 by gaducurt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

# include <stdlib.h>

# define VECT_SIZE 4

typedef struct s_vector
{
	void	**array;
	size_t	len;
	size_t	size_type;
	size_t	capacity;
}			t_vector;

void	ft_init_vector(t_vector *vector, size_t value_size);
int		ft_realloc_vector(t_vector *vector);
int		ft_vector_addone(t_vector *vector, void *element);
void	ft_free_vector(t_vector *vector);

#endif
