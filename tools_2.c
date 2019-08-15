/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mantis <mantis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/10 15:50:54 by sholiak           #+#    #+#             */
/*   Updated: 2019/08/14 19:09:25 by mantis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int ft_strdigits(char *str)
{
    int i;

    i = 0;
    if (str[i] == '\0' || str[i] == '\n' || str[i] == ' ')
    error("Please enter some digits");
    while(str[i] != '\0' && str[i] > 47 && str[i] < 58)
    i++;
    if (str[i] != '\0' && str[i] != '\n' && str[i] != ' ')
    error("Please enter digits only");
    return(0);
}

int	cmd_check(const char *s1, const char *s2)
{
	while (*s1 == *s2 && *s1 != '\0' && *s2 != '\0')
	{
		s1++;
		s2++;
	}
	if (*s1 != *s2 && *s1 != '\n' && *s1 != ' ')
		return (1);
	return (0);
}

int node_count(t_list *stack)
{
    int i;

    i = 1;
    while(stack->next != NULL) //count, if sorter can do whole row without switching mean its sorted.
    {
        stack = stack->next;
        i++;
    }
        return(i);
}