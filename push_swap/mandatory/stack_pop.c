/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_pop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youyoon <youyoon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 14:12:11 by youyoon           #+#    #+#             */
/*   Updated: 2023/07/06 15:26:39 by youyoon          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_empty_stack(t_stack *s)
{
	if (s->len == 0)
		return (1);
	return (0);
}

t_node	*pop_top(t_stack *s)
{
	t_node	*del;

	if (is_empty_stack(s))
		return (NULL);
	del = s->top->next;
	del->next->prev = s->top;
	s->top->next = del->next;
	del->prev = NULL;
	del->next = NULL;
	return (del);
}

t_node	*pop_bottom(t_stack *s)
{
	t_node	*del;

	if (is_empty_stack(s))
		return (NULL);
	del = s->bottom->prev;
	del->prev->next = s->bottom;
	s->bottom->prev = del->prev;
	del->prev = NULL;
	del->next = NULL;
	return (del);
}
