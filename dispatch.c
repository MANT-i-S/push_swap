/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dispatch.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sholiak <sholiak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/08 22:00:23 by sholiak           #+#    #+#             */
/*   Updated: 2019/09/02 20:27:03 by sholiak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	read_commands(t_list *stack_a)
{
	int		j;
	char	buff[1];
	char	*str;
	char	**cmd;
	t_list	*stack_b;

	stack_b = NULL;
	cmd = NULL;
	str = ft_strnew(0);
	j = 0;
	while (read(0, buff, 1))
		str = ft_strjoin(str, buff);
	cmd = ft_strsplit(str, '\n');
	ft_strdel(&str);
	while (cmd[j] != NULL)
	{
		if (cmd_c(cmd[j], "sa") && cmd_c(cmd[j], "sb") && cmd_c(cmd[j], "ss")
		&& cmd_c(cmd[j], "pa") && cmd_c(cmd[j], "pb") && cmd_c(cmd[j], "ra")
		&& cmd_c(cmd[j], "rb") && cmd_c(cmd[j], "rr") && cmd_c(cmd[j], "rra")
		&& cmd_c(cmd[j], "rrb") && cmd_c(cmd[j], "rrr"))
			error("Error : Please use correct commands");
		j++;
	}
	j = -1;
	pred(stack_a, stack_b, cmd, j);
}

void	pred(t_list *stack_a, t_list *stack_b, char **cmd, int j)
{
	j++;
	while (cmd[j] != NULL)
	{
		if (!cmd_c(cmd[j], "rrr"))
		{
			stack_a = do_rra_rrb(stack_a);
			stack_b = do_rra_rrb(stack_b);
		}
		else if (!cmd_c(cmd[j], "pa"))
		{
			stack_a = pre_pa_pb(stack_b, stack_a);
			stack_b = rm_first_node(stack_b);
		}
		else
			dis(stack_a, stack_b, cmd, j);
		j++;
	}
	free(cmd);
	if (!correct_order(stack_a) || stack_b)
		error("KO");
	error("OK");
}

void	dis(t_list *stack_a, t_list *stack_b, char **cmd, int j)
{
	if (!cmd_c(cmd[j], "pb"))
	{
		stack_b = pre_pa_pb(stack_a, stack_b);
		stack_a = rm_first_node(stack_a);
	}
	else if (!cmd_c(cmd[j], "sa"))
		do_sa_sb(stack_a);
	else if (!cmd_c(cmd[j], "ra"))
		do_ra_rb(stack_a);
	else if (!cmd_c(cmd[j], "rra"))
		stack_a = do_rra_rrb(stack_a);
	else if (!cmd_c(cmd[j], "sb"))
		do_sa_sb(stack_b);
	else if (!cmd_c(cmd[j], "rb"))
		do_ra_rb(stack_b);
	else if (!cmd_c(cmd[j], "rrb"))
		stack_b = do_rra_rrb(stack_b);
	pred(stack_a, stack_b, cmd, j);
}
