/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_commands.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sholiak <sholiak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/08 21:50:56 by sholiak           #+#    #+#             */
/*   Updated: 2019/08/28 20:03:34 by sholiak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	read_commands(t_list *stack_a, int debug)
{
	int		j;
	char	buff[1];
	char	*str;
	char	**cmd;

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
	pre_dispatch(stack_a, cmd, debug);
}
