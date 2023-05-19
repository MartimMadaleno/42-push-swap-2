/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmendes- <mmendes-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 14:15:10 by mmendes-          #+#    #+#             */
/*   Updated: 2023/02/23 14:15:10 by mmendes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	*ft_calloc(size_t nitems, size_t size)
{
	void	*p;

	p = malloc(nitems * size);
	if (!p)
		return (NULL);
	ft_bzero(p, nitems * size);
	return (p);
}
