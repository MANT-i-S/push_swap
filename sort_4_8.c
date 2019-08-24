/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_4_8.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sholiak <sholiak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/15 17:24:30 by mantis            #+#    #+#             */
/*   Updated: 2019/08/23 18:10:41 by sholiak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char *sort_4_8(t_list *stack_a, t_list *stack_b, t_table *tab, char *str)
{
    int spot;
    int rev_revrot;
    int min;

    min = 1;
    spot = 0;
    while(stack_a && min < 3)
    {
        spot = check_spot(tab, stack_a->node);
        rev_revrot = better_rev(stack_a, tab, min) - better_revrot(stack_a, tab, min);
        if (spot == min && min < 3)
        {
            str = ft_strjoin(str, "pb\n");
            stack_b = pre_pa_pb(stack_a, stack_b);
            stack_a = rm_first_node(stack_a);
			min++;
        }
        else if (rev_revrot > 0)
		{
            str = ft_strjoin(str, "rra\n");
            stack_a = do_rra_rrb(stack_a);
		}
        else if (rev_revrot <= 0)
        {
			str = ft_strjoin(str, "ra\n");
            do_ra_rb(stack_a);
        }
    }
    str = sort_1_3(stack_a, tab, str);
    str = merge(stack_a, stack_b, str);
    return(str);
}

char *merge(t_list *stack_a, t_list *stack_b, char *str)
{
    int len;

    len = node_count(stack_b);
    while(len)
    {
        str = ft_strjoin(str, "pb\n");
        stack_a = pre_pa_pb(stack_b, stack_a);
        stack_b = rm_first_node(stack_b);
        len--;
    }
    printf("%s", str); //remove;
    if(!correct_order(stack_a))//remove;
	error("KO");//remove;
	error("OK");//remove;
    return(str);
}
