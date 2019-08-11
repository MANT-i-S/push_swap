/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dispatch.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sholiak <sholiak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/08 22:00:23 by sholiak           #+#    #+#             */
/*   Updated: 2019/08/10 20:07:44 by sholiak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*dispatch_a(t_list *stack_a, t_list *stack_b, char **cmd)
{
	if (cmd_check(cmd, "sa"))
	do_sa_sb(stack_a);
	else if (cmd_check(cmd, "pa"))
	{
	pre_pa_pb(stack_a, stack_b);
	stack_a = rm_first_node(stack_a);
	}
	else if (cmd_check(cmd, "ra"))
	do_ra_rb(stack_a);
	else if (cmd_check(cmd, "rr"))
	{
	do_ra_rb(stack_a);
	do_ra_rb(stack_b);
	}
	else if (cmd_check(cmd, "rra"))
	do_rra_rrb(stack_a);
	else if (cmd_check(cmd, "rrr"))
	{
	do_rra_rrb(stack_a);
	do_rra_rrb(stack_b);
	}
	return(stack_a);
}

t_list	*dispatch_b(t_list *stack_a, t_list *stack_b, char **cmd)
{
	if (cmd_check(cmd, "sb"))
	do_sa_sb(stack_b);
	else if (cmd_check(cmd, "ss"))
	{
	do_sa_sb(stack_a);
	do_sa_sb(stack_b);
	}
	else if (cmd_check(cmd, "pb"))
	{
	pre_pa_pb(stack_b, stack_a);
	stack_b = rm_first_node(stack_b);
	}
	else if (cmd_check(cmd, "rb"))
	do_ra_rb(stack_b);
	else if (cmd_check(cmd, "rrb"))
	do_rra_rrb(stack_b);
	return(stack_b);
}