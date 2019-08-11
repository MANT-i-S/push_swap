/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_commands.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sholiak <sholiak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/08 21:50:56 by sholiak           #+#    #+#             */
/*   Updated: 2019/08/10 20:07:40 by sholiak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**read_commands(char **cmd)
{
	int j;
	char buff[22];

	j = 0;
	while(read(0, buff, 22))
		cmd = ft_strsplit(buff, ' ');
	while (cmd[j] != NULL)
	{
		if(cmd_check(cmd[j], "sa") && cmd_check(cmd[j], "sb") && cmd_check(cmd[j], "ss")
		&& cmd_check(cmd[j], "pa") && cmd_check(cmd[j], "pb") && cmd_check(cmd[j], "ra")
		&& cmd_check(cmd[j], "rb") && cmd_check(cmd[j], "rr") && cmd_check(cmd[j], "rra")
		&& cmd_check(cmd[j], "rrb") && cmd_check(cmd[j], "rrr"))
		error("Please use correct commands");
		j++;
	}
	return(cmd);
}