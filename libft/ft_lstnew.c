/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmendes- <mmendes-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 14:16:27 by mmendes-          #+#    #+#             */
/*   Updated: 2023/02/23 14:16:27 by mmendes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_list	*ft_lstnew(int value, int index)
{
	t_list	*strct;

	strct = malloc(sizeof(t_list));
	if (!strct)
		return (NULL);
	strct->value = value;
	strct->index = index;
	strct->tmp = 0;
	strct->next = NULL;
	return (strct);
}
