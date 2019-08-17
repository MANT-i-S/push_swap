/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_4_42.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sholiak <sholiak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/15 17:24:30 by mantis            #+#    #+#             */
/*   Updated: 2019/08/16 20:17:55 by sholiak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char *sort_4_42(t_list *stack_a, char *str)
{
	int len;
	int less;
	int min;
	t_list *stack_b;
	t_list *begin;

	stack_b = NULL;
	len = node_count(stack_a);
    while(len != 1)
    {
		begin = stack_a;
        less = 1;
        min = stack_a->node;
        while(stack_a && less != len)
        {
            if (min < stack_a->node)
            less++;
			stack_a = stack_a->next;
        }
		stack_a = begin;
		if (less == len)
		{
			str = ft_strjoin(str, "pb\n");
            stack_b = pre_pa_pb(stack_a, stack_b);
            stack_a = rm_first_node(stack_a);
			len--;
		}
		else 
		{
			str = ft_strjoin(str, "ra\n");
            do_ra_rb(stack_a);
		}
    }
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
    //print_list(stack_a); //remove;
    return(str);
}