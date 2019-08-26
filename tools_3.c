/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sholiak <sholiak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/26 15:13:01 by sholiak           #+#    #+#             */
/*   Updated: 2019/08/26 15:14:40 by sholiak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    make_sorted(t_list *stack, t_table *tab, int len)
{
    int i;
    int j;
    int temp;
    int check;

    i = 0;
    j = 1;
    len--;
    while (stack)
    {
        tab->sorted[i++] = stack->node;
        stack = stack->next;
    }
    i = 0;
    check = 1;
    while(check > 0)
    {
        check = 1;
        while (j <= len)
        {
            if(tab->sorted[i] > tab->sorted[j])
            {
                temp = tab->sorted[i];
                tab->sorted[i] = tab->sorted[j];
                tab->sorted[j] = temp;
                check = 2;
            }
            i++;
            j++;
        }
        i = 0;
        j = 1;
        if (check == 1)
        check = 0;
    }
}

void    make_minisorted(t_list *stack, t_table *tab, int len)
{
    int i;
    int j;
    int temp;
    int check;

    i = 0;
    j = 1;
    len--;
    while (stack)
    {
        tab->minisorted[i++] = stack->node;
        stack = stack->next;
    }
    i = 0;
    check = 1;
    while(check > 0)
    {
        check = 1;
        while (j <= len)
        {
            if(tab->minisorted[i] > tab->minisorted[j])
            {
                temp = tab->minisorted[i];
                tab->minisorted[i] = tab->minisorted[j];
                tab->minisorted[j] = temp;
                check = 2;
            }
            i++;
            j++;
        }
        i = 0;
        j = 1;
        if (check == 1)
        check = 0;
    }
}