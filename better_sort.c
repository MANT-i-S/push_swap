/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   better_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sholiak <sholiak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/22 20:15:29 by sholiak           #+#    #+#             */
/*   Updated: 2019/08/28 15:23:19 by sholiak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char *better_sort(t_list *stack_a, char *str)
{
    t_list *stack_b;
    t_table *tab;
    
    tab = (t_table*)malloc(sizeof(t_table));
    stack_b = NULL;
    tab->len = node_count(stack_a);
    make_sorted(stack_a, tab, tab->len);
    if(tab->len <= 3)
    str = sort_1_3(stack_a, tab, str);
    if(tab->len > 3 && tab->len <= 5)
    str = sort_4_8(stack_a, stack_b, tab, str);
    if(tab->len > 5)
    str = smart_split(stack_a, stack_b, tab, str);
	return(str);
}

char *smart_split(t_list *stack_a, t_list *stack_b, t_table *tab, char *str)
{
    int spot;
    int rev_revrot;
    int min;
    int max;
    int check;

    min = 1;
    spot = 0;
    max = tab->len;
    while(stack_a && min != tab->len)
    {
        spot = check_spot(tab, stack_a->node);
        rev_revrot = better_rev(stack_a, tab, min) - better_revrot(stack_a, tab, min);
        if (spot == min)
        {
            str = ft_strjoin(str, "pb\n");
            stack_b = pre_pa_pb(stack_a, stack_b);
            stack_a = rm_first_node(stack_a);
            if(check)
            {
                str = ft_strjoin(str, "sb\n");
                do_sa_sb(stack_b);
                min++;
                check = 0;
            }
			min++;
        }
        else if (spot == min + 1 && !check)
        {
            str = ft_strjoin(str, "pb\n");
            stack_b = pre_pa_pb(stack_a, stack_b);
            stack_a = rm_first_node(stack_a);
            check = 1;
        }
        else if (spot == max)
        {
            str = ft_strjoin(str, "pb\n");
            stack_b = pre_pa_pb(stack_a, stack_b);
            stack_a = rm_first_node(stack_a);
            str = ft_strjoin(str, "rb\n");
            do_ra_rb(stack_b);
            max--;
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
    str = before_merging(stack_a, stack_b, tab, str);
    return(str);
}

int better_rev(t_list *stack_a, t_table *tab, int min)
{
    int rot;
    int spot;

    rot = 0;
    spot = 0;
    while(spot != min && stack_a)
    {
        spot = check_spot(tab, stack_a->node);
        stack_a = stack_a->next;
        rot++;
    }
    return(rot);
}

int better_revrot(t_list *stack_a, t_table *tab, int min)
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
    while(spot != min && j >= 0)
    {
        spot = check_spot(tab, array[j]);
        j--;
        revrot++;
    }
    return(revrot);
}

char *before_merging(t_list *stack_a, t_list *stack_b, t_table *tab, char *str)
{
    int spot;

    spot = 0;
    while (spot != tab->len)
    {
        spot = check_spot(tab, stack_b->node);
        if(spot == tab->len)
        {
        str = merge_stacks(stack_a, stack_b, str);
        return(str);
        }
        str = ft_strjoin(str, "ra\n");
        do_ra_rb(stack_b);
    }
    return(str);
}