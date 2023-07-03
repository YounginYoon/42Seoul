/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init_push.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youyoon <youyoon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 13:34:39 by youyoon           #+#    #+#             */
/*   Updated: 2023/07/03 15:59:31 by youyoon          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_stack(t_info *var)
{
	var->a_stack = (t_stack *) malloc(sizeof(t_stack));
	var->b_stack = (t_stack *) malloc(sizeof(t_stack));
	if (!(var->a_stack) || !(var->b_stack))
		return ;
	var->a_stack->top = NULL;
	var->a_stack->bottom = NULL;
	var->a_stack->len = 0;
	var->b_stack->top = NULL;
	var->b_stack->bottom = NULL;
	var->b_stack->len = 0;
}

int	is_empty_stack(t_stack *s)
{
	if (s->len == 0)
		return (1);
	return (0);
}

void	push_top(t_stack *s, t_node *new_node)
{
	if (is_empty_stack(s))
	{
		s->top = new_node;
		s->bottom = new_node;
		new_node->next = s->bottom;
		new_node->prev = s->top;
	}
	else
	{
		new_node->next = s->top;
		s->top->prev = new_node;
		s->top = new_node;
	}
	s->len++;
}

void	push_bottom(t_stack *s, t_node *new_node)
{
	if (is_empty_stack(s))
	{
		s->top = new_node;
		s->bottom = new_node;
		new_node->next = s->bottom;
		new_node->prev = s->top;
	}
	else
	{
		new_node->prev = s->bottom;
		s->bottom->next = new_node;
		s->bottom = new_node;
	}
	s->len++;
}
