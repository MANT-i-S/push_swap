/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_1_3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sholiak <sholiak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/23 16:43:20 by sholiak           #+#    #+#             */
/*   Updated: 2019/09/06 19:03:32 by sholiak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_1_3(t_list *stack_a, t_table *tab)
{
	make_minisorted(stack_a, tab, node_count(stack_a));
	while (!correct_order(stack_a))
	{
		tab->spot = minispot(tab, stack_a->node);
		if (tab->spot == 3)
			write_ra(stack_a);
		else if (tab->spot == 2)
		{
			ft_putstr("sa\n");
			do_sa_sb(stack_a);
		}
		else if (tab->spot == 1 && minispot(tab, stack_a->next->node != 2))
		{
			ft_putstr("sa\n");
			do_sa_sb(stack_a);
			ft_putstr("ra\n");
			do_ra_rb(stack_a);
		}
	}
	if (tab->notfree != 1)
		ft_list_free(stack_a);
}
