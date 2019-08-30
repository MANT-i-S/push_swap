/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_4_8.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sholiak <sholiak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/15 17:24:30 by mantis            #+#    #+#             */
/*   Updated: 2019/08/29 21:41:48 by sholiak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*sort_4_8(t_list *stack_a, t_list *stack_b, t_table *tab, char *str)
{
	int i[3];

	i[1] = 1;
	while (stack_a && i[1] < 3)
	{
		i[0] = check_spot(tab, stack_a->node);
		i[2] = rev(stack_a, tab, i[1]) - revrot(stack_a, tab, i[1]);
		if (i[0] == i[1] && i[1] < 3)
		{
			str = ft_strjoin(str, "pb\n");
			stack_b = pre_pa_pb(stack_a, stack_b);
			stack_a = rm_first_node(stack_a);
			i[1]++;
		}
		else if (i[2] > 0)
		{
			str = ft_strjoin(str, "rra\n");
			stack_a = do_rra_rrb(stack_a);
		}
		else if (i[2] <= 0)
			str = write_ra(stack_a, str);
	}
	str = sort_1_3(stack_a, tab, str);
	str = merge_stacks(stack_a, stack_b, str);
	return (str);
}

char	*pre_merg(t_list *stack_a, t_list *stack_b, t_table *tab, char *str)
{
	int spot;

	spot = 0;
	while (spot != tab->len)
	{
		spot = check_spot(tab, stack_b->node);
		if (spot == tab->len)
		{
			str = merge_stacks(stack_a, stack_b, str);
			return (str);
		}
		str = ft_strjoin(str, "ra\n");
		do_ra_rb(stack_b);
	}
	return (str);
}

char	*merge_stacks(t_list *stack_a, t_list *stack_b, char *str)
{
	int len;

	len = node_count(stack_b);
	while (len)
	{
		str = ft_strjoin(str, "pa\n");
		stack_a = pre_pa_pb(stack_b, stack_a);
		stack_b = rm_first_node(stack_b);
		len--;
	}
	return (str);
}

char	*write_ra(t_list *stack, char *str)
{
	str = ft_strjoin(str, "ra\n");
	do_ra_rb(stack);
	return (str);
}
