/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sholiak <sholiak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 12:40:36 by sholiak           #+#    #+#             */
/*   Updated: 2019/08/13 17:07:43 by sholiak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
#include <unistd.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <stdio.h>

typedef struct		s_list
{
	int				node;
	struct s_list	*next;
}					t_list;

void print_list(t_list *list);
int ft_strdigits(char *str);
int	cmd_check(const char *s1, const char *s2);
int error(char *msg);
int node_count(t_list *stack);
int	repeat_check(t_list *stack_a, int num);
t_list	*add_link(t_list *list, int num);
t_list	*push_swap(t_list *stack_a);
int		correct_order(t_list *stack_a);
void	do_sa_sb(t_list *stack_a);
t_list	*pre_pa_pb(t_list *stack_a, t_list *stack_b);
t_list	*rm_first_node(t_list *stack);
void	do_ra_rb(t_list *stack);
void	do_rra_rrb(t_list *stack);
t_list	*dispatch_a(t_list *stack_a, t_list *stack_b, char **cmd);
t_list	*dispatch_b(t_list *stack_a, t_list *stack_b, char **cmd);
t_list	*read_digits(t_list *stack_a);
char	**read_commands(char **cmd);
int	find_mid(t_list *stack_a);
char *analyse(t_list *stack_a);
char *divide(t_list *stack_a, t_list *stack_b, char *str, int mid);
char *bubble_a(t_list *stack_a, char *str);
char *bubble_b(t_list *stack_b, char *str);
char *merge(t_list *stack_a, t_list *stack_b, char *str);
char *double_bubble(t_list *stack_a, t_list *stack_b, char *str, int mid);

#endif
