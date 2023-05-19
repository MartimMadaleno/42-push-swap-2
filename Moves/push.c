/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmendes- <mmendes-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 15:36:31 by mmendes-          #+#    #+#             */
/*   Updated: 2023/02/23 15:36:31 by mmendes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	push(t_list **src, t_list **dest)
{
	t_list	*tmp;

	if (*src == NULL)
		return ;
	tmp = (*src)->next;
	(*src)->next = *dest;
	*dest = *src;
	*src = tmp;
}

/* do_pa:
*	Pushes the top element of stack b to the top of stack a.
*	Prints "pa" to the standard output.
*/
void	do_pa(t_list **stack_a, t_list **stack_b)
{
	push(stack_b, stack_a);
	printf("pa\n");
}

/* do_pb:
*	Pushes the top element of stack a to the top of stack b.
*	Prints "pb" to the standard output.
*/
void	do_pb(t_list **stack_a, t_list **stack_b)
{
	push(stack_a, stack_b);
	printf("pb\n");
}