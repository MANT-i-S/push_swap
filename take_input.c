/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sholiak <sholiak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 19:31:31 by sholiak           #+#    #+#             */
/*   Updated: 2019/08/18 21:04:10 by sholiak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int ac, char **av)
{
	t_list *stack_a;
	char *str;
	int num = 0;
	int j = 0;
	int len = 0; //remove

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
	//stack_a = read_digits(stack_a);
	len = node_count(stack_a);
	//printf("%d\n", len); //remove;
	if(!correct_order(stack_a))
	str = sort_with_better_check(stack_a, str);
	printf("%s", str); // remove;
	//if(!correct_order(stack_a))
	//error("KO");
	error("OK");
	return(0);
}
