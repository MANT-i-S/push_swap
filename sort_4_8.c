/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_4_8.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sholiak <sholiak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/15 17:24:30 by mantis            #+#    #+#             */
/*   Updated: 2019/09/06 18:58:21 by sholiak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_4_8(t_list *stack_a, t_list *stack_b, t_table *tab)
{
	int i[3];

	i[1] = 1;
	while (stack_a && i[1] < 3)
	{
		i[0] = check_spot(tab, stack_a->node);
		i[2] = rev(stack_a, tab, i[1]) - revrot(stack_a, tab, i[1]);
		if (i[0] == i[1] && i[1] < 3)
		{
			ft_putstr("pb\n");
			stack_b = pre_pa_pb(stack_a, stack_b);
			stack_a = rm_first_node(stack_a);
			i[1]++;
		}
		else if (i[2] > 0)
		{
			ft_putstr("rra\n");
			stack_a = do_rra_rrb(stack_a);
		}
		else if (i[2] <= 0)
			write_ra(stack_a);
	}
	sort_1_3(stack_a, tab);
	merge_stacks(stack_a, stack_b);
}

int		pre_merg(t_list *stack_a, t_list *stack_b, t_table *tab)
{
	int spot;

	spot = 0;
	while (spot != tab->len && stack_b)
	{
		spot = check_spot(tab, stack_b->node);
		if (spot == tab->len)
		{
			merge_stacks(stack_a, stack_b);
			return (1);
		}
		ft_putstr("rb\n");
		do_ra_rb(stack_b);
	}
	return (0);
}

void	merge_stacks(t_list *stack_a, t_list *stack_b)
{
	int len;

	len = node_count(stack_b);
	while (len)
	{
		ft_putstr("pa\n");
		stack_a = pre_pa_pb(stack_b, stack_a);
		stack_b = rm_first_node(stack_b);
		len--;
	}
	exit(1);
}
