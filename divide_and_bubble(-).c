/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   divide_and_bubble(-).c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mantis <mantis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/11 18:03:10 by sholiak           #+#    #+#             */
/*   Updated: 2019/08/15 18:32:12 by mantis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char *analyse(t_list *stack_a)
{
    t_list *stack_b;
    char *str;
    int mid;

    stack_b = NULL;
    str = ft_strnew(0);
    mid = find_median(stack_a);
    str = divide(stack_a, stack_b, str, mid);
    return(str);
}

char *divide(t_list *stack_a, t_list *stack_b, char *str, int mid)
{
    int check;

    check = 2;
    while (check)
    {
        if (stack_a->node < mid)
        {
            str = ft_strjoin(str, "pb\n");
            pre_pa_pb(stack_a, stack_b);
            stack_a = rm_first_node(stack_a);
        }
        else if (stack_a->node > mid)
        {
            str = ft_strjoin(str, "ra\n");
            do_ra_rb(stack_a);
        }
        else if (stack_a->node == mid)
        {
            str = ft_strjoin(str, "ra\n");
            do_ra_rb(stack_a);
            check--;
        }
    }
    str = ft_strjoin(str, bubble_a(stack_a, str));
    str = ft_strjoin(str, bubble_b(stack_b, str));
    str = merge(stack_a, stack_b, str);
    return(str);
}

char *bubble_a(t_list *stack_a, char *str)
{
    while (!correct_order(stack_a))
    {
		if (stack_a->node < stack_a->next->node)
		{
			str = ft_strjoin(str, "ra\n");
            do_ra_rb(stack_a);
		}
        else if (stack_a->node > stack_a->next->node)
        {
            str = ft_strjoin(str, "sa\n");
            do_sa_sb(stack_a);
        }
    }
    return(str);
}

// char *bubble_a(t_list *stack_a, char *str)
// {
//     int len;
//     int check;

//     len = node_count(stack_a);
//     check = len;
//     while (check)
//     {
//         if (stack_a->node < stack_a->next->node)
//         {
//             str = ft_strjoin(str, "sa\n");
//             do_sa_sb(stack_a);
//             check--;
//         }
//         else if (stack_a->node > stack_a->next->node)
//         {
//             str = ft_strjoin(str, "ra\n");
//             do_ra_rb(stack_a);
//             check = len;
//         }
//     }
//     return(str);
// }

char *bubble_b(t_list *stack_b, char *str)
{
    int len;
    int check;

    len = node_count(stack_b);
    check = len;
    while (check)
    {
        if (stack_b->node > stack_b->next->node)
        {
            str = ft_strjoin(str, "sa\n");
            do_sa_sb(stack_b);
            check--;
        }
        else if (stack_b->node > stack_b->next->node)
        {
            str = ft_strjoin(str, "ra\n");
            do_ra_rb(stack_b);
            check = len;
        }
    }
    return(str);
}

// char *merge(t_list *stack_a, t_list *stack_b, char *str)
// {
//     int len;

//     len = node_count(stack_b);
//     while(len)
//     {
//         str = ft_strjoin(str, "pb\n");
//         pre_pa_pb(stack_b, stack_a);
//         stack_b = rm_first_node(stack_b);
//         len--;
//     }
//     return(str);
// }