/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dispatch.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sholiak <sholiak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/08 22:00:23 by sholiak           #+#    #+#             */
/*   Updated: 2019/09/04 15:47:14 by sholiak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	read_commands(t_list *stack_a, t_table *tab)
{
	int		j;
	char	buff[1];
	char	*str;
	char	**cmd;
	t_list	*s_b;

	s_b = NULL;
	cmd = NULL;
	str = ft_strnew(0);
	j = 0;
	while (read(0, buff, 1))
		str = ft_strcat(str, buff);
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
	tab->j = 0;
	pre(stack_a, s_b, tab, cmd);
}

void	pre(t_list *stack_a, t_list *s_b, t_table *tab, char **cmd)
{
	while (cmd[tab->j] != NULL)
	{
		if (!cmd_c(cmd[tab->j], "rrr"))
		{
			stack_a = do_rra_rrb(stack_a);
			s_b = do_rra_rrb(s_b);
		}
		else if (!cmd_c(cmd[tab->j], "pa"))
		{
			stack_a = pre_pa_pb(s_b, stack_a);
			s_b = rm_first_node(s_b);
		}
		else
			dis(stack_a, s_b, tab, cmd);
		if (tab->debug)
			print_list(stack_a, s_b);
		tab->j++;
	}
	ft_strdel(cmd);
	if (!correct_order(stack_a) || s_b)
		errorko();
	errorok();
}

void	dis(t_list *stack_a, t_list *s_b, t_table *tab, char **cmd)
{
	if (!cmd_c(cmd[tab->j], "pb"))
	{
		s_b = pre_pa_pb(stack_a, s_b);
		stack_a = rm_first_node(stack_a);
	}
	else if (!cmd_c(cmd[tab->j], "sa"))
		do_sa_sb(stack_a);
	else if (!cmd_c(cmd[tab->j], "ra"))
		do_ra_rb(stack_a);
	else if (!cmd_c(cmd[tab->j], "rra"))
		stack_a = do_rra_rrb(stack_a);
	else if (!cmd_c(cmd[tab->j], "sb"))
		do_sa_sb(s_b);
	else if (!cmd_c(cmd[tab->j], "rb"))
		do_ra_rb(s_b);
	else if (!cmd_c(cmd[tab->j], "rrb"))
		s_b = do_rra_rrb(s_b);
	if (tab->debug)
		print_list(stack_a, s_b);
	tab->j++;
	pre(stack_a, s_b, tab, cmd);
}

void	errorko(void)
{
	printf("\033[0;31m");
	printf("%s\n", "KO");
	exit(1);
}

void	errorok(void)
{
	printf("\033[0;32m");
	printf("%s\n", "OK");
	exit(1);
}
