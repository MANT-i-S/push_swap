/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sholiak <sholiak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 12:40:36 by sholiak           #+#    #+#             */
/*   Updated: 2019/09/06 19:03:29 by sholiak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <unistd.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdio.h>

typedef struct		s_list
{
	int				node;
	struct s_list	*next;
}					t_list;

typedef struct		s_table
{
	int				notfree;
	int				j;
	int				debug;
	int				flag;
	int				min;
	int				max;
	int				check;
	int				r_r;
	int				spot;
	int				len;
	int				minisorted[11];
	int				sorted[555];
}					t_table;

int					ft_strdigits(char *str);
int					cmd_c(const char *s1, const char *s2);
void				ft_list_free(t_list *stack);
void				ft_use(void);
void				error(char *msg);
void				errorko(void);
void				errorok(void);
int					node_count(t_list *stack);
void				print_list(t_list *stack_a, t_list *stack_b);
void				checker(t_list *stack_a, t_table *tab, char **digits);
void				push_swap(t_list *stack_a, char **digits);
int					repeat_check(t_list *stack_a, int num);
t_list				*add_link(t_list *list, int num);
int					correct_order(t_list *stack_a);
void				do_sa_sb(t_list *stack_a);
t_list				*pre_pa_pb(t_list *stack_a, t_list *stack_b);
t_list				*rm_first_node(t_list *stack);
void				do_ra_rb(t_list *stack);
t_list				*do_rra_rrb(t_list *stack);
t_list				*read_digits(t_list *stack_a);
void				read_commands(t_list *stack_a, t_table *tab);
void				sort_4_8(t_list *stack_a, t_list *stack_b, t_table *tab);
void				make_sorted(t_list *stack, t_table *tab, int len);
int					check_spot(t_table *tab, int find);
void				better_sort(t_list *stack_a);
int					smart_split(t_list *stack_a, t_list *stack_b, t_table *tab);
int					midsplit(t_list *stack_a, t_list *stack_b, t_table *tab);
int					rev(t_list *stack_a, t_table *tab, int i);
int					revrot(t_list *stack_a, t_table *tab, int i);
int					pre_merg(t_list *stack_a, t_list *stack_b, t_table *tab);
void				sort_1_3(t_list *stack_a, t_table *tab);
void				make_minisorted(t_list *stack, t_table *tab, int len);
int					minispot(t_table *tab, int node);
void				pre(t_list *stack_a, t_list *s_b, t_table *tab, char **cmd);
void				dis(t_list *stack_a, t_list *s_b, t_table *tab, char **cmd);
void				las(t_list *stack_a, t_list *s_b, t_table *tab, char **cmd);
void				merge_stacks(t_list *stack_a, t_list *stack_b);
void				ft_help(void);
void				ft_sorting(t_table *tab, int len, int temp, int check);
void				ft_minisorting(t_table *tab, int len, int temp, int check);
void				write_ra(t_list *stack);

#endif
