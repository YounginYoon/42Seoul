/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_pop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youyoon <youyoon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 14:12:11 by youyoon           #+#    #+#             */
/*   Updated: 2023/07/03 16:02:35 by youyoon          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*pop_top(t_stack *s)
{
	t_node	*ret;

	if (is_empty_stack(s))
		return (NULL);
	ret = s->top;
	s->top = s->top->next;
	s->top->prev = NULL;
	ret->next = NULL;
	s->len--;
	return (ret);
}

t_node	*pop_bottom(t_stack *s)
{
	t_node	*ret;

	if (is_empty_stack(s))
		return (NULL);
	ret = s->bottom;
	s->bottom = s->bottom->prev;
	s->bottom->next = NULL;
	ret->prev = NULL;
	s->len--;
	return (ret);
}
