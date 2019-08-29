/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_commands.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sholiak <sholiak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/08 21:50:56 by sholiak           #+#    #+#             */
/*   Updated: 2019/08/28 17:36:27 by sholiak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	read_commands(t_list *stack_a, char **cmd, int debug)
{
	int j;
	char buff[1];
	char *str;

	str = ft_strnew(0);
	j = 0;
	while(read(0, buff, 1))
	str = ft_strjoin(str, buff);
	cmd = ft_strsplit(str, '\n');
	ft_strdel(&str);
	while (cmd[j] != NULL)
	{
		if(cmd_check(cmd[j], "sa") && cmd_check(cmd[j], "sb") && cmd_check(cmd[j], "ss")
		&& cmd_check(cmd[j], "pa") && cmd_check(cmd[j], "pb") && cmd_check(cmd[j], "ra")
		&& cmd_check(cmd[j], "rb") && cmd_check(cmd[j], "rr") && cmd_check(cmd[j], "rra")
		&& cmd_check(cmd[j], "rrb") && cmd_check(cmd[j], "rrr"))
		error("Error : Please use correct commands");
		j++;
	}
	pre_dispatch(stack_a, cmd, debug);
}