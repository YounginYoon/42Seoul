/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_push.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youyoon <youyoon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 15:21:29 by youyoon           #+#    #+#             */
/*   Updated: 2023/07/05 18:59:49 by youyoon          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_info *stacks)
{
	if (stacks->b_stack->top->next->data != 0)
	{
		push_top(stacks->a_stack, pop_top(stacks->b_stack));
		stacks->a_stack->len++;
		stacks->b_stack->len--;
		write(1, "pa\n", 3);
	}
}

void	pb(t_info *stacks)
{
	if (stacks->a_stack->top->next->data != 0)
	{
		push_top(stacks->b_stack, pop_top(stacks->a_stack));
		stacks->b_stack->len++;
		stacks->a_stack->len--;
		write(1, "pb\n", 3);
	}
}
