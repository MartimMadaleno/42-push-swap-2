/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   times_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmendes- <mmendes-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 14:19:00 by mmendes-          #+#    #+#             */
/*   Updated: 2023/02/27 14:19:00 by mmendes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	run_function(t_func_ptr func, t_list **stack_a,
			t_list **stack_b, int times)
{
	int	i;

	i = 0;
	while (i < times)
	{
		func(stack_a, stack_b);
		i++;
	}
}
