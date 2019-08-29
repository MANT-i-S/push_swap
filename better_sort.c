/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   better_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sholiak <sholiak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/22 20:15:29 by sholiak           #+#    #+#             */
/*   Updated: 2019/08/29 16:43:55 by sholiak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*better_sort(t_list *stack_a, char *str)
{
	t_list	*stack_b;
	t_table	*tab;

	tab = (t_table *)malloc(sizeof(t_table));
	stack_b = NULL;
	tab->len = node_count(stack_a);
	make_sorted(stack_a, tab, tab->len);
	if (tab->len <= 3)
		str = sort_1_3(stack_a, tab, str);
	if (tab->len > 3 && tab->len <= 5)
		str = sort_4_8(stack_a, stack_b, tab, str);
	if (tab->len > 5)
	{
		tab->min = 1;
		tab->check = 0;
		tab->spot = 0;
		tab->max = tab->len;
		str = smart_split(stack_a, stack_b, tab, str);
	}
	return (str);
}

char	*smart_split(t_list *stack_a, t_list *stack_b, t_table *tab, char *str)
{
	while (stack_a && (tab->min != tab->len || tab->max == tab->min))
	{
		tab->spot = check_spot(tab, stack_a->node);
		tab->rev_revrot = rev(stack_a, tab, tab->min) -
		revrot(stack_a, tab, tab->min);
		if (tab->spot == tab->min && tab->min != tab->max)
		{
			str = ft_strjoin(str, "pb\n");
			stack_b = pre_pa_pb(stack_a, stack_b);
			stack_a = rm_first_node(stack_a);
			if (tab->check)
			{
				str = ft_strjoin(str, "sb\n");
				do_sa_sb(stack_b);
				tab->min++;
				tab->check = 0;
			}
			tab->min++;
		}
		else
			midsplit(stack_a, stack_b, tab, str);
	}
	str = pre_merg(stack_a, stack_b, tab, str);
	return (str);
}

void	midsplit(t_list *stack_a, t_list *stack_b, t_table *tab, char *str)
{
	if (tab->spot == tab->min + 1 && !tab->check)
	{
		str = ft_strjoin(str, "pb\n");
		stack_b = pre_pa_pb(stack_a, stack_b);
		stack_a = rm_first_node(stack_a);
		tab->check = 1;
	}
	else if (tab->spot == tab->max)
	{
		str = ft_strjoin(str, "pb\n");
		stack_b = pre_pa_pb(stack_a, stack_b);
		stack_a = rm_first_node(stack_a);
		str = ft_strjoin(str, "rb\n");
		do_ra_rb(stack_b);
		tab->max--;
	}
	else if (tab->rev_revrot > 0)
	{
		str = ft_strjoin(str, "rra\n");
		stack_a = do_rra_rrb(stack_a);
	}
	else if (tab->rev_revrot <= 0)
		str = write_ra(stack_a, str);
	smart_split(stack_a, stack_b, tab, str);
}

int		rev(t_list *stack_a, t_table *tab, int min)
{
	int rot;
	int spot;

	rot = 0;
	spot = 0;
	while (spot != min && stack_a)
	{
		spot = check_spot(tab, stack_a->node);
		stack_a = stack_a->next;
		rot++;
	}
	return (rot);
}

int		revrot(t_list *stack_a, t_table *tab, int min)
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
	while (spot != min && j >= 0)
	{
		spot = check_spot(tab, array[j]);
		j--;
		revrot++;
	}
	return (revrot);
}
