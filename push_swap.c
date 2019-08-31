/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sholiak <sholiak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/08 14:54:39 by sholiak           #+#    #+#             */
/*   Updated: 2019/08/30 13:49:45 by sholiak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_list	*stack_a;
	int		num;
	int		j;

	num = 0;
	stack_a = NULL;
	j = ac - 1;
	while (j > 0)
	{
		num = ft_atoi(av[j]);
		stack_a = add_link(stack_a, num);
		if (repeat_check(stack_a, num))
			error("Error : Please don't use same digits");
		j--;
	}
	if (!correct_order(stack_a))
	better_sort(stack_a);
	return (0);
}
