/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sholiak <sholiak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 12:40:36 by sholiak           #+#    #+#             */
/*   Updated: 2019/08/28 17:52:11 by sholiak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include "get_next_line.h"
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

typedef struct	s_table
{
int			debug;
int			len;
int			minisorted[11];
int 		sorted[555];
}				t_table;

void print_list(t_list *list);
int ft_strdigits(char *str);
int	cmd_check(const char *s1, const char *s2);
int error(char *msg);
int node_count(t_list *stack);
int	repeat_check(t_list *stack_a, int num);
t_list	*add_link(t_list *list, int num);
int		correct_order(t_list *stack_a);
void	do_sa_sb(t_list *stack_a);
t_list	*pre_pa_pb(t_list *stack_a, t_list *stack_b);
t_list	*rm_first_node(t_list *stack);
void	do_ra_rb(t_list *stack);
t_list	*do_rra_rrb(t_list *stack);
t_list	*read_digits(t_list *stack_a);
void read_commands(t_list *stack_a, char **cmd, int debug);
int	find_median(t_list *stack);
int for_even(t_list *stack, int mid, int half);
int for_odd(t_list *stack, int mid, int half);
char *sort_4_8(t_list *stack_a, t_list *stack_b, t_table *tab, char *str);
char *sort_with_check(t_list *stack_a, char *str);
char *sort_with_better_check(t_list *stack_a, char *str);
char *divide_sort(t_list *stack_a, char *str);
char *process(t_list *stack_a, t_list *stack_b, t_table *table, char *str);
void make_sorted(t_list *stack, t_table *tab, int len);
int spot_rot(t_list *stack_b, t_table *tab, int spot);
int spot_revrot(t_list *stack_b, t_table *tab, int spot);
int check_spot(t_table *tab, int find);
//int sort_array(t_list *stack);
int check_rot(t_list *stack_a, int len, int min);
int check_revrot(t_list *stack_a, int len, int min);
int closest_rot(t_list *stack_a, int len, int min);
int closest_revrot(t_list *stack_a, int len, int min);
char *better_sort(t_list *stack_a, char *str);
char *smart_split(t_list *stack_a, t_list *stack_b, t_table *tab, char *str);
int better_rev(t_list *stack_a, t_table *tab, int i);
int better_revrot(t_list *stack_a, t_table *tab, int i);
char *before_merging(t_list *stack_a, t_list *stack_b, t_table *tab, char *str);
char *sort_1_3(t_list *stack_a, t_table *tab, char *str);
void make_minisorted(t_list *stack, t_table *tab, int len);
int check_minispot(t_table *tab, int node);
void pre_dispatch(t_list *stack_a, char **cmd, int debug);
t_list	*dispatch_a(t_list *stack_a, t_list *stack_b, char **cmd, int j);
t_list	*dispatch_b(t_list *stack_a, t_list *stack_b, char **cmd, int j);
char *merge_stacks(t_list *stack_a, t_list *stack_b, char *str);
void ft_help();

#endif
