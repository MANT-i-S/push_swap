/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sholiak <sholiak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/08 14:55:23 by sholiak           #+#    #+#             */
/*   Updated: 2019/09/03 16:34:59 by sholiak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_sa_sb(t_list *stack)
{
	int tmp;

	if (stack)
		tmp = stack->node;
	if (stack->next != NULL)
	{
		stack->node = stack->next->node;
		stack = stack->next;
		stack->node = tmp;
	}
}

t_list	*rm_first_node(t_list *stack)
{
	t_list *toremove;

	toremove = stack;
	if (stack)
	{
		if (stack->next != NULL)
			stack = stack->next;
		free(toremove);
		if (stack->next == NULL)
			return (0);
	}
	return (stack);
}

t_list	*pre_pa_pb(t_list *stack_a, t_list *stack_b)
{
	if (stack_a)
	{
		stack_b = add_link(stack_b, stack_a->node);
		return (stack_b);
	}
	return (stack_b);
}

void	do_ra_rb(t_list *stack)
{
	int first;
	int mid;

	if (stack)
	{
		first = stack->node;
		while (stack->next != NULL)
		{
			mid = stack->node;
			stack->node = stack->next->node;
			stack = stack->next;
			stack->node = mid;
		}
		stack->node = first;
	}
}

t_list	*do_rra_rrb(t_list *stack)
{
	int		last;
	t_list	*firstnode;

	if (stack)
	{
		firstnode = stack;
		if (stack->next != NULL)
		{
			while (stack->next->next != NULL)
				stack = stack->next;
			last = stack->next->node;
			stack->next = NULL;
			stack = firstnode;
			stack = add_link(stack, last);
		}
	}
	return (stack);
}
