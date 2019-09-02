/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sholiak <sholiak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/30 13:49:36 by sholiak           #+#    #+#             */
/*   Updated: 2019/09/02 14:14:15 by sholiak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_list	*stack_a;
	char	**digits;
	int		num;
	int		j;

	j = 0;
	num = 0;
	stack_a = NULL;
	digits = ft_strsplit(av[1], ' ');
	while (digits[j] != NULL)
		j++;
	j--;
	while (j >= 0 && ac == 2)
	{
		num = ft_atoi(digits[j]);
		stack_a = add_link(stack_a, num);
		if (repeat_check(stack_a, num))
			error("Error : Please don't use same digits");
		j--;
	}
	if (!correct_order(stack_a))
		better_sort(stack_a);
	return (0);
}
