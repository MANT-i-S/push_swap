/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dispatch.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sholiak <sholiak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/08 22:00:23 by sholiak           #+#    #+#             */
/*   Updated: 2019/08/28 17:36:35 by sholiak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pre_dispatch(t_list *stack_a, char **cmd, int debug)
{
	int j;
	t_list *stack_b;

	stack_b = NULL;
	j = 0;
	while (cmd[j] != NULL)
	{
		if(!cmd_check(cmd[j], "sa") || !cmd_check(cmd[j], "pa") || !cmd_check(cmd[j], "ra")
		|| !cmd_check(cmd[j], "rr") || !cmd_check(cmd[j], "rra"))
		stack_a = dispatch_a(stack_a, stack_b, cmd, j);
		else if(!cmd_check(cmd[j], "sb") || !cmd_check(cmd[j], "ss") || !cmd_check(cmd[j], "pb")
		|| !cmd_check(cmd[j], "rb") || !cmd_check(cmd[j], "rrb"))
		stack_b = dispatch_b(stack_a, stack_b, cmd, j);
		else if (!cmd_check(cmd[j], "rrr"))
		{
		stack_a = do_rra_rrb(stack_a);
		stack_b = do_rra_rrb(stack_b);
		}
		if(debug)
		{
		ft_putstr("-\n");
		print_list(stack_a);
		}
		j++;
	}
}

t_list	*dispatch_a(t_list *stack_a, t_list *stack_b, char **cmd, int j)
{
	if (!cmd_check(cmd[j], "sa"))
	do_sa_sb(stack_a);
	else if (!cmd_check(cmd[j], "pa"))
	{
	stack_a = pre_pa_pb(stack_a, stack_b);
	stack_a = rm_first_node(stack_a);
	}
	else if (!cmd_check(cmd[j], "ra"))
	do_ra_rb(stack_a);
	else if (!cmd_check(cmd[j], "rr"))
	{
	do_ra_rb(stack_a);
	do_ra_rb(stack_b);
	}
	else if (!cmd_check(cmd[j], "rra"))
	stack_a = do_rra_rrb(stack_a);
	return(stack_a);
}

t_list	*dispatch_b(t_list *stack_a, t_list *stack_b, char **cmd, int j)
{
	if (!cmd_check(cmd[j], "sb"))
	do_sa_sb(stack_b);
	else if (!cmd_check(cmd[j], "ss"))
	{
	do_sa_sb(stack_a);
	do_sa_sb(stack_b);
	}
	else if (!cmd_check(cmd[j], "pb"))
	{
	stack_b = pre_pa_pb(stack_b, stack_a);
	stack_b = rm_first_node(stack_b);
	}
	else if (!cmd_check(cmd[j], "rb"))
	do_ra_rb(stack_b);
	else if (!cmd_check(cmd[j], "rrb"))
	stack_b = do_rra_rrb(stack_b);
	return(stack_b);
}