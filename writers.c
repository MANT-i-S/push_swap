/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   writers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sholiak <sholiak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/28 20:48:38 by sholiak           #+#    #+#             */
/*   Updated: 2019/08/29 16:27:35 by sholiak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*write_ra(t_list *stack, char *str)
{
	str = ft_strjoin(str, "ra\n");
	do_ra_rb(stack);
	return(str);
}

t_list	*write_pa_pb(t_list *stack_a, t_list *stack_b, char *str)
{
	str = ft_strjoin(str, "pb\n");
	stack_b = pre_pa_pb(stack_a, stack_b);
	return(stack_b);
}

void	write_sa_sb(t_list *stack, char *str)
{
	str = ft_strjoin(str, "sb\n");
	do_sa_sb(stack);
}

void	write_rb(t_list *stack, char *str)
{
	str = ft_strjoin(str, "rb\n");
	do_ra_rb(stack);
}

t_list	*write_rra_rrb(t_list *stack, char *str)
{
	str = ft_strjoin(str, "rra\n");
	stack = do_rra_rrb(stack);
	return(stack);
}