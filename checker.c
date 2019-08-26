/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sholiak <sholiak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/26 15:43:13 by sholiak           #+#    #+#             */
/*   Updated: 2019/08/26 16:40:31 by sholiak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int ac, char **av)
{
	t_list *stack_a;
	char **str;
	int num = 0;
	int j = 0;

    str = NULL;
	stack_a = NULL;
	j = ac - 1;
	while(j > 0)
	{
        num = ft_atoi(av[j]);
        stack_a = add_link(stack_a, num);
        if (repeat_check(stack_a, num))
	    error("Error : Please don't use same digits");	
        j--;
	}
    ft_putstr("Please, enter commands to change stacks\n");
	str = read_commands(str);
	// if(!correct_order(stack_a))
	// str = better_sort(stack_a, str);
	printf("%s", str[0]); //remove;
    printf("%s", str[1]); //remove;
    printf("%s", str[2]); //remove;
	// if(!correct_order(stack_a))
	// error("KO");
	// error("OK");
	return(0);
}
