/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dispatch.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sholiak <sholiak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/08 22:00:23 by sholiak           #+#    #+#             */
/*   Updated: 2019/08/09 13:25:52 by sholiak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*dispatch_a(t_list *stack_a, t_list *stack_b, char *str)
{
	if (ft_strcmp(str, "sa"))
	do_sa_sb(stack_a);
	else if (ft_strcmp(str, "pa"))
	{
	pre_pa_pb(stack_a, stack_b);
	stack_a = rm_first_node(stack_a);
	}
	else if (ft_strcmp(str, "ra"))
	do_ra_rb(stack_a);
	else if (ft_strcmp(str, "rr"))
	{
	do_ra_rb(stack_a);
	do_ra_rb(stack_b);
	}
	else if (ft_strcmp(str, "rra"))
	do_rra_rrb(stack_a);
	else if (ft_strcmp(str, "rrr"))
	{
	do_rra_rrb(stack_a);
	do_rra_rrb(stack_b);
	}
	return(stack_a);
}

t_list	*dispatch_b(t_list *stack_a, t_list *stack_b, char *str)
{
	if (ft_strcmp(str, "sb"))
	do_sa_sb(stack_b);
	else if (ft_strcmp(str, "ss"))
	{
	do_sa_sb(stack_a);
	do_sa_sb(stack_b);
	}
	else if (ft_strcmp(str, "pb"))
	{
	pre_pa_pb(stack_b, stack_a);
	stack_b = rm_first_node(stack_b);
	}
	else if (ft_strcmp(str, "rb"))
	do_ra_rb(stack_b);
	else if (ft_strcmp(str, "rrb"))
	do_rra_rrb(stack_b);
	return(stack_b);
}