/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_4.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sholiak <sholiak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 16:27:13 by sholiak           #+#    #+#             */
/*   Updated: 2019/09/06 18:58:59 by sholiak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	write_ra(t_list *stack)
{
	ft_putstr("ra\n");
	do_ra_rb(stack);
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

void	ft_list_free(t_list *stack)
{
	t_list *nextone;

	if (stack)
	{
		while (stack != NULL)
		{
			nextone = stack->next;
			free(stack);
			stack = nextone;
		}
	}
}
