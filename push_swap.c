/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sholiak <sholiak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/08 14:54:39 by sholiak           #+#    #+#             */
/*   Updated: 2019/08/09 13:25:48 by sholiak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*push_swap(t_list *stack_a)
{
	t_list *stack_b;

	stack_b = NULL;
	print_list(stack_a);
	do_rra_rrb(stack_a);
	printf("%s\n", "-------------");
	print_list(stack_a);
	return(0);
}
