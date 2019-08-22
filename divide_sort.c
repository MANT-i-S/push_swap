/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   divide_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sholiak <sholiak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/20 16:41:05 by sholiak           #+#    #+#             */
/*   Updated: 2019/08/21 20:50:32 by sholiak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char *divide_sort(t_list *stack_a, char *str)
{
    t_list *stack_b;
    t_table *tab;
    int count;
    int spot;

    tab = (t_table*)malloc(sizeof(t_table));
    stack_b = NULL;
    tab->len = node_count(stack_a);
    count = tab->len / 2;
    make_sorted(stack_a, tab, tab->len);
    while(count)
    {
        spot = check_spot(tab, stack_a->node);
        if(spot % 2 && spot <= tab->len)
        {
            if (spot == tab->len)
            {
                str = ft_strjoin(str, "ra\n");
                do_ra_rb(stack_a);
            }
            str = ft_strjoin(str, "pb\n");
            stack_b = pre_pa_pb(stack_a, stack_b);
            stack_a = rm_first_node(stack_a);
            count--;
        }
        else 
        {
            str = ft_strjoin(str, "ra\n");
            do_ra_rb(stack_a);
        }
    }
    str = process(stack_a, stack_b, tab, str);
    return(str);
}

char *process(t_list *stack_a, t_list *stack_b, t_table *tab, char *str)
{
    int spot_a;
    int spot_b;
    int rev_revrot;

    while(stack_b)
    {
        spot_a = check_spot(tab, stack_a->node);
        spot_b = check_spot(tab, stack_b->node);
        rev_revrot = spot_rot(stack_b, tab, spot_a) - spot_revrot(stack_b, tab, spot_a);
        if (spot_b - 1 == spot_a)
        {
            str = ft_strjoin(str, "pb\n");
            stack_a = pre_pa_pb(stack_b, stack_a);
            stack_b = rm_first_node(stack_b);
        }
        else if (rev_revrot < 0)
		{
            str = ft_strjoin(str, "rrb\n");
            stack_b = do_rra_rrb(stack_b);
		}
        else if (rev_revrot >= 0) 
        {
			str = ft_strjoin(str, "rb\n");
            do_ra_rb(stack_b);
        }
        else 
        {
          	str = ft_strjoin(str, "ra\n");
            do_ra_rb(stack_a);
        }
    }
    return(str);
}

int spot_rot(t_list *stack_b, t_table *tab, int spot)
{
    int find;
    int rot;

    rot = 0;
    find = 555;
    while(stack_b && find != spot - 1)
    {
        find = check_spot(tab, stack_b->node);
        stack_b = stack_b->next;
        rot++;
    }
    return(rot);
}

int spot_revrot(t_list *stack_b, t_table *tab, int spot)
{
    int find;
    int revrot;
    int i;
    int array[555];
    t_list *begin;

    begin = stack_b;
    revrot = 0;
    i = 0;
    find = 555;
    while (stack_b)
    {
        array[i++] = stack_b->node;
        stack_b = stack_b->next;
    }
    stack_b = begin;
    i--;
    while(i >= 0 && spot != find -1)
    {
        find = check_spot(tab, stack_b->node);
        i--;
        revrot++;
    }
    return(revrot);
}