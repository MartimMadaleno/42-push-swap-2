/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmendes- <mmendes-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 16:59:34 by mmendes-          #+#    #+#             */
/*   Updated: 2023/02/24 16:59:34 by mmendes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	give_tmp(t_list **lst)
{
	t_list	*tmp;
	t_list	*newtmp;

	tmp = (*lst);
	newtmp = (*lst);
	while (tmp)
	{
		tmp->tmp = 0;
		while (newtmp)
		{
			if (tmp->index > newtmp->index)
				tmp->tmp += 1;
			newtmp = newtmp->next;
		}
		tmp = tmp->next;
		newtmp = (*lst);
	}
}

int	count_numb_op(t_list *lst, int numb)
{
	t_list	*tmp;
	int		count_first;
	int		count_last;

	count_first = 0;
	count_last = 0;
	tmp = lst;
	while (tmp->index != numb)
	{
		count_first++;
		tmp = tmp->next;
	}
	while (tmp)
	{
		count_last++;
		tmp = tmp->next;
	}
	if (count_first <= count_last)
		return (count_first);
	else
		return (count_last);
}

int	get_op(t_list *lst, int numb)
{
	t_list	*tmp;
	int		count_first;
	int		count_last;

	count_first = 0;
	count_last = 0;
	tmp = lst;
	while (tmp->index != numb)
	{
		count_first++;
		tmp = tmp->next;
	}
	while (tmp)
	{
		count_last++;
		tmp = tmp->next;
	}
	if (count_first <= count_last)
		return (-1 * count_first);
	else
		return (count_last);
}

void	sort_media_number(t_list **list_a, t_list **list_b)
{
	int	numb;
	int	op;

	numb = find_media_number(*list_a);
	op = get_op(*list_a, numb);
	if (op < 0)
	{
		op *= -1;
		run_function(do_ra, list_a, list_b, op);
	}
	else
		run_function(do_rra, list_a, list_b, op);
	do_pb(list_a, list_b);
}

void	sort_last_b(t_list **list_a, t_list **list_b)
{
	int		moves_a;
	int		moves_b;
	int		total_moves;
	int		moves_a_tmp;
	int		moves_b_tmp;
	int		vis;
	int		tmp_vis;
	t_list	*tmp_b;

	tmp_b = *list_b;
	total_moves = 1000;
	while (tmp_b)
	{
		moves_b_tmp = get_op(*list_b, tmp_b->index);
		tmp_vis = find_vis(*list_a, tmp_b->index);
		moves_a_tmp = get_op(*list_a, tmp_vis);
		if (total_moves > get_positive(moves_a_tmp) + get_positive(moves_b_tmp))
		{
			total_moves = get_positive(moves_a_tmp) + get_positive(moves_b_tmp);
			vis = tmp_vis;
			moves_a = moves_a_tmp;
			moves_b = moves_b_tmp;
		}
		tmp_b = tmp_b->next;
	}
	if (moves_a < 0)
		run_function(do_ra, list_a, list_b, -moves_a);
	else if (moves_a > 0)
		run_function(do_rra, list_a, list_b, moves_a);
	if (moves_b < 0)
		run_function(do_rb, list_a, list_b, -moves_b);
	else if (moves_b > 0)
		run_function(do_rrb, list_a, list_b, moves_b);
	do_pa(list_a, list_b);
}

static void	sort_3(t_list **list_a, t_list **list_b)
{
	if ((*list_a)->tmp == 1)
	{
		if ((*list_a)->next->tmp == 0)
			do_sa(list_a, list_b);
		else if ((*list_a)->next->tmp == 2)
			do_rra(list_a, list_b);
	} 
	else if ((*list_a)->tmp == 2)
	{
		if ((*list_a)->next->tmp == 1)
		{
			do_sa(list_a, list_b);
			do_rra(list_a, list_b);
		}
		else if ((*list_a)->next->tmp == 0)
			do_ra(list_a, list_b);
	} 
	else if ((*list_a)->tmp == 0)
	{
		if ((*list_a)->next->tmp == 2)
		{
			do_sa(list_a, list_b);
			do_ra(list_a, list_b);
		}
	}
}

static void	sort_max(t_list **list_a, t_list **list_b, int argc)
{
	int	op;

	while (get_stack_len(*list_a) != 3)
		sort_media_number(list_a, list_b);
	sort_3(list_a, list_b);
	while (get_stack_len(*list_b) != 0)
		sort_last_b(list_a, list_b);
	op = get_op(*list_a, find_smallest_numb(*list_a));
	if (op < 0)
		run_function(do_ra, list_a, list_b  , -op);
	else if (op != 0)
		run_function(do_rra, list_a, list_b , op);
}

void	sort(int argc, t_list **list_a, t_list **list_b)
{
	if (argc < 5)
		sort_3(list_a, list_b);
	else
		sort_max(list_a, list_b, argc);
}
