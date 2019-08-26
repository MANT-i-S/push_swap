/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_commands.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sholiak <sholiak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/08 21:50:56 by sholiak           #+#    #+#             */
/*   Updated: 2019/08/26 16:54:58 by sholiak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**read_commands(char **cmd)
{
	int j;

	j = 0;
	while(get_next_line(0, cmd))
	while (cmd[j] != NULL)
	{
		if(cmd_check(cmd[j], "sa") && cmd_check(cmd[j], "sb") && cmd_check(cmd[j], "ss")
		&& cmd_check(cmd[j], "pa") && cmd_check(cmd[j], "pb") && cmd_check(cmd[j], "ra")
		&& cmd_check(cmd[j], "rb") && cmd_check(cmd[j], "rr") && cmd_check(cmd[j], "rra")
		&& cmd_check(cmd[j], "rrb") && cmd_check(cmd[j], "rrr"))
		error("Error : Please use correct commands");
		j++;
	}
	return(cmd);
}