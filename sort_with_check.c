/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_with_check.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sholiak <sholiak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/17 17:48:03 by sholiak           #+#    #+#             */
/*   Updated: 2019/08/17 18:13:46 by sholiak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char *sort_with_check(t_list *stack_a, char *str)
{
	int len;
	int less;
	int min;
	t_list *stack_b;
	t_list *begin;
    int check;
    int rev_or_revrot;

	stack_b = NULL;
	len = node_count(stack_a);
    check = 0;
    while(len != 1)
    {
        if (!check)
        {
            rev_or_revrot = check_rot(stack_a, len, min) - check_revrot(stack_a, len, min);
            check = len;
        }
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
		if (rev_or_revrot < 0 && check)
		{
            str = ft_strjoin(str, "rra\n");
            do_rra_rrb(stack_a);
            check--;
		}
        if (rev_or_revrot >= 0 && check)
        {
			str = ft_strjoin(str, "ra\n");
            do_ra_rb(stack_a);
            check--;
        }
    }
	str = merge(stack_a, stack_b, str);
	return(str);
}

int check_rot(t_list *stack_a, int len, int min)
{
    int rot;
    int less;
    t_list *begin;
    t_list *center;

    rot = 0;
    center = stack_a;
    while(len)
    {
		begin = stack_a;
        less = 1;
        min = stack_a->node;
        while(stack_a && less <= len)
        {   
            if (min < stack_a->node)
            less++;
            stack_a = stack_a->next;
        }
        stack_a = center;
        stack_a = stack_a->next;
        center = center->next;
        begin = center;
		if ((less == len && len != 1) || (less == 2 && len == 1))
        rot++;
        len--;
    }
    return(rot);
}

int check_revrot(t_list *stack_a, int len, int min)
{
    int revrot;
    int less;
    int i;
    int tab[555];

    revrot = 0;
    i = 0;
    while (stack_a)
    {
        tab[i++] = stack_a->node;
        stack_a = stack_a->next;
    }
    while(len)
    {
        i = len - 1;
        less = 1;
        min = tab[i];
        while(i && less <= len)
        {
            if (min <= tab[i--])
            less++;
        }
		if ((less == len && len != 1) || (less == 2 && len == 1))
        revrot++;
        len--;
    }
    return(revrot);
}