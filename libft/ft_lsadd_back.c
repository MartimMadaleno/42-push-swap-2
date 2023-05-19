/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lsadd_back.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmendes- <mmendes-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 14:15:47 by mmendes-          #+#    #+#             */
/*   Updated: 2023/02/23 14:15:47 by mmendes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_lstadd_back(t_list *lst, t_list *new)
{
	t_list	*last;

	last = lst;
	while (last->next)
		last = last->next;
	last->next = new;
}
