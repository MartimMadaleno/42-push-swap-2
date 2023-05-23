/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmendes- <mmendes-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 14:17:52 by mmendes-          #+#    #+#             */
/*   Updated: 2023/02/23 14:17:52 by mmendes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	give_index(int num, char **argv)
{
	int	h;
	int	index;

	h = 0;
	index = 0;
	while (argv[++h])
	{
		if (num > ft_atoi(argv[h]))
			index++;
	}
	return (index);
}

t_list	*fill_list_a(t_list *list_a, char **argv)
{
	int	i;

	i = 1;
	list_a = ft_lstnew(ft_atoi(argv[i]), give_index(ft_atoi(argv[i]), argv));
	while (argv[++i])
	{
		ft_lstadd_back(list_a, ft_lstnew(ft_atoi(argv[i]),
				give_index(ft_atoi(argv[i]), argv)));
	}
	return (list_a);
}
