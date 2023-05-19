/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmendes- <mmendes-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 15:38:54 by mmendes-          #+#    #+#             */
/*   Updated: 2023/02/23 15:38:54 by mmendes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"



static void	rotate(t_list **stack)
{
	t_list	*tmp;
	t_list	*tail;

	tmp = *stack;
	*stack = (*stack)->next;
	tail = get_stack_bottom(*stack);
	tmp->next = NULL;
	tail->next = tmp;
}

void	do_ra(t_list **stack_a, t_list **stack_b)
{
	rotate(stack_a);
	printf("ra\n");
}

void	do_rb(t_list **stack_a, t_list **stack_b)
{
	rotate(stack_b);
	printf("rb\n");
}

void	do_rr(t_list **stack_a, t_list **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
	printf("rr\n");
}