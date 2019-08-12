/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sholiak <sholiak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 19:31:31 by sholiak           #+#    #+#             */
/*   Updated: 2019/08/11 18:43:26 by sholiak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int ac, char **av)
{
	t_list *stack_a;

	stack_a = NULL;
	stack_a = read_digits(stack_a);
	print_list(stack_a);
	if(!correct_order(stack_a))
	stack_a = push_swap(stack_a);
	//error("KO");//push-swap. then OK/KO;
	error("OK");
	retunr(0);
}
