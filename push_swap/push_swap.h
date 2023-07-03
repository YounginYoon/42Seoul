/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youyoon <youyoon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 13:04:11 by youyoon           #+#    #+#             */
/*   Updated: 2023/07/03 14:14:40 by youyoon          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>

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
}	t_info;

/* utils.c */
t_node	*make_new_node(int data);

/* stack_init_push.c */
void	init_stack(t_info *var);
int		is_empty_stack(t_stack *s);
void	push_top(t_stack *s, t_node *new_node);
void	push_bottom(t_stack *s, t_node *new_node);
t_node	*pop_top(t_stack *s);
t_node	*pop_bottom(t_stack *s);
#endif
