/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youyoon <youyoon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 13:04:11 by youyoon           #+#    #+#             */
/*   Updated: 2023/07/05 19:31:05 by youyoon          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include "./libft/libft.h"

typedef struct s_node
{
	int				data;
	struct s_node	*prev;
	struct s_node	*next;
}	t_node;

typedef struct s_tack
{
	t_node	*top;
	t_node	*bottom;
	int		len;
}	t_stack;

typedef struct s_info
{
	t_stack	*a_stack;
	t_stack	*b_stack;
	int		*list;
	int		list_size;
	int		max_list_size;
	int		*pivot;
}	t_info;

/* push_swap.c */
void	print_error(void);

/* utils.c */
int		ps_atoi(const char *str);
int		check_valid_atoi(char *str);
void	check_sorted(t_info *stacks);
void	indexing(t_info *stacks);

/* utils2.c */
void	stacking(t_info *stacks);
void	divide_pivot(t_info *stacks);
int		get_stack_min(t_info *stacks);
int		get_stack_max(t_info *stacks);
int		check_bigger(int a_min, int b_min, int a_loc, int b_loc);

/* stack_push.c */
t_node	*make_new_node(int data);
void	init_stack(t_info *var);
void	push_top(t_stack *s, t_node *new_node);
void	push_bottom(t_stack *s, t_node *new_node);

/* stack_pop.c */
int		is_empty_stack(t_stack *s);
t_node	*pop_top(t_stack *s);
t_node	*pop_bottom(t_stack *s);

/* validate_arg.c */
void	validate_arg(int argc, char *argv[], t_info *stacks);

/* sort.c */
void	operating(t_info *stacks);
void	sort_three_args(t_info *stacks);
void	sort_args(t_info *stacks);
void	sort_big_last(t_info *stacks);

/* sort_rotate.c */
void	get_min_rotate(t_info *stacks, int *a_min, int *b_min);
void	rotate_same(t_info *stacks, int *a, int *b);
void	rotate_a(t_info *stacks, int a);
void	rotate_b(t_info *stacks, int b);

/* sort_find_location.c */
int		find_location_a(int num, t_info *stacks);
int		find_min_a(t_info *stacks);
int		find_max_a(t_info *stacks);
int		find_mid_a(int num, t_info *stacks);

/* operations_swap.c */
void	sa(t_info *stacks);
void	sb(t_info *stacks);
void	ss(t_info *stacks);

/* operations_push.c */
void	pa(t_info *stacks);
void	pb(t_info *stacks);

/* operations_rotate.c */
void	ra(t_info *stacks);
void	rb(t_info *stacks);
void	rr(t_info *stacks);

/*operations_rotate2.c */
void	rra(t_info *stacks);
void	rrb(t_info *stacks);
void	rrr(t_info *stacks);
#endif
