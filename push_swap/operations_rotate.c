/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youyoon <youyoon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 15:27:45 by youyoon           #+#    #+#             */
/*   Updated: 2023/07/05 15:39:02 by youyoon          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ps_rotate(t_stack *stack)
{
	t_node	*tmp;

	tmp = pop_top(stack);
	push_bottom(stack, tmp);
}

void	ra(t_info *stacks)
{
	ps_rotate(stacks->a_stack);
	write(1, "ra\n", 3);
}

void	rb(t_info *stacks)
{
	ps_rotate(stacks->b_stack);
	write(1, "rb\n", 3);
}

void	rr(t_info *stacks)
{
	ps_rotate(stacks->a_stack);
	ps_rotate(stacks->b_stack);
	write(1, "rr\n", 3);
}

