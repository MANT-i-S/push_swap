/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sholiak <sholiak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/08 21:11:23 by sholiak           #+#    #+#             */
/*   Updated: 2019/09/06 17:00:34 by sholiak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_list(t_list *stack_a, t_list *stack_b)
{
	printf("|:::::::::|::|:::::::::|\n");
	while (stack_a != NULL && stack_b != NULL)
	{
		printf("|%-9d|  |%9d|\n", stack_a->node, stack_b->node);
		stack_a = stack_a->next;
		stack_b = stack_b->next;
	}
	while (stack_a != NULL)
	{
		printf("|%-9d|  |         |\n", stack_a->node);
		stack_a = stack_a->next;
	}
	while (stack_b != NULL)
	{
		printf("|         |  |%9d|\n", stack_b->node);
		stack_b = stack_b->next;
	}
	printf("|:::::::::|::|:::::::::|\n");
}

void	error(char *msg)
{
	ft_putendl(msg);
	exit(1);
}

t_list	*add_link(t_list *list, int num)
{
	t_list *tmp;

	tmp = malloc(sizeof(t_list));
	if (tmp)
	{
		tmp->node = num;
		tmp->next = list;
	}
	return (tmp);
}

int		repeat_check(t_list *stack_a, int num)
{
	while (stack_a->next != NULL)
	{
		stack_a = stack_a->next;
		if (stack_a->node == num)
			return (1);
	}
	return (0);
}

int		correct_order(t_list *stack_a)
{
	int tmp;

	while (stack_a->next != NULL)
	{
		tmp = stack_a->node;
		stack_a = stack_a->next;
		if (stack_a->node < tmp)
			return (0);
	}
	return (1);
}
