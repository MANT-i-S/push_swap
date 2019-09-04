/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sholiak <sholiak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/30 12:30:10 by sholiak           #+#    #+#             */
/*   Updated: 2019/09/04 16:08:34 by sholiak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		main(int ac, char **av)
{
	t_list	*stack_a;
	char	**digits;
	t_table *tab;
	int		j;

	tab = (t_table *)malloc(sizeof(t_table));
	j = 0;
	stack_a = NULL;
	if (ac == 2 && !cmd_c(av[1], "-help"))
		ft_help();
	if (ac == 3 && !cmd_c(av[2], "-v"))
		tab->debug = 1;
	if (ac == 2 && !cmd_c(av[1], "-use"))
		ft_use();
	digits = ft_strsplit(av[1], ' ');
	if (ac >= 2)
		checker(stack_a, tab, digits);
	return (0);
}

void	checker(t_list *stack_a, t_table *tab, char **digits)
{
	int num;
	int j;

	j = 0;
	while (digits[j] != NULL)
		j++;
	j--;
	while (j >= 0)
	{
		ft_strdigits(digits[j]);
		if (ft_strlen(digits[j]) > 9)
			error("Error : Reached integer limit, use digits closer to 0");
		num = ft_atoi(digits[j]);
		stack_a = add_link(stack_a, num);
		if (repeat_check(stack_a, num))
			error("Error : Please don't use same digits");
		j--;
	}
	ft_strdel(digits);
	ft_putstr("Please enter commands, for list use |./checker -help|\n");
	read_commands(stack_a, tab);
}

void	ft_use(void)
{
	ft_putstr("|ARG=\"replace with digits\"; ./push_swap $ARG | ./checker $ARG|\n");
	ft_putstr("|To process 2 exe together				     |\n");
	ft_putstr("|ARG=\"replace with digits\"; ./push_swap $ARG		     |\n");
	ft_putstr("|To see output of push_swap which suppose to sort stack	     |\n");
	ft_putstr("|ARG=\"replace with digits\"; ./checker $ARG		     |\n");
	ft_putstr("|To see if checker works enter comands after request	     |\n");
	error("|^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^|");
}