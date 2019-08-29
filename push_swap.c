/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sholiak <sholiak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/08 14:54:39 by sholiak           #+#    #+#             */
/*   Updated: 2019/08/28 17:53:50 by sholiak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int ac, char **av)
{
	t_list *stack_a;
	char *str;
	int num = 0;
	int j = 0;

	str = ft_strnew(0);
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
	if(!correct_order(stack_a))
	str = better_sort(stack_a, str);
	ft_putstr(str);
	return(0);
}
