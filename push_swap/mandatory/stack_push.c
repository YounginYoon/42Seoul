/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_push.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youyoon <youyoon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 13:34:39 by youyoon           #+#    #+#             */
/*   Updated: 2023/07/03 15:59:31 by youyoon          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*make_new_node(int data)
{
	t_node	*ret;

	ret = (t_node *) malloc(sizeof(t_node));
	if (!ret)
		return (0);
	ret->data = data;
	ret->next = NULL;
	ret->prev = NULL;
	return (ret);
}

void	init_stack(t_info *var)
{
	var->a_stack = (t_stack *) malloc(sizeof(t_stack));
	var->b_stack = (t_stack *) malloc(sizeof(t_stack));
	if (!(var->a_stack) || !(var->b_stack))
		return ;
	var->a_stack->top = make_new_node(0);
	var->a_stack->bottom = make_new_node(0);
	var->a_stack->top->next = var->a_stack->bottom;
	var->a_stack->bottom->prev = var->a_stack->top;
	var->a_stack->len = 0;
	var->b_stack->top = make_new_node(0);
	var->b_stack->bottom = make_new_node(0);
	var->b_stack->top->next = var->b_stack->bottom;
	var->b_stack->bottom->prev = var->b_stack->top;
	var->b_stack->len = 0;
	var->list = (int *) malloc(sizeof(int));
	var->list_size = 0;
}

void	push_top(t_stack *s, t_node *new_node)
{
	new_node->prev = s->top;
	new_node->next = s->top->next;
	s->top->next->prev = new_node;
	s->top->next = new_node;
}

void	push_bottom(t_stack *s, t_node *new_node)
{
	new_node->next = s->bottom;
	new_node->prev = s->bottom->prev;
	s->bottom->prev->next = new_node;
	s->bottom->prev = new_node;
}
