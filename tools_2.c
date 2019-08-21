/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sholiak <sholiak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/10 15:50:54 by sholiak           #+#    #+#             */
/*   Updated: 2019/08/21 16:33:23 by sholiak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int ft_strdigits(char *str)
{
    int i;

    i = 0;
    if (str[i] == '\0' || str[i] == '\n' || str[i] == ' ')
    error("Error : Please enter some digits");
    while(str[i] != '\0' && str[i] > 47 && str[i] < 58)
    i++;
    if (str[i] != '\0' && str[i] != '\n' && str[i] != ' ')
    error("Error : Please enter digits only");
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
    while(stack->next != NULL)
    {
        stack = stack->next;
        i++;
    }
        return(i);
}

int make_sorted(t_list *stack, t_table *tab, int len, int find)
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
    return(0);
}

int check_spot(t_table *tab, int find)
{
    int i;

    i = 0;
    while (i)
}