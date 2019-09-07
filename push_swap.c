/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sholiak <sholiak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/30 13:49:36 by sholiak           #+#    #+#             */
/*   Updated: 2019/09/06 19:16:43 by sholiak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		main(int ac, char **av)
{
	t_list	*stack_a;
	char	**digits;

	stack_a = NULL;
	digits = ft_strsplit(av[1], ' ');
	if (ac == 2)
		push_swap(stack_a, digits);
	return (0);
}

void	push_swap(t_list *stack_a, char **digits)
{
	int j;
	int num;

	j = 0;
	while (digits[j] != NULL)
		j++;
	j--;
	while (j >= 0)
	{
		ft_strdigits(digits[j]);
		num = ft_atoi(digits[j]);
		stack_a = add_link(stack_a, num);
		if (repeat_check(stack_a, num))
			error("Error : Please don't use same digits");
		j--;
	}
	ft_strdel(digits);
	if (!correct_order(stack_a))
		better_sort(stack_a);
}
