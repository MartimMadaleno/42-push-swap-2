/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkinput.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmendes- <mmendes-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 14:13:07 by mmendes-          #+#    #+#             */
/*   Updated: 2023/02/23 14:13:07 by mmendes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	checkdoubles(char **argv, int i)
{
	int	num;

	num = ft_atoi(argv[i]);
	while (argv[++i])
	{
		if (ft_atoi(argv[i]) == num)
			return (0);
	}
	return (1);
}

int	is_correct_input(char **argv)
{
	int	i;
	int	h;

	i = 0;
	h = -1;
	while (argv[++i])
	{
		h = -1;
		while (argv[i][++h])
		{
			if (argv[i][h] == '-')
				h++;
			if (!ft_isdigit(argv[i][h]))
				return (0);
		}
		if (!checkdoubles(argv, i))
			return (0);
	}
	return (1);
}
