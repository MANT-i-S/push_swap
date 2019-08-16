/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mantis <mantis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 19:31:31 by sholiak           #+#    #+#             */
/*   Updated: 2019/08/15 18:09:47 by mantis           ###   ########.fr       */
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
	    error("Please don't use same digits");
        j--;
	}
	//stack_a = read_digits(stack_a);
	print_list(stack_a);
	if(!correct_order(stack_a))
	str = just_sort(stack_a, str);
	printf("%s", str);
	error("OK");
	return(0);
}
