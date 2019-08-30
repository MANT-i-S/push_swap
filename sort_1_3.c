/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_1_3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sholiak <sholiak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/23 16:43:20 by sholiak           #+#    #+#             */
/*   Updated: 2019/08/29 21:31:43 by sholiak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*sort_1_3(t_list *stack_a, t_table *tab, char *str)
{
	int	spot;

	spot = 0;
	make_minisorted(stack_a, tab, node_count(stack_a));
	while (!correct_order(stack_a))
	{
		spot = check_minispot(tab, stack_a->node);
		if (spot == 3)
			str = write_ra(stack_a, str);
		else if (spot == 2)
		{
			str = ft_strjoin(str, "sa\n");
			do_sa_sb(stack_a);
		}
		else if (spot == 1 && check_minispot(tab, stack_a->next->node != 2))
		{
			str = ft_strjoin(str, "sa\n");
			do_sa_sb(stack_a);
			str = ft_strjoin(str, "ra\n");
			do_ra_rb(stack_a);
		}
	}
	return (str);
}
