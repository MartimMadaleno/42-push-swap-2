/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_util.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmendes- <mmendes-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 14:21:28 by mmendes-          #+#    #+#             */
/*   Updated: 2023/05/19 14:21:28 by mmendes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	find_biggest_numb(t_list *lst)
{
	t_list	*tmp;
	int		n;

	tmp = lst;
	n = tmp->index;
	while (tmp)
	{
		if (tmp->index > n)
			n = tmp->index;
		tmp = tmp->next;
	}
	return (n);
}

int	find_smallest_numb(t_list *lst)
{
	t_list	*tmp;
	int		n;

	tmp = lst;
	n = tmp->index;
	while (tmp)
	{
		if (tmp->index < n)
			n = tmp->index;
		tmp = tmp->next;
	}
	return (n);
}

int	find_vis(t_list *lst, int numb)
{
	t_list	*tmp;
	int		vis;
	int		dif_vis;

	tmp = lst;
	dif_vis = 1000;
	while (tmp)
	{
		if (dif_vis > tmp->index - numb && tmp->index - numb > 0)
		{
			dif_vis = tmp->index - numb;
			vis = tmp->index;
		}
		tmp = tmp->next;
	}
	return (vis);
}

int	find_media_number(t_list *lst)
{
	int		media;
	int		ind_numb;
	int		op;
	int		new_op;
	int		top_numb;
	t_list	*tmp;

	top_numb = find_biggest_numb(lst);
	media = get_media(lst);
	op = top_numb;
	new_op = 1000;
	tmp = lst;
	while (tmp)
	{
		if (tmp->index <= media && tmp->index <= top_numb - 3)
			new_op = count_numb_op(lst, tmp->index);
		if (new_op < op)
		{
			op = new_op;
			ind_numb = tmp->index;
		}
		tmp = tmp->next;
	}
	return (ind_numb);
}
