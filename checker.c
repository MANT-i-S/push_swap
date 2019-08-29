/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sholiak <sholiak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/26 15:43:13 by sholiak           #+#    #+#             */
/*   Updated: 2019/08/28 17:49:34 by sholiak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int ac, char **av)
{
	t_list *stack_a;
	char **cmd;
	int num = 0;
	int j = 0;
	int debug;
    
	debug = 0;
    cmd = NULL;
	stack_a = NULL;
	j = ac - 1;
	if (!cmd_check(av[j], "-v"))
	debug = 1;
	if (!cmd_check(av[j], "help"))
	ft_help();
	while(j > 0)
	{
        num = ft_atoi(av[j]);
        stack_a = add_link(stack_a, num);
        if (repeat_check(stack_a, num))
	    error("Error : Please don't use same digits");
        j--;
	}
    ft_putstr("Please, enter commands\n");
	read_commands(stack_a, cmd, debug);
	if(!correct_order(stack_a))
	error("KO");
	error("OK");
	return(0);
}
