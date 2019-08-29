/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sholiak <sholiak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/26 15:43:13 by sholiak           #+#    #+#             */
/*   Updated: 2019/08/28 19:53:44 by sholiak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_list	*stack_a;
	int		j[3];

	j[2] = 0;
	stack_a = NULL;
	j[0] = ac - 1;
	if (!cmd_c(av[j[0]], "-v"))
		j[2] = 1;
	if (!cmd_c(av[j[0]], "help"))
		ft_help();
	while (j[0] > 0)
	{
		j[1] = ft_atoi(av[j[0]]);
		stack_a = add_link(stack_a, j[1]);
		if (repeat_check(stack_a, j[1]))
			error("Error : Please don't use same digits");
		j[0]--;
	}
	ft_putstr("Please, enter commands\n");
	read_commands(stack_a, j[2]);
	if (!correct_order(stack_a))
		error("KO");
	error("OK");
	return (0);
}
