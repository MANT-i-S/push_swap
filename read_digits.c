/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_digits.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sholiak <sholiak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/09 15:27:52 by sholiak           #+#    #+#             */
/*   Updated: 2019/08/17 11:52:04 by sholiak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list *read_digits(t_list *stack_a)
{
    int num;
    int j;
    char buff[22];
    char **digits;

    
    j = 0;
    while(read(0, buff, 22))
        digits = ft_strsplit(buff, ' ');
    while(digits[j] != NULL)
    j++;
    j--;
    while(j >= 0)
    {
        ft_strdigits(digits[j]);
        num = ft_atoi(digits[j]);
        stack_a = add_link(stack_a, num);
        if (repeat_check(stack_a, num))
	    error("Error : Please don't use same digits");
        j--;
    }
    ft_strdel(digits);
    return(stack_a);
}