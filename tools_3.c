/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sholiak <sholiak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/26 15:13:01 by sholiak           #+#    #+#             */
/*   Updated: 2019/09/04 16:10:33 by sholiak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	make_sorted(t_list *stack, t_table *tab, int len)
{
	int i;
	int j;
	int temp;
	int check;

	i = 0;
	j = 1;
	temp = 0;
	check = 1;
	len--;
	while (stack)
	{
		tab->sorted[i++] = stack->node;
		stack = stack->next;
	}
	i = 0;
	ft_sorting(tab, len, temp, check);
}

void	make_minisorted(t_list *stack, t_table *tab, int len)
{
	int i;
	int j;
	int temp;
	int check;

	i = 0;
	j = 1;
	temp = 0;
	check = 1;
	len--;
	while (stack)
	{
		tab->minisorted[i++] = stack->node;
		stack = stack->next;
	}
	i = 0;
	ft_minisorting(tab, len, temp, check);
}

void	ft_sorting(t_table *tab, int len, int temp, int check)
{
	int i;
	int j;

	i = 0;
	j = 1;
	while (check > 0)
	{
		check = 1;
		while (j <= len)
		{
			if (tab->sorted[i] > tab->sorted[j])
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

void	ft_minisorting(t_table *tab, int len, int temp, int check)
{
	int i;
	int j;

	i = 0;
	j = 1;
	while (check > 0)
	{
		check = 1;
		while (j <= len)
		{
			if (tab->minisorted[i] > tab->minisorted[j])
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

void	ft_help(void)
{
	ft_putstr("Commands list:\n|sa| swap a - swap the first 2 of stack a\n");
	ft_putstr("|sb| swap b - swap the first 2 of stack b\n");
	ft_putstr("|ss| running |sa| + |sb|\n");
	ft_putstr("|pa| push a - take the first of b and put it at the top of a\n");
	ft_putstr("|pb| push b - take the first of a and put it at the top of b\n");
	ft_putstr("|ra| rotate a - shift up all elements of stack a by 1\n");
	ft_putstr("|rb| rotate b - shift up all elements of stack b by 1\n");
	ft_putstr("|rr| running |ra| + |rb|\n");
	ft_putstr("|rra| rev rotate a - shift down all elements of stack a by 1\n");
	ft_putstr("|rrb| rev rotate b - shift down all elements of stack b by 1\n");
	ft_putstr("|rrr| running |rra| + |rrb|\n");
	ft_putstr("Also try |./checker -use| for usage examples\n");
	error("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^");
}
