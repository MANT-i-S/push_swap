/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sholiak <sholiak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/30 12:30:10 by sholiak           #+#    #+#             */
/*   Updated: 2019/09/02 14:22:11 by sholiak          ###   ########.fr       */
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
	stack_a = NULL;
	if (ac == 2)
		if (!cmd_c(av[1], "-help"))
			ft_help();
	digits = ft_strsplit(av[1], ' ');
	while (digits[j] != NULL)
		j++;
	j--;
	while (j >= 0)
	{
		num = ft_atoi(digits[j]);
		stack_a = add_link(stack_a, num);
		if (repeat_check(stack_a, num))
			error("Error : Please don't use same digits");
		j--;
	}
	if (ac >= 2)
		read_commands(stack_a);
	return (0);
}
