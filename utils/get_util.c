/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_util.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmendes- <mmendes-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 14:12:03 by mmendes-          #+#    #+#             */
/*   Updated: 2023/05/19 14:12:03 by mmendes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_list	*get_stack_bottom(t_list *lst)
{
	while (lst && lst->next != NULL)
		lst = lst->next;
	return (lst);
}

t_list	*get_stack_before_bottom(t_list *lst)
{
	while (lst && lst->next && lst->next->next != NULL)
		lst = lst->next;
	return (lst);
}

int getPositive(int num)
{
    if (num < 0) {
        return -num;
    } else {
        return num;
    }
}

int get_media(t_list *lst)
{
	t_list *tmp;
	int media;
	int count;

	tmp = lst;
	media = 0;
	count = 0;
	while(tmp)
	{
		media += tmp->index;
		count++;
		tmp = tmp->next;
	}
	media /= count;
	return media;
}

int get_stack_len(t_list *lst)
{
	t_list *tmp;
	int count;

	tmp = lst;
	count = 0;
	while(tmp)
	{
		count++;
		tmp = tmp->next;
	}
	return count;
}