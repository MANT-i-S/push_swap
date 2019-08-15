/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_median.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mantis <mantis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/14 18:56:54 by mantis            #+#    #+#             */
/*   Updated: 2019/08/14 19:37:09 by mantis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_median(t_list *stack)
{
    int mid;
    int len;
	
	mid = 0;
    len = node_count(stack);
	if(len % 2)
	{
		len = len / 2;
		mid = for_even(stack, mid, len);
	}
	else 
	{
		len = len / 2;
		mid = for_odd(stack, mid, len);
	}
	return(mid);
}

int for_even(t_list *stack, int mid, int half)
{
    int more = 0;
    int less = 0;
	t_list *center;
    t_list *begin;
	
    begin = stack;
	center = stack;
    while(more != half || less != half)
    {
        more = 0;
        less = 0;
        mid = stack->node;
		stack = begin;
        while(stack && less <= half && more <= half)
        {
            if (mid > stack->node)
            less++;
            if (mid < stack->node)
            more++;
			stack = stack->next;
        }
        stack = center;
        stack = stack->next;
        center = center->next;
    }
	return(mid);
}

int for_odd(t_list *stack, int mid, int half)
{
    int more = 0;
    int less = 0;
	t_list *center;
    t_list *begin;
	
    begin = stack;
	center = stack;
    while(more != half - 1 || less != half)
    {
        more = 0;
        less = 0;
        mid = stack->node;
		stack = begin;
        while(stack && less <= half && more <= half - 1)
        {
            if (mid > stack->node)
            less++;
            if (mid < stack->node)
            more++;
			stack = stack->next;
        }
        stack = center;
        stack = stack->next;
        center = center->next;
    }
	return(mid);
}
