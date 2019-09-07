/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   better_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sholiak <sholiak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/22 20:15:29 by sholiak           #+#    #+#             */
/*   Updated: 2019/09/06 18:55:11 by sholiak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	better_sort(t_list *stack_a)
{
	t_list	*stack_b;
	t_table	*tab;

	tab = (t_table *)malloc(sizeof(t_table));
	stack_b = NULL;
	tab->len = node_count(stack_a);
	make_sorted(stack_a, tab, tab->len);
	if (tab->len <= 3)
		sort_1_3(stack_a, tab);
	if (tab->len > 3 && tab->len <= 5)
	{
		sort_4_8(stack_a, stack_b, tab);
		tab->notfree = 1;
	}
	if (tab->len > 5)
	{
		tab->min = 1;
		tab->check = 0;
		tab->spot = 0;
		tab->max = tab->len;
		smart_split(stack_a, stack_b, tab);
	}
	free(tab);
}

int		smart_split(t_list *stack_a, t_list *stack_b, t_table *tab)
{
	while (stack_a && (tab->min != tab->len || tab->max == tab->min))
	{
		tab->spot = check_spot(tab, stack_a->node);
		tab->r_r = rev(stack_a, tab, tab->min) - revrot(stack_a, tab, tab->min);
		if (tab->spot == tab->min && tab->min != tab->max)
		{
			ft_putstr("pb\n");
			stack_b = pre_pa_pb(stack_a, stack_b);
			stack_a = rm_first_node(stack_a);
			if (tab->check)
			{
				ft_putstr("sb\n");
				do_sa_sb(stack_b);
				tab->min++;
				tab->check = 0;
			}
			tab->min++;
		}
		else
			midsplit(stack_a, stack_b, tab);
		if (tab->flag)
			return (0);
	}
	tab->flag = pre_merg(stack_a, stack_b, tab);
	return (0);
}

int		midsplit(t_list *stack_a, t_list *stack_b, t_table *tab)
{
	if (tab->spot == tab->min + 1 && !tab->check && stack_a)
	{
		ft_putstr("pb\n");
		stack_b = pre_pa_pb(stack_a, stack_b);
		stack_a = rm_first_node(stack_a);
		tab->check = 1;
	}
	else if (tab->spot == tab->max && stack_a)
	{
		ft_putstr("pb\n");
		stack_b = pre_pa_pb(stack_a, stack_b);
		stack_a = rm_first_node(stack_a);
		ft_putstr("rb\n");
		do_ra_rb(stack_b);
		tab->max--;
	}
	else if (tab->r_r > 0 && stack_a)
	{
		ft_putstr("rra\n");
		stack_a = do_rra_rrb(stack_a);
	}
	else if (tab->r_r <= 0 && stack_a)
		write_ra(stack_a);
	smart_split(stack_a, stack_b, tab);
	return (0);
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
