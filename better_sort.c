/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   better_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sholiak <sholiak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/22 20:15:29 by sholiak           #+#    #+#             */
/*   Updated: 2019/08/22 21:05:09 by sholiak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char *better_sort(t_list *stack_a, char *str)
{
    t_list *stack_b;
    t_table *tab;
    int spot;
    int rev_revrot;
    int i;

    i = 1;
    tab = (t_table*)malloc(sizeof(t_table));
    stack_b = NULL;
    tab->len = node_count(stack_a);
    make_sorted(stack_a, tab, tab->len);
    spot = 0;
    while(i != tab->len)
    {
        spot = check_spot(tab, stack_a->node);
        rev_revrot = better_rev(stack_a, tab, i) - better_revrot(stack_a, tab, i);
        if (spot == i)
        {
            str = ft_strjoin(str, "pb\n");
            stack_b = pre_pa_pb(stack_a, stack_b);
            stack_a = rm_first_node(stack_a);
			i++;
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
    str = merge(stack_a, stack_b, str);
    printf("%s", str); //remove;
    if(!correct_order(stack_a))//remove;
	error("KO");//remove;
	error("OK");//remove;
	return(str);
}

int better_rev(t_list *stack_a, t_table *tab, int i)
{
    int rot;
    int spot;

    rot = 0;
    spot = 0;
    while(spot != i && stack_a)
    {
        spot = check_spot(tab, stack_a->node);
        stack_a = stack_a->next;
        rot++;
    }
    return(rot);
}

int better_revrot(t_list *stack_a, t_table *tab, int i)
{
    int revrot;
    int spot;
    int j;
    int array[555];

    revrot = 0;
    spot = 0;
    j = 0;
    while (stack_a)
    {
        array[j++] = stack_a->node;
        stack_a = stack_a->next;
    }
    j--;
    while(spot != i && j >= 0)
    {
        spot = check_spot(tab, array[j]);
        j--;
        revrot++;
    }
    return(revrot);
}
