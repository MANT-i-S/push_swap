/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sholiak <sholiak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/30 12:30:10 by sholiak           #+#    #+#             */
/*   Updated: 2019/09/02 17:31:28 by sholiak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_list	*stack_a;
	char	**digits;
	int		j[2];

	j[0] = 0;
	stack_a = NULL;
	if (ac == 2)
		if (!cmd_c(av[1], "help"))
			ft_help();
	digits = ft_strsplit(av[1], ' ');
	while (digits[j[0]] != NULL)
		j[0]++;
	j[0]--;
	while (j[0] >= 0)
	{
		ft_strdigits(digits[j[0]]);
		j[1] = ft_atoi(digits[j[0]]);
		stack_a = add_link(stack_a, j[1]);
		if (repeat_check(stack_a, j[1]))
			error("Error : Please don't use same digits");
		j[0]--;
	}
	if (ac >= 2)
		read_commands(stack_a);
	return (0);
}
