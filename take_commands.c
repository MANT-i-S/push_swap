/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_commands.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sholiak <sholiak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/08 21:50:56 by sholiak           #+#    #+#             */
/*   Updated: 2019/08/10 16:57:21 by sholiak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	int j;

	j = 1;
	if (ac < 2)
	return(error("Please enter operator commands"));
	while (j < ac)
	{
		if(ft_strcmp(av[j], "sa") && ft_strcmp(av[j], "sb") && ft_strcmp(av[j], "ss")
		&& ft_strcmp(av[j], "pa") && ft_strcmp(av[j], "pb") && ft_strcmp(av[j], "ra")
		&& ft_strcmp(av[j], "rb") && ft_strcmp(av[j], "rr") && ft_strcmp(av[j], "rra")
		&& ft_strcmp(av[j], "rrb") && ft_strcmp(av[j], "rrr"))
		return(error("Please use correct commands"));
		//store into the file. Plans changed xD Store eather store into array or take it as an input..
		j++;
	}
	return(0);
}