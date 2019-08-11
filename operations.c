/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sholiak <sholiak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/08 14:55:23 by sholiak           #+#    #+#             */
/*   Updated: 2019/08/08 22:26:16 by sholiak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_sa_sb(t_list *stack)
{
	int tmp;

	if (stack->node)
	tmp = stack->node;
	if (stack->next != NULL)
	{
	stack->node = stack->next->node;
	stack = stack->next;
	stack->node = tmp;
	}
}

t_list *rm_first_node(t_list *stack)
{
	t_list *toremove;

	toremove = stack;
	stack = stack->next;
	free(toremove);
	return(stack);
}

t_list	*pre_pa_pb(t_list *stack_a, t_list *stack_b)
{
	if (stack_a->node)
	{
	stack_b = add_link(stack_b, stack_a->node);
	return(stack_b);
	}
	return (stack_b);
}

void	do_ra_rb(t_list *stack)
{
	int first;
	int mid;

	if(stack->node)
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

void	do_rra_rrb(t_list *stack)
{
	int mid;
	int midnext;
	t_list *firstnode;

	midnext = 0;
	firstnode = stack;
	if(stack->node)
	while (stack->next != NULL)
	{
		mid = stack->node;
		stack->node = midnext;
		stack = stack->next;
		midnext = stack->node;
		stack->node = mid;
		if(stack->next != NULL)
		stack = stack->next;
	}
	stack = firstnode;
	stack->node = midnext;
}