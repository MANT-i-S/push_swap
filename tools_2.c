/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sholiak <sholiak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/10 15:50:54 by sholiak           #+#    #+#             */
/*   Updated: 2019/09/03 16:34:09 by sholiak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strdigits(char *str)
{
	int i;

	i = 0;
	if (str[i] == '\0' || str[i] == '\n' || str[i] == ' ')
		error("Error : Please enter some digits");
	if (str[i] == '-')
		i++;
	while (str[i] != '\0' && str[i] > 47 && str[i] < 58)
		i++;
	if (str[i] != '\0' && str[i] != '\n' && str[i] != ' ')
		error("Error : Please enter digits only");
	return (0);
}

int	cmd_c(const char *s1, const char *s2)
{
	while (*s1 == *s2 && *s1 != '\0' && *s2 != '\0')
	{
		s1++;
		s2++;
	}
	if (*s1 != *s2 && *s1 != '\n')
		return (1);
	return (0);
}

int	node_count(t_list *stack)
{
	int i;

	i = 1;
	while (stack->next != NULL)
	{
		stack = stack->next;
		i++;
	}
	return (i);
}

int	check_spot(t_table *tab, int node)
{
	int i;

	i = 0;
	while (tab->sorted[i] != node)
		i++;
	i++;
	return (i);
}

int	check_minispot(t_table *tab, int node)
{
	int i;

	i = 0;
	while (tab->minisorted[i] != node)
		i++;
	i++;
	return (i);
}
